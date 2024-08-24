#include <Arduino.h>
#include "config.h"
#include "display_7segmentos.h"


#define BTN1 15

// Definición de pines para los dígitos
#define DIS1 32
#define DIS2 33
// Definición de segmentos 
#define sA 25
#define sB 26
#define sC 14
#define sD 13
#define sE 5
#define sF 19
#define sG 21
#define sP 4
//Definiciòn de pines analògicos
#define PinPot1 36
#define PinPot2 39

//*********************** 

  void mostrar();
  void temporizacion();

//*********************** 

int pot1;
int pot2;
int mult;



// Set up the 'counter' feed
AdafruitIO_Feed *Canal1 = io.feed("pot1");
AdafruitIO_Feed *Canal2 = io.feed("pot2");
AdafruitIO_Feed *Canal3 = io.feed("mult");

// Variables para el debounce del botón
unsigned long t_Boton = 0;
unsigned long ultimo_t_Boton = 0;

//Función enviar datos
void IRAM_ATTR SUMA() {
  t_Boton = millis();
  if (t_Boton - ultimo_t_Boton > 250) {
    enviar ();
  }
}

void buttons(void);
void adaf();

void setup() {
  // Start the serial connection
  Serial.begin(115200);

  // Wait for serial monitor to open
  while (!Serial);

  Serial.print("Connecting to Adafruit IO");

  // Connect to io.adafruit.com
  io.connect();

  // Wait for a connection
  while (io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // We are connected
  Serial.println();
  Serial.println(io.statusText());

 configurarDisplay(sA, sB,sC, sD, sE, sF, sG, sP);
 pinMode (DIS1, OUTPUT);
 pinMode (DIS2, OUTPUT);

 buttons();
 mostrador();
 temporizacion();
 adaf();
 io.run();
}

void loop() {
 temporizacion ();
}

void adaf(){
   // io.run() is required for all sketches.

/*  Serial.print("valor1: ");
  Serial.println(valor1);
  Serial.print("valor2: ");
  Serial.println(valor2);
*/

  void enviar_datos(){
    multiplicacion = (valor1 * valor2);

    // Save count to the 'counter' feed on Adafruit IO
    Serial.print("sending -> ");
    Serial.println();
    Canal1->save(valor1);
    Canal2->save(valor2);
    Canal3->save(multiplicacion);
  }
}
void mostrador (){

   // Lee los valores de los pines analógicos
  valor1 = analogRead(PinPot1);
  valor2 = analogRead(PinPot2);
  valor1 = map(valor1, 0, 4095, 0, 15);
  valor2 = map(valor2, 0, 4095, 0, 15); 

  //Mostrar en display digito 1
  desplegarDisplay(valor1);
  //desplegarPunto(0);
  digitalWrite(DIS1, HIGH);
  delay(1);
   digitalWrite(DIS1, LOW);
  //Mostrar en display digito 2 
  desplegarDisplay(valor2);
  //desplegarPunto(0);
  digitalWrite(DIS2, HIGH);
  delay(1);
  digitalWrite(DIS2, LOW);
}

void temporizacion() 
{
   int contret=1000;
   while (contret>0)
   {
      mostrador();
      contret--; 
   }
      adaf(); 
}

void buttons(void) {
  pinMode(BTN1, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BTN1), onButton1Press, FALLING);
}
