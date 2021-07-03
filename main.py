from letter_classifier.settings import Settings
from pathlib import Path
from letter_classifier.dataset_generator.augmentation import Augmentation
from letter_classifier.model import Model
from letter_classifier.loader import DatasetLoader
from letter_classifier.preprocessor import *

if __name__ == "__main__":
    s = Settings()
    s.set('NUM_EPOCHS', 1)
    s.set('BATCH_SIZE', 128)
    letter_pt_size = 48
    aug = Augmentation(letter_size_list=[letter_pt_size])
    cur_aug_path = Path(s.get('DATASET_PATH') + '/' + str(letter_pt_size))

    # -------Execute augmentation if dataset dir doesn't exist-----------------#
    if not cur_aug_path.is_dir():
        aug.execute()

    dl = DatasetLoader()
    ds = dl.load_multiclass()
    print('Dataset loaded')

    model_feedforward = Model()
    model_convolutional = Model()
    # model_feedforward.feedforward_multiclass()
    # model_convolutional.convolutional_multiclass()

    model_feedforward.load('feedforward_multiclass')

    model_convolutional.load('convolutional_multiclass')

    s_out, predicted_fonts = img_to_str(model_convolutional.get_model(), "img.png")
    print('Predicted fonts')
    print(predicted_fonts)
    print(s_out)
