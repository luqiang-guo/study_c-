import  numpy as np
import cv2  


img = np.loadtxt('Input_1_tensor.dec').reshape([224,224,3]).astype(np.float32)

img = img * 255
print(img)

# img1 = np.save("image.jpg", img)
# print('________________________')
# print(img1)

cv2.imwrite("image.jpg", img)  