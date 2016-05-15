import sys
import cv2


if __name__ == '__main__':
    imagepath = sys.argv[1]

    image = cv2.imread(imagepath)

    cv2.imshow(imagepath, image)
    cv2.waitKey(0)
