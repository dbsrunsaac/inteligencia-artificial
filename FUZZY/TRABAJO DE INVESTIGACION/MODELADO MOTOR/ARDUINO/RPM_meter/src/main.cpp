#include <Arduino.h>

// Variables de entrada y salida
int boton = 4;
int motor = 3;

// Variables adicionales (contadores, estados, etc)
int estados = 0;
int contadorEstado = 0;
int contadorFuncionamiento = 0;

// variables de interrupciòn
volatile int rpm = 0;

void rpmMotor(){
  rpm++;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // Definir entradas y salidas
  pinMode(boton, INPUT);
  pinMode(motor, OUTPUT);
  attachInterrupt(0, rpmMotor, RISING);
  // Mensaje inicial
  Serial.println("Tacometro - Inicializado");

}

void loop() {  
  if (digitalRead(boton) == HIGH){
    while( digitalRead(boton) == HIGH){}
    estados++;
  }

  if (estados == 0){
    // Motor en marcha (max)
    analogWrite(motor, 0);
    contadorEstado = 0;
    rpm = 0;
    contadorFuncionamiento = 0;

  }else if (estados == 1){

    if(contadorFuncionamiento != 100){
      digitalWrite(motor, HIGH);
      contadorFuncionamiento++;
      delay(100);
      Serial.println(rpm*60/0.2);
      rpm = 0;
    }else{
      Serial.println("Motor apagado");
      digitalWrite(motor, LOW);
      contadorEstado++;
      contadorFuncionamiento = 0;
    }

    if(contadorEstado == 1){
      estados = 0;
    }else{
      estados = 2;
    }

  }else if(estados == 2){
    rpm = 0;
    estados = 1;
  }else{
    estados = 0;
  }
}