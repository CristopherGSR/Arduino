#include <Servo.h>
Servo servo1; // BASE
Servo servo2; // CODO DERECHO MAXIMO ADELANTE 130, ATRAS 40 MINIMO
Servo servo3; // CODO IZQUIERDO 160 MAXIMO ARRIBA, ABAJO 100 MINIMO
Servo servo4; // PINZA ABRE 180, CIERRA 165 
 
String entradaSerial = "";         // String para almacenar entrada
String datos="";
bool entradaCompleta = false;  // Indicar si el String está completo
 
int pin = 3;    // pin de conexión PWM al servo
int pin2 = 5;
int pulsoMinimo = 580;  // Duración en microsegundos del pulso para girar 0º
int pulsoMaximo = 2500; // Duración en microsegundos del pulso para girar 180º
int angulo = 0; // Variable para guardar el angulo que deseamos de giro
boolean e=false;
int posServoY,posServoX,posX,posY;
String cad,cad1,cad2;
int pos,pos2;
int aux;
 
void setup()
{
  servo1.attach(pin, pulsoMinimo, pulsoMaximo);
  servo2.attach(pin2,pulsoMinimo, pulsoMaximo);
  Serial.begin(9600);
}
 
void loop()
{
  if (entradaCompleta) {

       posX = posServoX / 8; //MOVIMIENTO SERVO BASE X
       servo1.write(posX);
       delay(20);

       posY = posServoY / 4; //MOVIMIENTO SERVO CODO DERECHO Y
       servo2.write(posY);
       delay(20);
       
      if (cad2 == "movobj\n"){
        //posServo = posServo / 4;
      for(int x=posServoX;x<=170;x++){
       servo1.write(x);
       delay(10); 
      }
    }
    entradaSerial = "";
    datos="";
    entradaCompleta = false;
    cad="";
    cad2="";
}
 }
// Función que se activa al recibir algo por
// el puerto serie, Interrupción del Puerto Serie.
void serialEvent() {
  while (Serial.available()) {
    // Obtener bytes de entrada:
    char inChar = (char)Serial.read();
    // Agregar al String de entrada:
    entradaSerial += inChar;
    //Serial.println(inChar);
    //cad = Serial.readString();
    //Serial.println(inChar);
    // Para saber si el string está completo, se detendrá al recibir
    // el caracter de retorno de línea ENTER \n
    if (inChar == '\n') {
      Serial.println(entradaSerial);
      aux = entradaSerial.indexOf('\n');
      datos = entradaSerial.substring(0,aux);
      pos = datos.indexOf(','); // guardamos la posicion de la primera coma
      cad1 = datos.substring(0,pos); // guarda todo antes de la coma
      pos2 = datos.indexOf(',', pos +1); //guardamos la posicion de la segunda coma
      cad2 = datos.substring(pos+1,pos2); // guarda todo antes de la segunda coma
      //Serial.println(cad2);
      posServoX = cad1.toInt(); // guardamos la posicion del servo X
      posServoY = cad2.toInt(); //guardamos la posicion del servo Y
      entradaCompleta = true;
      //Serial.println("funciona");
    }
  }

}
