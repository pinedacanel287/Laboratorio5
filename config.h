#ifndef _DISPLAY7SEG_H_
#define _DISPLAY7SEG_H_

#include <Arduino.h>

extern uint8_t pinA, pinB, pinC, pinD, pinE, pinF, pinG, pinP;

//Función para congigurar display de  7 segmentos: parámetros son los pines 
void configurarDisplay(uint8_t segA, uint8_t segB, uint8_t segC, uint8_t segD, uint8_t segE, uint8_t segF, uint8_t segG, uint8_t segP);
//Función para desplegar un número en el display

void desplegarDisplay (uint8_t numero);

//Funcipon para desplegar el punto en el display 
void desplegarPunto(uint8_t punto);

#endif // _DISPLAY7SEG_H_
