import numpy as np
import cv2
import pathlib

def main():
    vid_path = pathlib.Path(__file__).parent / 'video.mp4'
    output_path = pathlib.Path(__file__).parent / 'hw0_110704010_2.png'

    vid = cv2.VideoCapture(str(vid_path))
    ret, frame1 = vid.read()
    while ret:
        ret, frame2 = vid.read()

        # Note: The size is too big for my pc to display (>-<)
        # frame1 = cv2.resize(frame1, (1280, 720), interpolation=cv2.INTER_AREA)
        # frame2 = cv2.resize(frame2, (1280, 720), interpolation=cv2.INTER_AREA)

        if ret:
            gray_frame1 = cv2.cvtColor(frame1, cv2.COLOR_BGR2GRAY)
            gray_frame2 = cv2.cvtColor(frame2, cv2.COLOR_BGR2GRAY)
            
            frame_diff = cv2.absdiff(gray_frame1, gray_frame2)
            mask = cv2.threshold(frame_diff, 35, 255, cv2.THRESH_BINARY)[1]
            colored_frame = cv2.cvtColor(mask, cv2.COLOR_GRAY2BGR)
            colored_frame[mask > 0] = (0, 255, 0)

            combine_frame = np.hstack((frame2, colored_frame))

            cv2.imshow('frame', combine_frame)

            frame1 = frame2
            
            key = cv2.waitKey(1)
            if key == ord('c'):
                cv2.imwrite(str(output_path), combine_frame)
            if key == ord('q'):
                break
        else:
            break
    vid.release()
    cv2.destroyAllWindows()

    

if __name__ == '__main__':
    main()