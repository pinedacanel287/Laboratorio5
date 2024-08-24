#include "display_7segmentos.h"

uint8_t pinA, pinB, pinC, pinD, pinE, pinF, pinG, pinP;

// Función para configurar display de 7 segmentos: parámetros son los pines
void configurarDisplay(uint8_t segA, uint8_t segB, uint8_t segC, uint8_t segD, uint8_t segE, uint8_t segF, uint8_t segG, uint8_t segP){
   pinA = segA;
   pinB = segB;
   pinB = segC;
   pinB = segD;
   pinB = segE;
   pinB = segF;
   pinB = segG;
   pinB = segP;
   
   pinMode(pinA, OUTPUT);
   pinMode(pinB, OUTPUT);
   pinMode(pinC, OUTPUT);
   pinMode(pinD, OUTPUT);
   pinMode(pinE, OUTPUT);
   pinMode(pinF, OUTPUT);
   pinMode(pinG, OUTPUT);
   pinMode(pinP, OUTPUT);
   
   // Apagar segmentos (display cátodo común)
   digitalWrite(pinA, HIGH);
   digitalWrite(pinB, HIGH);
   digitalWrite(pinC, HIGH);
   digitalWrite(pinD, HIGH);
   digitalWrite(pinE, HIGH);
   digitalWrite(pinF, HIGH);
   digitalWrite(pinG, HIGH);
   digitalWrite(pinP, HIGH);
    
}

// Función para desplegar un número en el display
void desplegarDisplay(uint8_t numero){
    switch (numero)
    {
    case 0:
        digitalWrite(pinA, LOW);
        digitalWrite(pinB, LOW);
        digitalWrite(pinC, LOW);
        digitalWrite(pinD, LOW);
        digitalWrite(pinE, LOW);
        digitalWrite(pinF, LOW);
        digitalWrite(pinG, HIGH);
        break;
    case 1:
        digitalWrite(pinA, HIGH);
        digitalWrite(pinB, LOW);
        digitalWrite(pinC, LOW);
        digitalWrite(pinD, HIGH);
        digitalWrite(pinE, HIGH);
        digitalWrite(pinF, HIGH);
        digitalWrite(pinG, HIGH);
        break;
    case 2:
        digitalWrite(pinA, LOW);
        digitalWrite(pinB, LOW);
        digitalWrite(pinC, HIGH);
        digitalWrite(pinD, LOW);
        digitalWrite(pinE, LOW);
        digitalWrite(pinF, HIGH);
        digitalWrite(pinG, LOW);
        break;
    case 3:
        digitalWrite(pinA, LOW);
        digitalWrite(pinB, LOW);
        digitalWrite(pinC, LOW);
        digitalWrite(pinD, LOW);
        digitalWrite(pinE, HIGH);
        digitalWrite(pinF, HIGH);
        digitalWrite(pinG, LOW);
        break;
    case 4:
        digitalWrite(pinA, HIGH);
        digitalWrite(pinB, LOW);
        digitalWrite(pinC, LOW);
        digitalWrite(pinD, HIGH);
        digitalWrite(pinE, HIGH);
        digitalWrite(pinF, LOW);
        digitalWrite(pinG, LOW);
        break;
    case 5:
        digitalWrite(pinA, LOW);
        digitalWrite(pinB, HIGH);
        digitalWrite(pinC, LOW);
        digitalWrite(pinD, LOW);
        digitalWrite(pinE, HIGH);
        digitalWrite(pinF, LOW);
        digitalWrite(pinG, LOW);
        break;
    case 6:
        digitalWrite(pinA, LOW);
        digitalWrite(pinB, HIGH);
        digitalWrite(pinC, LOW);
        digitalWrite(pinD, LOW);
        digitalWrite(pinE, LOW);
        digitalWrite(pinF, LOW);
        digitalWrite(pinG, LOW);
        break;
    case 7:
        digitalWrite(pinA, LOW);
        digitalWrite(pinB, LOW);
        digitalWrite(pinC, LOW);
        digitalWrite(pinD, HIGH);
        digitalWrite(pinE, HIGH);
        digitalWrite(pinF, HIGH);
        digitalWrite(pinG, HIGH);
        break;
    case 8:
        digitalWrite(pinA, LOW);
        digitalWrite(pinB, LOW);
        digitalWrite(pinC, LOW);
        digitalWrite(pinD, LOW);
        digitalWrite(pinE, LOW);
        digitalWrite(pinF, LOW);
        digitalWrite(pinG, LOW);
        break;
}

// Función para desplegar el punto en el display
void desplegarPunto(uint8_t punto){
    if(punto == 1){
        digitalWrite(pinP, LOW);
    } else{
        digitalWrite(pinP, HIGH);
    }
}
