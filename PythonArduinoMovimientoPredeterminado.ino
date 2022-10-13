#include <Servo.h>

//#define SER 3 //Pin para el servo
 
Servo servo1; //Objeto servo base
Servo servo2; // codo derecho  CODO DERECHO MAXIMO ADELANTE 130, ATRAS 40 MINIMO
Servo servo3; //codo izquierdo CODO IZQUIERDO 160 MAXIMO ARRIBA, ABAJO 100 MINIMO
Servo servo4; //pinza PINZA ABRE 180, CIERRA 165 

int pin=3;
int pin2=5;
int pin3=6;
int pin4=9;
  
void setup()
{
   //Inicializamos el servo y el Serial:
   servo1.attach(pin); //Servo base
   servo2.attach(pin2); //Servp codo derecho 
   servo3.attach(pin3); //Servo codo izquierdo
   servo4.attach(pin4); //Servo pinza
   Serial.begin(9600);
}
  
void loop()
{
  ///////////////////MOVIMIENTO PREDETERMINADO///////////////////////
   servo3.write(100); // codo izquierdo arriba
   delay(2000);
   servo4.write(180); //abre pinza
   delay(2000);
   ////////////////////////////////////////////////////
   for (int i=140;i>100;i--){ //codo izquierdo abajo
    servo3.write(i);
    delay(15);
   }
   delay(3000);
   ////////////////////////////////////////////////////
   servo4.write(165); // cierra pinza
   delay(1000);
   ///////////////////////////////////////////////////
   for (int i=100;i<=140;i++){ //codo izquierdo arriba
    servo3.write(i);
    delay(15);
   }
   delay(2000);
   ///////////////////////////////////////////////////
   for (int i = 90 ; i>0;i--){
    servo1.write(i); //Movemos el servo de base a angulo 0 lado Derecho
     delay(10);
   }
   delay(3000);
   ///////////////////////////////////////////////////
   for (int i=140;i>100;i--){ //codo izquierdo abajo
    servo3.write(i);
    delay(15);
   }
   delay(2000);
   //////////////////////////////////////////////////
   servo4.write(180); //abre pinza
   delay(2000);
   //////////////////////////////////////////////////
   for (int i=100;i<=140;i++){ //codo izquierdo arriba
    servo3.write(i);
    delay(15);
   }
   delay(2000);
   ////////////////////////////////////////////////////
   for (int i=0;i<=90;i++){ //vuelve a la posicion inicial
    servo1.write(i);
    delay(15);
   }
   delay(1000);
}
