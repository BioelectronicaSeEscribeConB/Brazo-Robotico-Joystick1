#include <Servo.h> //libreria
Servo myservo;     //objeto servo
Servo myservo2;     //objeto servo
Servo myservo3;     //objeto servo
Servo myservo4;     //objeto servo
int pos = 0;       // posicion
int pos2 = 0;       // posicion
int pos3 = 0;       // posicion
int pot=A0;        //pot1 en A0 del jotstick
int pot2=A1;        //pot2 en A0 del joystick
int valorPot=0;    //valor del potenciometro
int valorPot2=0;    //valor del potenciometro
int botonAutomatico=13; // pin 7 se conceta la señal del boton de rutina Automatica
int estadoAutomatico=0;// variable donde guardamos el estado del boton de rutina automatica

void setup() 
{
 myservo.attach(7);  //servo en pin 9
 pinMode(pot,INPUT); //por como entrada
 myservo2.attach(8);  //servo en pin 9
 pinMode(pot2,INPUT); //por como entrada
 pinMode(botonAutomatico,INPUT_PULLUP); //señal de boton como entrada digital
 myservo3.attach(9);  //servo en pin 9
 myservo4.attach(10);  //servo en pin 9
 Serial.begin(9600);
}

void loop() 
{
 estadoAutomatico=digitalRead(botonAutomatico);  //leemos el estado del boton automatico
  Serial.print(" | Button: ");
  Serial.println(estadoAutomatico);
 if(estadoAutomatico==LOW)                       //si boton automatico fue presionado 
{
 myservo4.write(10);              // escribe la posicion angular

}
else
{
myservo4.write(150);              // escribe la posicion angular

}

 valorPot=analogRead(pot);         // leemos el valor del pot del joystick
 valorPot=map(valorPot,0,1023,30,130);
 myservo.write(valorPot);              // escribe la posicion angular

 valorPot=analogRead(pot);
 valorPot=map(valorPot,0,1023,180,130);
 myservo2.write(valorPot);              // escribe la posicion angular

  valorPot2=analogRead(pot2);
 valorPot2=map(valorPot2,0,1023,10,170);
 myservo3.write(valorPot2);              // escribe la posicion angular
 
 delay(400);                       // mantiene 15ms la posicion
 
}
