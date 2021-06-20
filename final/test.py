from dataset_generator import distortion as au
import cv2


orig = cv2.imread('big-sha_0000.jpg')

# 20 shifts
img = au.vertical_shift(orig, 0.10)
cv2.imshow('vertical_flip', img)
cv2.waitKey(0)

# 20 shifts
img = au.horizontal_shift(orig, 0.10)
cv2.imshow('horizontal_flip', img)
cv2.waitKey(0)

# 50 rotations
img = au.rotation(orig, -25)
cv2.imshow('horizontal_flip', img)
cv2.waitKey(0)

# 10 blurs
img = cv2.blur(orig, (10, 10))
cv2.imshow('horizontal_flip', img)
cv2.waitKey(0)


cv2.destroyAllWindows()