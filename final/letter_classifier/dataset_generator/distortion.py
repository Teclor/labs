import cv2
import random
import numpy as np


def fill(img, h, w):
    img = cv2.resize(img, (h, w), cv2.INTER_CUBIC)
    return img


def check_gray_image_bounds_are_white(img, h, w, debug_print=False):
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    ret, thresh = cv2.threshold(gray, 220, 255, cv2.THRESH_BINARY)
    img_erode = cv2.erode(thresh, np.ones((3, 3), np.uint8), iterations=1)

    bounds_are_white = np.mean([np.mean(img_erode[0]), np.mean(img_erode[h-1]), np.mean(img_erode[:, 0]), np.mean(img_erode[:, w-1])]) == 255.0
    if not bounds_are_white and debug_print:
        print('Object on image has been moved out of the bounds image bounds after augmentation.')
    return bounds_are_white


def horizontal_shift(img_initial, ratio=0.0, stretch=False):
    if ratio > 1 or ratio < -1:
        print('Value should be less than 1 and greater than -1')
        return img_initial
    img = img_initial.copy()
    # ratio = random.uniform(-ratio, ratio)
    h, w = img.shape[:2]
    to_shift = w * ratio
    if ratio > 0:
        move = int(w - to_shift)
        img = img[:, :move, :]
        if not stretch:
            to_append = np.full((img.shape[0], img.shape[0] - move, img.shape[2]), 255, dtype=np.uint8)
            img = np.column_stack((to_append, img))
    if ratio < 0:
        move = int(-1 * to_shift)
        img = img[:, move:, :]
        if not stretch:
            to_append = np.full((img.shape[0], move, img.shape[2]), 255, dtype=np.uint8)
            img = np.column_stack((img, to_append))

    # check that we didn't move object out of the bound or on the bound of image
    if not check_gray_image_bounds_are_white(img, h, w, True):
        return img_initial
    if stretch:
        img = fill(img, h, w)
    return img


def vertical_shift(img_initial, ratio=0.0, stretch=False):
    if ratio > 1 or ratio < -1:
        print('Value should be less than 1 and greater than -1')
        return img_initial
    img = img_initial.copy()
    # ratio = random.uniform(-ratio, ratio)
    h, w = img.shape[:2]
    to_shift = h * ratio
    if ratio > 0:
        move = int(h - to_shift)
        img = img_initial[:move, :, :]
        if not stretch:
            to_append = np.full((img.shape[1] - move, img.shape[1], img.shape[2]), 255, dtype=np.uint8)
            img = np.concatenate((to_append, img))
    if ratio < 0:
        move = int(-1 * to_shift)
        img = img_initial[move:, :, :]
        if not stretch:
            to_append = np.full((move, img.shape[1], img.shape[2]), 255, dtype=np.uint8)
            img = np.concatenate((img, to_append))

    # check that we didn't move object out of the bound or on the bound of image
    if not check_gray_image_bounds_are_white(img, h, w, True):
        return img_initial
    if stretch:
        img = fill(img, h, w)
    return img


def brightness(img, low, high):
    value = random.uniform(low, high)
    hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
    hsv = np.array(hsv, dtype=np.float64)
    hsv[:, :, 1] = hsv[:, :, 1] * value
    hsv[:, :, 1][hsv[:, :, 1] > 255] = 255
    hsv[:, :, 2] = hsv[:, :, 2] * value
    hsv[:, :, 2][hsv[:, :, 2] > 255] = 255
    hsv = np.array(hsv, dtype=np.uint8)
    img = cv2.cvtColor(hsv, cv2.COLOR_HSV2BGR)
    return img


def zoom(img, value):
    if value > 1 or value < 0:
        print('Value for zoom should be less than 1 and greater than 0')
        return img
    value = random.uniform(value, 1)
    h, w = img.shape[:2]
    h_taken = int(value * h)
    w_taken = int(value * w)
    h_start = random.randint(0, h - h_taken)
    w_start = random.randint(0, w - w_taken)
    img = img[h_start:h_start + h_taken, w_start:w_start + w_taken, :]
    img = fill(img, h, w)
    return img


def channel_shift(img, value):
    value = int(random.uniform(-value, value))
    img = img + value
    img[:, :, :][img[:, :, :] > 255] = 255
    img[:, :, :][img[:, :, :] < 0] = 0
    img = img.astype(np.uint8)
    return img


def horizontal_flip(img, flag):
    if flag:
        return cv2.flip(img, 1)
    else:
        return img


def vertical_flip(img, flag):
    if flag:
        return cv2.flip(img, 0)
    else:
        return img


def rotation(img_initial, angle):
    img = img_initial.copy()

    # angle = int(random.uniform(-angle, angle))
    h, w = img.shape[:2]
    M = cv2.getRotationMatrix2D((int(w / 2), int(h / 2)), angle, 1)
    img = cv2.warpAffine(img, M, (w, h), borderMode=cv2.BORDER_CONSTANT, borderValue=(255,255,255))

    # check that we didn't move object out of the bound or on the bound of image
    if not check_gray_image_bounds_are_white(img, h, w, True):
        return img_initial
    return img
