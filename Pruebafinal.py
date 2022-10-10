from pickle import TRUE
import cv2
import numpy as np
import serial
from time import sleep
from threading import Timer
import imutils
import time


def counter():
    start = time.perf_counter()
    return start

#TIMER = int(5)
#def temps():
 #   while True:
  #      prev = time.time()
    
   #     while TIMER >= 0:
        # current time
    #        cur = time.time()
     #       if cur-prev >= 1:
      #          prev = cur
       #         TIMER = TIMER-1
#print("holaaa")

def camera():
    COM = 'COM4'
    BAUD = 9600
    detecto = False
    ser = serial.Serial(COM, BAUD)
 
    cap = cv2.VideoCapture(1)
    fps_start_time=0
    fps=0
    #RANGO DE COLORES 
    azulBajo = np.array([90, 100, 20], np.uint8)
    azulAlto = np.array([120, 255, 255], np.uint8)

    rojoBajo = np.array([136,87,111], np.uint8)
    rojoAlto = np.array([180,255,255], np.uint8)

    verdeBajo = np.array([25,52,72], np.uint8)
    verdeAlto = np.array([102,255,255], np.uint8)
    #start = time.perf_counter()
    elapsed = 0
    #detectando= False
    while True:
        ret, frame = cap.read()
       # if detectando == False:
           # print("no detectado")
        if ret:
            #fps_end_time= time.time()
            #time_diff=fps_end_time - fps_start_time
            #fps= 1/(time_diff)
            #fps_start_time = fps_end_time

            #fps_text = "FPS: {:.2f}".format(fps)
            #cv2.putText(frame,fps_text,(5,30), cv2.FONT_HERSHEY_COMPLEX,1, (0,255,255),1)
        
            frame = cv2.flip(frame, 1)
            frameHSV = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
            mascara = cv2.inRange(frameHSV, azulBajo, azulAlto)
            contornos, _ = cv2.findContours(mascara, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
            cv2.drawContours(frame, contornos, -1, (255, 0, 0), 4)
            
            
            for c in contornos:
                area = cv2.contourArea(c)
                #print("objeto encontrado") 
                if area > 5000:
                    M = cv2.moments(c)
                    if M["m00"] == 0:
                        M["m00"] = 1
                    x = int(M["m10"] / M["m00"])
                    y = int(M['m01'] / M['m00'])
                    cv2.circle(frame, (x, y), 7, (0, 0, 255), -1)
                    font = cv2.FONT_HERSHEY_SIMPLEX
                    cv2.putText(frame, '{},{}'.format(x, y), (x + 10, y), font, 1.2, (0, 0, 255), 2, cv2.LINE_AA)
                    nuevoContorno = cv2.convexHull(c)
                    cv2.drawContours(frame, [nuevoContorno], 0, (255, 0, 0), 3)
                    #detectando=True
                    detecto =True
                    #print("Blue Color")
                    elapsed = (time.perf_counter() - start)
                    print(elapsed)
                    #if elapsed >= 5:
                     #   print("MOTION")
                      #  start = time.perf_counter() #Reincia el cronometro
                      #  x = x / 4 # divide en 4 ya que la resolucion es de 640 x 320
                        #print(x);
                      #  cad = str(x) + "," + str("movobj\n") # se guarda en una string el valor de x y el movimiento predeterminado
                     #   ser.write(cad.encode('ascii')) #enviar el string al arduino
                     #   sleep(10) #duerme 10 segundos :v
                    #x = x / 180
                    #print(x)
                    cad = str(x)+","+str(y)+",\n"
                    #print(cad)
                    ser.write(cad.encode('ascii'))
                
            if detecto == False:
                print("NO DETECTA NINGUN OBJETO")
                start = time.perf_counter() #reinicia el contador hasta que encuentre un objeto
            
            # cv2.imshow('mascaraAzul', mascara)
            cv2.imshow('frame', frame)
            if cv2.waitKey(1) & 0xFF == ord('s'):
                print('FIN')
                ser.close()
                break
        detecto =False        
    cap.release()
    cv2.destroyAllWindows()
