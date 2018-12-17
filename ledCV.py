import numpy as np
import cv2
import serial

ardu = serial.Serial('COM4')
camera = cv2.VideoCapture(0)

while True:
    (grabbed, frame) = camera.read()

    frame = cv2.flip(frame, 1) #aynalama
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV) #rgb->hsv

    kernel = np.ones((9, 9), np.uint8)
    filtre = cv2.inRange(hsv, (97, 100, 117), (117,255,255)) #renk filtesi
    filtre = cv2.morphologyEx(filtre, cv2.MORPH_OPEN, kernel) #opening


    cnts = cv2.findContours(filtre.copy(), cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)[-2]
    center = None
    if len(cnts) > 0:
        c = max(cnts, key=cv2.contourArea)
        ((x, y), radius) = cv2.minEnclosingCircle(c)
        M = cv2.moments(c)
        center = (int(M["m10"] / M["m00"]), int(M["m01"] / M["m00"]))
        if radius > 0.5:
            cv2.circle(frame, (int(x), int(y)), int(radius), (0,0,255), 2)
        if y<138 and x<210:
            ardu.write(b'1')
        elif y<138 and x>=210 and x<420:
            ardu.write(b'2')
        elif y<138 and x>=420:
            ardu.write(b'3')
        elif y>=138 and y<276 and x<210:
            ardu.write(b'4')
        elif y>=138 and y<276 and x>=210 and x<420:
            ardu.write(b'5')
        elif y>=138 and y<276 and x>=420:
            ardu.write(b'6')
        elif y>=210 and x<210:
            ardu.write(b'7')
        elif y>=210 and x>=210 and x<420:
            ardu.write(b'8')
        elif y>=210 and x>=420:
            ardu.write(b'9')
    else:
        ardu.write(b'0')
    cv2.imshow("Frame", frame)

    key = cv2.waitKey(1) & 0xFF
    if key == ord("q"):
        break

camera.release()
cv2.destroyAllWindows()