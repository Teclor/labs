from letter_classifier.settings import Settings
import pandas as pd
import numpy as np
import letter_classifier.dataset_generator.char_helper as ch
import os
import cv2
from pathlib import Path


class DatasetLoader:

    def __init__(self, dataset_path=None):
        self.settings = Settings()
        self.dataset_path = self.settings.get('DATASET_PATH') if dataset_path is None else dataset_path
        self.dataset = pd.DataFrame({})
        self.mode = ''

    def load_multiclass(self, size_pt=48):
        self.mode = 'multiclass'
        file = self.settings.get('DATASET_PATH') + '/{}/ds_{}.pkl'.format(size_pt, self.mode)
        if not Path(file).is_file():
            self._get_multiclass()
        else:
            self.dataset = pd.read_pickle(file)
        return self.dataset.iloc[0]

    def save(self, file_name=None):
        file = self.settings.get('DATASET_PATH') + '/ds_' + self.mode + '.pkl' if file_name is None else file_name + '.pkl'
        self.dataset.to_pickle(file)

    def _get_multiclass(self, size_pt=48):
        self.mode = 'multiclass'
        dataset_path = self.dataset_path + '/' + str(size_pt)

        dataset = {'data': np.ndarray(shape=(3*89000, 64, 64, 1)), 'target': np.ndarray(shape=(3*89000, 2), dtype=object)}
        char_indexes = ch.get_char_indexes()
        file_names_to_chars = ch.get_file_names_to_chars()
        font_indices = {'Arial': 89, 'Calibri': 90, 'Times New Roman': 91}

        iter_count = 0
        for font_directory in os.listdir(dataset_path):
            font = font_directory
            font_full_path = dataset_path + '/' + font_directory
            for letter_directory in os.listdir(font_full_path):
                letter_label = letter_directory
                list_files = os.listdir('{}\\{}'.format(font_full_path, letter_directory))
                for file in list_files:
                    image = cv2.imread('{}\\{}\\{}'.format(font_full_path, letter_directory, file))
                    image_gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
                    dataset['data'][iter_count] = np.reshape((image_gray.astype('float32') / 255.0), newshape=(64, 64, 1))
                    dataset['target'][iter_count][0] = char_indexes[file_names_to_chars[letter_label]]
                    dataset['target'][iter_count][1] = font_indices[font]
                    iter_count += 1
                print('Preprocessing progress {:3.2f}%'.format((iter_count/(3*89*1000))*100), [font, letter_label])
        df = pd.DataFrame([dataset])
        self.dataset = df
        self.save()
        return self.dataset
