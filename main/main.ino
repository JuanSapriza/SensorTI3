#include <string.h>
#include "COLOR.h"



// Todo el código que coloquen dentro de setup() se correrá una sola vez, cuando se prenda el Arduino
void setup() {
  //inicialización serial y sensor
  Serial.begin(9600);
  COLOR_init();
  Serial.println("Hola Mundo!");
}

// Todo el código que coloquen dentro de loop() se corre infinitamente mientras el Arduino esté prendido, luego de haber corrido setup()

bool onlyOnce = true;
int buttonState;

void loop() {
    Serial.println (COLOR_getColorName()); // Se obtiene el nombre del color que esté viendo el sensor y se imprime en el monitor (Herramientas > Monitor Serial)

    delay(1000); // Este delay no es necesario si ya se incluyen otros delays en el programa que utilizan. Simplemente evita congestionar la consola. 
}
