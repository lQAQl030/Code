import cv2
import pathlib

def main():
    file_path = pathlib.Path(__file__).parent / 'bounding_box.txt'
    img_path = pathlib.Path(__file__).parent / 'image.png'
    output_path = pathlib.Path(__file__).parent / 'hw0_110704010_1.png'

    box = open(file_path, 'r')
    img = cv2.imread(str(img_path))
    
    for line in box:
        cd = line.split()
        first_point = (int(cd[0]), int(cd[1]))
        second_point = (int(cd[2]), int(cd[3]))
        cv2.rectangle(img, first_point, second_point, (0, 0, 255), 2)
    cv2.imwrite(str(output_path), img)

if __name__ == '__main__':
    main()