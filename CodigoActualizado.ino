#include <Servo.h>
Servo servo1; // BASE
Servo servo2; // CODO DERECHO MAXIMO ADELANTE 130, ATRAS 40 MINIMO
Servo servo3; // CODO IZQUIERDO 160 MAXIMO ARRIBA, ABAJO 100 MINIMO
Servo servo4; // PINZA ABRE 180, CIERRA 165 
 
String entradaSerial = "";         // String para almacenar entrada
bool entradaCompleta = false;  // Indicar si el String está completo
 
int pin = 3;    // pin de conexión PWM al servo
int pin2 = 5;
int pulsoMinimo = 580;  // Duración en microsegundos del pulso para girar 0º
int pulsoMaximo = 2500; // Duración en microsegundos del pulso para girar 180º
int angulo = 0; // Variable para guardar el angulo que deseamos de giro
boolean e=false;
int mssg,posServo;
String cad,cad2;
int pos;
 
void setup()
{
  servo1.attach(pin, pulsoMinimo, pulsoMaximo);
  servo2.attach(pin2,pulsoMinimo, pulsoMaximo);
  Serial.begin(9600);
}
 
void loop()
{
  if (entradaCompleta) {

       posServo = posServo / 4;
       servo1.write(posServo);
       delay(20);
       
      if (cad2 == "movobj\n"){
        //posServo = posServo / 4;
      for(int x=posServo;x<=170;x++){
       servo1.write(x);
       delay(10); 
      }
    }
    entradaSerial = "";
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
    
    // Para saber si el string está completo, se detendrá al recibir
    // el caracter de retorno de línea ENTER \n
    if (inChar == '\n') {
      entradaCompleta = true;
      //Serial.println("funciona");
    }
  }
  pos = entradaSerial.indexOf(','); // guardamos la posicion de la coma
  cad = entradaSerial.substring(0,pos); // guarda todo antes de la coma
  cad2 = entradaSerial.substring(pos+1); // guarda todo despues de la coma :v
  //Serial.println(cad);
  //Serial.println(cad2);
  posServo = cad.toInt(); // guardamos la posicion del servo
}
