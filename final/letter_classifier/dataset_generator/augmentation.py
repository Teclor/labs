import cv2
from pathlib import Path
import os
from letter_classifier.dataset_generator import distortion as ds, char_helper as ch
import numpy as np
from letter_classifier.settings import IMAGE_SIZE, DATASET_PATH, FONT_LIST
from letter_classifier.dataset_generator.generator import Generator


class Augmentation:

    def __init__(
            self,
            letter_size_list=None,
            letters_initial_dir=None,
            letters_dataset_dir=None,
            stretch_on_resize=False,
            v_shift_values=range(-2, 3),
            h_shift_values=range(-2, 3),
            rotations=range(-8, 9, 4),
            blur_values=range(0, 8)
    ):
        self.letter_size_list = [48] if letter_size_list is None else letter_size_list
        self.letters_initial_dir = os.path.relpath(DATASET_PATH + '_initial' if letters_initial_dir is None else letters_initial_dir)
        self.letters_dataset_dir = DATASET_PATH if letters_dataset_dir is None else letters_initial_dir
        self.stretch_on_resize = stretch_on_resize
        self.v_shift_values = v_shift_values
        self.h_shift_values = h_shift_values
        self.rotations = rotations
        self.blur_values = blur_values
        self.out_size = IMAGE_SIZE

    def crop_by_extreme_points(self, img):
        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        ret, thresh = cv2.threshold(gray, 220, 255, cv2.THRESH_BINARY)
        img_erode = cv2.erode(thresh, np.ones((3, 3), np.uint8), iterations=1)

        x, y, w, h = self.custom_bounding_rect(img_erode)
        letter_crop = img[y:y + h, x:x + w, :]

        # Resize letter canvas to square
        size_max = max(w, h)
        letter_square = 255 * np.ones(shape=[size_max, size_max, 3], dtype=np.uint8)
        if w > h:
            # Enlarge image top-bottom
            # ------
            # ======
            # ------
            y_pos = size_max // 2 - h // 2
            letter_square[y_pos:y_pos + h, 0:w, :] = letter_crop
        elif w < h:
            # Enlarge image left-right
            # --||--
            x_pos = size_max // 2 - w // 2
            letter_square[0:h, x_pos:x_pos + w, :] = letter_crop
        else:
            letter_square = letter_crop

        # Resize letter to 64x64 and add letter and its X-coordinate
        letter_image = cv2.resize(letter_square, (self.out_size, self.out_size), interpolation=cv2.INTER_AREA)
        return letter_image

    @staticmethod
    def custom_bounding_rect(img):
        # findContours and boundingRect may result in more than 1 symbol in case of "Ы" or ":", etc.
        # so instead of them just find extreme points
        img_h, img_w = img.shape
        x_min = x_max = y_min = y_max = 0
        for i in range(img_h):
            if np.mean(img[i]) != 255.0:
                y_min = i
                break

        for i in range(img_h - 1, y_min, -1):
            if np.mean(img[i]) != 255.0:
                y_max = i - 1
                break

        for i in range(img_w):
            if np.mean(img[:, i]) != 255.0:
                x_min = i
                break

        for i in range(img_w - 1, x_min, -1):
            if np.mean(img[:, i]) != 255.0:
                x_max = i - 1
                break
        x = x_min
        y = y_min
        w = x_max - x_min + 1
        h = y_max - y_min + 1
        return x, y, w, h

    def __len__(self):
        return len(self.v_shift_values) * len(self.h_shift_values) * len(self.rotations) * len(self.blur_values) * len(
            self.letter_size_list) * len(ch.get_chars()) * len(FONT_LIST)

    def execute(self):
        # 5x5x5x8 augmentations = 1000 files by default for 1 size
        total = len(self)

        global_iter = 0
        iter_counter = 0
        letters_initial_path = Path(self.letters_initial_dir)
        if not letters_initial_path.is_dir():
            g = Generator()
            g.generate()

        for required_size in self.letter_size_list:
            for font_dir in os.listdir('{}\\{}'.format(self.letters_initial_dir, required_size)):
                for letter_dir in os.listdir('{}\\{}\\{}'.format(self.letters_initial_dir, required_size, font_dir)):
                    original_image = cv2.imread(
                        '{}\\{}\\{}\\{}\\{}_0000.jpg'.format(self.letters_initial_dir, required_size, font_dir, letter_dir,
                                                             letter_dir))
                    global_iter += iter_counter
                    print("Processing: " + "{:3.2f}".format((global_iter / total) * 100) + "%")
                    iter_counter = 1
                    for v_shift in self.v_shift_values:
                        for h_shift in self.h_shift_values:
                            for axis in self.rotations:
                                for blur in self.blur_values:
                                    image = original_image
                                    if blur != 0:
                                        image = cv2.blur(image, (blur, blur))
                                    if v_shift != 0:
                                        image = ds.vertical_shift(image, v_shift / 100, self.stretch_on_resize)
                                    if h_shift != 0:
                                        image = ds.horizontal_shift(image, h_shift / 100, self.stretch_on_resize)
                                    if axis != 0:
                                        image = ds.rotation(image, axis)

                                    image_cropped = self.crop_by_extreme_points(image)

                                    # --------Path template:-----letters/size/font/letter/letter_iter.jpg------------- #
                                    # Path('{}\\{}\\{}\\{}'.format(self.letters_dataset_dir, required_size, font_dir,
                                    #                              letter_dir)).mkdir(
                                    #     parents=True,
                                    #     exist_ok=True)
                                    # file_name = '{}\\{}\\{}\\{}\\{}_{}.jpg'.format(self.letters_dataset_dir,
                                    #                                                required_size,
                                    #                                                font_dir,
                                    #                                                letter_dir,
                                    #                                                letter_dir,
                                    #                                                str(iter_counter).zfill(4))
                                    # cv2.imwrite(filename=file_name, img=image_cropped)
                                    iter_counter += 1

        print('Augmentation done.')

