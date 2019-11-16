
import pyrealsense2 as rs
import cv2
import numpy as np
import numpy.ma as ma


# pipeline = rs.pipeline()
# pipeline.start()

# class Detector():
#     def __init__(self, img):
        #store image and calc bb and centroid
threshold = 55
img = cv2.imread("candle_1280x720.png")
hsv_flame= cv2.cvtColor(img,cv2.COLOR_BGR2HSV)
# cv2.imshow("img",hsv_flame)

h,s,v = cv2.split(hsv_flame)

flame_mask = ma.masked_where((s > threshold),s)

flame_mask = ma.getmask(flame_mask)
detector_img = np.zeros_like(v)
for i in range (0, img.shape[0]):
        for j in range (0, img.shape[1]):
                if flame_mask [i][j]:
                        detector_img[i][j] = 180
cv2.medianBlur(detector_img, 9)


circles = cv2.HoughCircles(detector_img,cv2.HOUGH_GRADIENT,1,100,
                            param1=50,param2=15,minRadius=0,maxRadius=100)

# circles = np.uint16(np.around(circles))
print circles
for i in circles[0,:]:

    
        # draw the outer circle
        cv2.circle(img,(i[0],i[1]),i[2],(0,255,0),2)
        # draw the center of the circle
        cv2.circle(img,(i[0],i[1]),5,(0,0,255),3)




cv2.imshow("flame mask", detector_img)
cv2.imshow('detected circles',img)
cv2.waitKey(0)
cv2.destroyAllWindows()


    # def get_all(self):


    # def get_vis(self):
        

    # def get_centroid(self):


    # def get_bb(self):