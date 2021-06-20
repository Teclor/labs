import cv2
from pathlib import Path
import os
from dataset_generator import char_helper as ch
from dataset_generator import distortion as ds

dir_to_letter_map = ch.file_names_to_chars()
letters_initial_dir = 'letters_initial'
letters_dataset_dir = 'letters'

skip_initial_values = False  # whether to skip or not values that don't influence on picture

total = 1000 * 89 * 3 if skip_initial_values else 1210 * 89 * 3  # всего циклов
global_iter = 0
iter_counter = 1


required_size = 48  # required font size in points, must be in letters_initial as a folder

for font_dir in os.listdir('{}\\{}'.format(letters_initial_dir, required_size)):
    for letter_dir in os.listdir('{}\\{}\\{}'.format(letters_initial_dir, required_size, font_dir)):
        original_image = cv2.imread(
            '{}\\{}\\{}\\{}\\{}_0000.jpg'.format(letters_initial_dir, required_size, font_dir, letter_dir, letter_dir))
        global_iter += iter_counter
        print("Processing: " + "{:3.2f}".format((global_iter/total)*100) + "%")
        iter_counter = 1
        # ---------10x10x5x2=1000 if skip 0 values---------------------------------------------------------------------#
        # ---------10 or 11 vertical shifts----------------------------------------------------------------------------#
        for v_shift in range(-10, 12, 2):
            if skip_initial_values and v_shift == 0:  # skip initial value
                continue
            # -----10 horizontal shifts--------------------------------------------------------------------------------#
            for h_shift in range(-10, 12, 2):
                if skip_initial_values and h_shift == 0:  # skip initial value
                    continue
                # -------5 rotations-----------------------------------------------------------------------------------#
                for axis in range(-20, 21, 10):
                    # ---2 blur kernels--------------------------------------------------------------------------------#
                    for blur in [5, 10]:
                        image = cv2.blur(original_image, (blur, blur))
                        image = ds.vertical_shift(image, v_shift / 100)
                        image = ds.horizontal_shift(image, h_shift / 100)
                        if axis != 0:
                            image = ds.rotation(image, axis)

                        # ------------------------------------letters/size/font/letter/letter_iter.jpg---------------- #
                        Path('{}\\{}\\{}\\{}'.format(letters_dataset_dir, required_size, font_dir, letter_dir)).mkdir(
                            parents=True,
                            exist_ok=True)
                        file_name = '{}\\{}\\{}\\{}\\{}_{}.jpg'.format(letters_dataset_dir,
                                                                       required_size,
                                                                       font_dir,
                                                                       letter_dir,
                                                                       letter_dir,
                                                                       str(iter_counter).zfill(4))
                        cv2.imwrite(filename=file_name, img=image)
                        iter_counter += 1
