import numpy as np
import cv2
from global_vars import *

img = cv2.imread("city_img/city-1-randbyme.png",cv2.IMREAD_COLOR)

title1 = 'img'

dst2 = cv2.resize(img, dsize=(0, 0), fx=10.0, fy=10.0, interpolation=cv2.INTER_NEAREST)


cv2.imshow('dst',dst2)


#init
from classes import citizen







while True:
    key = cv2.waitKey(16)
    if key == 27: break

cv2.destroyAllWindows()




"""


"""
















"""
image = np.zeros((200,300),np.uint8)
image.fill(255)
title1, title2 = 'autosize','normal'
cv2.namedWindow(title1,cv2.WINDOW_AUTOSIZE)
cv2.namedWindow(title2,cv2.WINDOW_NORMAL)

cv2.imshow(title1,image)
cv2.imshow(title2,image)
cv2.resizeWindow(title1,400,300)
cv2.resizeWindow(title2,400,300)
cv2.waitKey(0)
cv2.destroyAllWindows()
"""
