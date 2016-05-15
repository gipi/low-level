import sys
import cv2


if __name__ == '__main__':
    imagepath = sys.argv[1]

    image = cv2.imread(imagepath)

    image_el = cv2.cvtColor(image, cv2.COLOR_RGB2GRAY)
    ret, thresh1 = cv2.threshold(image_el, 127, 255, cv2.THRESH_BINARY)

    print thresh1
    for row in thresh1:
        for pixel in row:
            output = 'x' if not pixel > 0 else ' '
            sys.stdout.write(output)

        sys.stdout.write('\n')

    cv2.imshow(imagepath, image)
    cv2.waitKey(0)
