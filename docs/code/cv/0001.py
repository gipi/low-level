import sys
import cv2

def find_block_size(image):
    '''Search for the minimum distance between change of data.

    One approach is to iterate only the row, and look for the minimum
    block size; otherwise is simpler to divide the size of the image for
    the 29 block expected.
    '''
    minimum = image.shape[0]

    for row in image:
        counter = 0
        last_bit = None
        for pixel in row:
            if last_bit is not None: # this is not the first bit
                if pixel != last_bit:
                    minimum = minimum if counter > minimum else counter
                    counter = 0

            last_bit = pixel
            counter += 1
    reminder = image.shape[0] % minimum
    if reminder != 0:
        raise ValueError('AAHAHAH %d %d' % (minimum, reminder))

    return image.shape[0]/29

    return minimum

def bitify(image, block_size):
    '''transform the image in a simple array with the bits of the single blocks'''
    def _iter_blocks(_image):
        for y in xrange(_image.shape[1]/block_size):
            for x in xrange(_image.shape[0]/block_size):
                # I don't know why the x and y are swapped below
                block = _image[y*block_size:y*block_size + block_size, x*block_size:x*block_size + block_size]

                yield block

    return _iter_blocks(image)


if __name__ == '__main__':
    imagepath = sys.argv[1]

    image = cv2.imread(imagepath)

    image_el = cv2.cvtColor(image, cv2.COLOR_RGB2GRAY)
    ret, thresh1 = cv2.threshold(image_el, 127, 255, cv2.THRESH_BINARY)

    print thresh1
    for row in thresh1:
        for pixel in row:
            output = 'X' if not pixel > 0 else ' '
            sys.stdout.write(output)

        sys.stdout.write('\n')

    cv2.imshow(imagepath, image)
    block_size = find_block_size(thresh1)
    print 'image shape:', image.shape
    print 'block size:', block_size

    bits = [_ for _ in bitify(thresh1, block_size)]
    signs = [' ' if _[0,0] != 0 else 'X'  for _ in bits]

    width = image.shape[0]/block_size

    for _ in xrange(width):
        sign = signs[_*width:_*width+width]
        sys.stdout.write(''.join(sign))
        sys.stdout.write('\n')
    cv2.waitKey(0)
