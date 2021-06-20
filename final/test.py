import augmentation as au
import cv2
import os


img = cv2.imread('sha_0000.jpg')
cv2.imshow('Result', img)
cv2.waitKey(0)
print(img.shape)
img = au.vertical_flip(img, True)
print(img)
cv2.imshow('Result', img)
cv2.waitKey(0)
cv2.destroyAllWindows()