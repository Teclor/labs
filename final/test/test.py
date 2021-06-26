# import the necessary packages
from sklearn.preprocessing import LabelBinarizer
from sklearn.model_selection import train_test_split
from sklearn.metrics import classification_report
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense
from tensorflow.keras.optimizers import SGD
import tensorflow as tf
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import letter_classifier.dataset_generator.char_helper as ch


# dataset_path = '../dataset_generator/letters/48/Arial'
# dataset = {'data': {}, 'target': {}}
# iter_count = 0
# for directory in os.listdir(dataset_path):
#     target_label = directory
#     list_files = os.listdir('{}\\{}'.format(dataset_path, directory))
#     for file in list_files:
#         image = cv2.imread('{}\\{}\\{}'.format(dataset_path, directory, file))
#         image_gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
#         dataset['data'][iter_count] = np.concatenate(image_gray).astype('float32') / 255.0
#         dataset['target'][iter_count] = target_label
#         iter_count += 1
#     print('Progress {:3.2f}%'.format((iter_count/(89*1000))*100), target_label)
#
# df = pd.DataFrame(dataset)
# df.to_pickle('test_dataframe_1.pkl')


file_names_to_chars = ch.get_file_names_to_chars()
char_indexes = ch.get_char_indexes()

df = pd.read_pickle('test_dataframe_1.pkl')
dataset = df.sample(frac=1).reset_index(drop=True)

data = dataset.data
(trainX, testX, trainY, testY) = train_test_split(data, dataset.target, test_size=0.25)
trainY = {key: char_indexes[file_names_to_chars[value]] for key, value in trainY.items()}
testY = {key: char_indexes[file_names_to_chars[value]] for key, value in testY.items()}
trainX = tf.convert_to_tensor(trainX.tolist())
testX = tf.convert_to_tensor(testX.tolist())

# convert the labels from integers to vectors
lb = LabelBinarizer()
trainY = lb.fit_transform(list(trainY.values()))
testY = lb.transform(list(testY.values()))

# define the 784-256-128-10 architecture using Keras
model = Sequential()
model.add(Dense(256, input_shape=(4096,), activation="sigmoid"))
model.add(Dense(128, activation="sigmoid"))
model.add(Dense(89, activation="softmax"))
# train the model using SGD
print("[INFO] training network...")
sgd = SGD(0.01)
model.compile(loss="categorical_crossentropy", optimizer=sgd, metrics=["accuracy"])
H = model.fit(trainX, trainY, validation_data=(testX, testY), epochs=50, batch_size=4096)

# evaluate the network
print("[INFO] evaluating network...")
predictions = model.predict(testX, batch_size=1024)
print(classification_report(testY.argmax(axis=1), predictions.argmax(axis=1), target_names=[str(x) for x in lb.classes_]))

model.save('test_model_1.h5')
# plot the training loss and accuracy
plt.style.use("ggplot")
plt.figure()
plt.plot(np.arange(0, 50), H.history["loss"], label="train_loss")
plt.plot(np.arange(0, 50), H.history["val_loss"], label="val_loss")
plt.plot(np.arange(0, 50), H.history["accuracy"], label="train_acc")
plt.plot(np.arange(0, 50), H.history["val_accuracy"], label="val_acc")
plt.title("Training Loss and Accuracy")
plt.xlabel("Epoch #")
plt.ylabel("Loss/Accuracy")
plt.legend()
plt.savefig('output/fig_1.png')