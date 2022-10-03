import tkinter as tk
from tkinter import*
from PIL import Image,ImageTk
from tkinter import messagebox
import cv2
import numpy as np
import serial
from time import sleep
import imutils
import time
from PIL import Image,ImageTk
#from ArduinoPythonIA import camera
from Pruebafinal import camera
print("Librerias Leidas")
#Crear la interfaz
#a=0 
ventana = Tk()
ventana.title("ROBOTICA II")
ventana.geometry('640x480')
#imagen=PhotoImage(file="Roboto2.png")
#imagen=imagen.resize(640,320)
#fondo=Label(ventana,image=imagen).place(x=0,y=0)
canvas=Canvas(ventana,bg="#1b1b1b")
canvas.pack(fill=BOTH,expand=TRUE)

btn_inactive=Image.open("Images/Boton_Camara2.png")
btn_active=Image.open("Images/Boton_Camara1.png")
btn_inactive_Salir=Image.open("Images/Botones_Salir_Python4.png")
btn_active_Salir=Image.open("Images/Botones_Salir_Python3.png")

ventana.btn_inactive=ImageTk.PhotoImage(btn_inactive)
ventana.btn_active=ImageTk.PhotoImage(btn_active)
ventana.btn_inactive_Salir=ImageTk.PhotoImage(btn_inactive_Salir)
ventana.btn_active_Salir=ImageTk.PhotoImage(btn_active_Salir)

def on_enter(event):
    boton1.config(image=ventana.btn_active)

def on_enter2(event):
     boton2.config(image=ventana.btn_active_Salir)

def on_leave(enter):
    boton1.config(image=ventana.btn_inactive)

def on_leave2(enter):
    boton2.config(image=ventana.btn_inactive_Salir)

image = Image.open("Roboto2.png")
image = image.resize((640,480))
img = ImageTk.PhotoImage(image)
fondo=Label(ventana,image=img).place(x=0,y=0)
#Crear los comandos

def mensaje():
    salir = messagebox.askquestion("Salir","¿Desea salir de la interfaz?")
    if salir =='yes':
        ventana.quit()
        ventana.destroy()
#def n_ventana():
 #   global a
  #  a=a+1
   # if a == 1:
    #    ventana = Tk()
     #   ventana.title("ROBOTICA II")
      #  ventana.geometry('640x480')
# Crear botones
boton1 = tk.Button(ventana,image=ventana.btn_inactive,bg="#003b5d",width=150,height=80,bd=0,relief="sunken",activebackground="#003b5d",command=camera)
boton1.place(x=270,y=300)
boton1.bind("<Enter>",on_enter)
boton1.bind("<Leave>",on_leave)
boton2 = tk.Button(ventana,image=ventana.btn_inactive_Salir,bg="#003b5d",width=150,height=80,bd=0,relief="sunken",activebackground="#003b5d",command=mensaje)
boton2.place(x=270,y=370)
boton2.bind("<Enter>",on_enter2)
boton2.bind("<Leave>",on_leave2)
#boton1 = tk.Button(ventana,command=camera(),text='Camara',height=2,width=20)
#boton1.place(x=270,y=350)

ventana.mainloop()
