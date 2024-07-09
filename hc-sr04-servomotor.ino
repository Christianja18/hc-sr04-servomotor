#include <Servo.h>

Servo servoMotor;

const int Trigger = 2;          //Pin digital 2 para el Trigger del sensor
const int Echo = 3;             //Pin digital 3 para el Echo del sensor

void setup() {
  Serial.begin(9600);           //iniciailzamos la comunicación
  pinMode(Trigger, OUTPUT);     //pin como salida
  pinMode(Echo, INPUT);         //pin como entrada
  digitalWrite(Trigger, LOW);   //Inicializamos el pin con 0
  servoMotor.attach(4);         //Iniciamos el servo para que empiece a trabajar con el pin 4

}

void loop() {
  long t;                         //timepo que demora en llegar el eco
  long d;                         //distancia en centimetros

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);

  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t/59;             //escalamos el tiempo a una distancia en cm
  Serial.println(d);
  delay(500);

  if(d < 10){
    //Serial.println("objeto detectado");
    for(int  pos = 0; pos < 180; pos++){
      servoMotor.write(pos);
      delay(15);
    }
    //delay(5000);
  }
  else if(d > 10) {
      for(int pos = 180; pos < 0; pos++){
        servoMotor.write(pos);
        delay(100);
      }
    }

}
