import cv2
import numpy as np
from typing import *
import letter_classifier.dataset_generator.char_helper as ch


def img_to_str(model: Any, image_file: str):
    font_list_preidcted = []
    letters = letters_extract(image_file)
    s_out = ""
    for i in range(len(letters)):
        dn = letters[i+1][0] - letters[i][0] - letters[i][1] if i < len(letters) - 1 else 0
        l, f = predict_image(model, letters[i][2])
        font_list_preidcted.append(f)
        s_out += l
        if (dn > letters[i][1]/4):
            s_out += ' '
    return s_out, font_list_preidcted


def letters_extract(image_file: str, out_size=64):
    img = cv2.imread(image_file)
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    ret, thresh = cv2.threshold(gray, 127, 255, cv2.THRESH_BINARY)
    img_erode = cv2.erode(thresh, np.ones((3, 3), np.uint8), iterations=1)

    # Get contours
    contours, hierarchy = cv2.findContours(img_erode, cv2.RETR_TREE, cv2.CHAIN_APPROX_NONE)

    output = img.copy()

    letters = []
    for idx, contour in enumerate(contours):
        (x, y, w, h) = cv2.boundingRect(contour)
        # print("R", idx, x, y, w, h, cv2.contourArea(contour), hierarchy[0][idx])
        # hierarchy[i][0]: the index of the next contour of the same level
        # hierarchy[i][1]: the index of the previous contour of the same level
        # hierarchy[i][2]: the index of the first child
        # hierarchy[i][3]: the index of the parent
        if hierarchy[0][idx][3] == 0:
            cv2.rectangle(output, (x, y), (x + w, y + h), (70, 0, 0), 1)
            letter_crop = gray[y:y + h, x:x + w]
            # print(letter_crop.shape)

            # Resize letter canvas to square
            size_max = max(w, h)
            letter_square = 255 * np.ones(shape=[size_max, size_max], dtype=np.uint8)
            if w > h:
                # Enlarge image top-bottom
                # ------
                # ======
                # ------
                y_pos = size_max//2 - h//2
                letter_square[y_pos:y_pos + h, 0:w] = letter_crop
            elif w < h:
                # Enlarge image left-right
                # --||--
                x_pos = size_max//2 - w//2
                letter_square[0:h, x_pos:x_pos + w] = letter_crop
            else:
                letter_square = letter_crop

            letters.append((x, w, cv2.resize(letter_square, (out_size, out_size), interpolation=cv2.INTER_AREA)))

    # Sort array in place by X-coordinate
    letters.sort(key=lambda x: x[0], reverse=False)

    # cv2.imshow("Input", img)

    # cv2.imshow("Gray", thresh)
    # cv2.imshow("Enlarged", img_erode)
    # cv2.imshow("Output", output)

    # cv2.imshow("0", letters[0][2])
    # cv2.imshow("1", letters[1][2])
    # cv2.imshow("2", letters[2][2])
    # cv2.imshow("3", letters[3][2])
    # cv2.imshow("4", letters[4][2])
    cv2.waitKey(0)
    return letters


def predict_image(model, img):
    img_arr = np.expand_dims(img, axis=0)
    img_arr = img_arr.astype('float32')
    img_arr = img_arr/255.0
    img_arr = img_arr.reshape((1, 64, 64, 1))

    result = model.predict([img_arr])
    converted = (result[0][:88].argmax(), result[0][89:92].argmax())
    letter = ch.get_chars()[converted[0]]
    fonts = {0: 'Arial', 1: 'Calibri', 2: 'Times New Roman'}
    font = fonts[converted[1]]
    return letter, font
