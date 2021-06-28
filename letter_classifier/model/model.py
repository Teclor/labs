# import the necessary packages
from sklearn.preprocessing import MultiLabelBinarizer
from sklearn.model_selection import train_test_split
from sklearn.metrics import classification_report
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense
from tensorflow.keras.optimizers import SGD
from tensorflow.keras.optimizers import Adam
import tensorflow as tf
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import letter_classifier.dataset_generator.char_helper as ch
from tensorflow.keras.layers import Conv2D
from tensorflow.keras.layers import MaxPooling2D
from tensorflow.keras.layers import BatchNormalization
from tensorflow.keras.layers import Dropout
from tensorflow.keras.layers import Activation
from tensorflow.keras.layers import Flatten
from tensorflow.keras.losses import BinaryCrossentropy
from tensorflow.keras.metrics import BinaryAccuracy
import cv2
import os
from letter_classifier.settings import Settings
from letter_classifier.model.terminate_on_base_line import TerminateOnBaseline
from sklearn.metrics import accuracy_score
from tensorflow.keras.models import load_model
from pathlib import Path


class Model:

    def __init__(self, dataset=None):
        self.dataset = dataset
        self.model = Sequential()
        self.settings = Settings()
        self.model_type = ''
        self.available_names = ['convolutional', 'feedforward', 'convolutional_multiclass', 'feedforward_multiclass']
        self.plot_loss = ''
        self.plot_metric = ''
        self.dataset = dataset
        self.class_count = len(ch.get_chars()) + len(self.settings.get('FONT_LIST'))

    def load(self, model_name):
        if model_name in self.available_names:
            if Path(model_name + '.h5').is_file():
                self.model = load_model(model_name + '.h5')
            else:
                getattr(self, model_name)()
                self.execute()

    def convolutional_multiclass(self):
        self.plot_loss = 'binary_crossentropy'
        self.plot_metric= 'binary_accuracy'
        self.model_type = 'convolutional_multiclass'
        self.model.add(
            Conv2D(48, (5, 5), padding="same",
                   input_shape=(self.settings.get('IMAGE_SIZE'), self.settings.get('IMAGE_SIZE'), 1)))
        self.model.add(Activation("relu"))
        self.model.add(MaxPooling2D(pool_size=(2, 2), strides=(2, 2)))
        self.model.add(Conv2D(96, (5, 5), padding="same"))
        self.model.add(Activation("relu"))
        self.model.add(MaxPooling2D(pool_size=(2, 2), strides=(2, 2)))
        self.model.add(Flatten())
        self.model.add(Dense(1024))
        self.model.add(Activation("relu"))
        self.model.add(Dense(self.class_count))
        self.model.add(Activation("sigmoid"))
        opt = Adam()
        self.model.compile(loss=BinaryCrossentropy(), optimizer=opt, metrics=[BinaryAccuracy()])
        return self.model

    def feedforward_multiclass(self):
        self.plot_loss = 'binary_crossentropy'
        self.plot_metric = 'binary_accuracy'
        self.model_type = 'feedforward_multiclass'
        self.model.add(Dense(256, input_shape=(self.settings.get('IMAGE_SIZE'), self.settings.get('IMAGE_SIZE'), 1), activation="elu"))
        self.model.add(Dense(128, activation="elu"))
        self.model.add(Flatten())
        self.model.add(Dense(self.class_count, activation="sigmoid"))
        opt = Adam()
        self.model.compile(loss=BinaryCrossentropy(), optimizer=opt, metrics=[BinaryAccuracy()])
        return self.model

    def execute(self, dataset=None):
        if dataset is not None:
            self.dataset = dataset

        target = self.dataset.target
        mlb = MultiLabelBinarizer()
        mlb.fit(target)
        target = mlb.transform(target)

        (x_train, x_validate_test, y_train, y_validate_test) = train_test_split(self.dataset.data, target, train_size=0.6)
        # ------split into validation and test set -------#
        (x_validation, x_test, y_validation, y_test) = train_test_split(x_validate_test, y_validate_test, train_size=0.75)

        # ----------learn---------#
        batch_size = self.settings.get('BATCH_SIZE')
        num_epochs = self.settings.get('NUM_EPOCHS')

        callbacks = [TerminateOnBaseline(monitor='binary_accuracy', baseline=1.0)]
        history = self.model.fit(x_train, y_train,
                                 validation_data=(x_validation, y_validation),
                                 epochs=num_epochs, batch_size=batch_size,
                                 verbose=1, steps_per_epoch=len(x_train) // batch_size,
                                 # callbacks=callbacks
                                 )

        predictions = self.model.predict(x_test, batch_size=batch_size)
        print('Prediction accuracy: ')
        print(accuracy_score(y_test, predictions.round()))
        self.model.save(self.model_type + '.h5')
        self.save_plot(history, self.plot_loss, self.plot_metric)

    def convolutional(self):
        self.plot_loss = 'loss'
        self.plot_metric= 'accuracy'
        self.model_type = 'convolutional'
        self.model.add(Conv2D(48, (5, 5), padding="same", input_shape=(64, 64, 1)))
        self.model.add(Activation("elu"))
        self.model.add(MaxPooling2D(pool_size=(2, 2), strides=(2, 2)))
        self.model.add(Conv2D(122, (5, 5), padding="same"))
        self.model.add(Activation("elu"))
        self.model.add(MaxPooling2D(pool_size=(2, 2), strides=(2, 2)))
        self.model.add(Flatten())
        self.model.add(Dense(1024))
        self.model.add(Activation("elu"))
        self.model.add(Dense(self.class_count))
        self.model.add(Activation("softmax"))
        sgd = SGD(learning_rate=0.01)
        self.model.compile(loss="categorical_crossentropy", optimizer=sgd, metrics=["accuracy"])
        pass

    def feedforward(self):
        self.plot_loss = 'loss'
        self.plot_metric= 'accuracy'
        self.model_type = 'feedforward'
        self.model.add(Dense(2048, input_shape=(4096,), activation="elu"))
        self.model.add(Dense(1024, activation="elu"))
        self.model.add(Dense(512, activation="elu"))
        self.model.add(Dense(256, activation="elu"))
        self.model.add(Dense(128, activation="elu"))
        self.model.add(Dense(self.class_count, activation="softmax"))
        sgd = SGD(0.01)
        self.model.compile(loss="categorical_crossentropy", optimizer=sgd, metrics=["accuracy"])
        return self.model

    def save_plot(self, history, filename, loss='binary_crossentropy', metric='binary_accuracy'):
        # plot the training loss and accuracy
        plt.style.use("ggplot")
        plt.figure()
        plt.plot(np.arange(0, 1), history.history[loss], label="train_loss")
        plt.plot(np.arange(0, 1), history.history["val_" + loss], label="val_loss")
        plt.plot(np.arange(0, 1), history.history[metric], label="train_acc")
        plt.plot(np.arange(0, 1), history.history["val_" + metric], label="val_acc")
        plt.title("Training Loss and Accuracy")
        plt.xlabel("Epoch #")
        plt.ylabel("Loss/Accuracy")
        plt.legend()
        plt.savefig('output/{}.png'.format(filename))

    def get_model(self):
        return self.model