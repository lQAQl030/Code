import numpy as np
import cv2
import pathlib

def translate(img, x, y):
    height, width = img.shape[:2]
    M = np.float32([[1, 0, x], [0, 1, y]])
    shifted = cv2.warpAffine(img, M, (width, height))
    return shifted

def rotate(img, angle):
    height, width = img.shape[:2]
    M = cv2.getRotationMatrix2D((width / 2, height / 2), angle, 1)
    rotated = cv2.warpAffine(img, M, (width, height))
    return rotated

def flip(img, direction):
    flipped = cv2.flip(img, direction)
    return flipped

def scale(img, ratio):
    height, width = img.shape[:2]
    x = int(width * ratio)
    y = int(height * ratio)
    scaled = cv2.resize(img, (x, y), interpolation=cv2.INTER_AREA)
    return scaled

def crop(img, x, y, w, h):
    height, width = img.shape[:2]
    if y+h > height or x+w > width:
        return img
    cropped = img[y:y+h, x:x+w]
    return cropped



def main():
    img_path = pathlib.Path(__file__).parent / 'image.png'
    translation_path = pathlib.Path(__file__).parent / 'translation.png'
    rotation_path = pathlib.Path(__file__).parent / 'rotation.png'
    flipping_path = pathlib.Path(__file__).parent / 'flipping.png'
    scaling_path = pathlib.Path(__file__).parent / 'scaling.png'
    cropping_path = pathlib.Path(__file__).parent / 'cropping.png'

    img = cv2.imread(str(img_path))

    translation = np.hstack((img, translate(img, 400, 300)))
    cv2.imwrite(str(translation_path), translation)

    rotation = np.hstack((img, rotate(img, 45)))
    cv2.imwrite(str(rotation_path), rotation)

    flipping = np.hstack((img, flip(img, 0)))
    cv2.imwrite(str(flipping_path), flipping)

    scaling = scale(img, 0.5)
    cv2.imwrite(str(scaling_path), scaling)

    cropping = crop(img, 1073, 600, 107, 126)
    cv2.imwrite(str(cropping_path), cropping)



    

if __name__ == '__main__':
    main()
