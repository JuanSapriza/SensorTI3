#include <string.h>
#include "COLOR.h"

#define DELAY_BETWEEN_TAKES 100
#define LIGHT_SOURCE LIGHT_SOURCE_BOTH
#define COLOR_SENSOR_INTEGRATION_TIME TCS34725_INTEGRATIONTIME_50MS
#define COLOR_SENSOR_GAIN TCS34725_GAIN_60X
#define MITIGATION_FACTOR_RED   0.8
#define MITIGATION_FACTOR_GREEN 1
#define MITIGATION_FACTOR_BLUE  1

#define SLAVE false

// Todo el código que coloquen dentro de setup() se correrá una sola vez, cuando se prenda el Arduino

void setup( ){
    //inicialización serial y sensor
    Serial.begin( 9600 );
    COLOR_init( COLOR_SENSOR_INTEGRATION_TIME, COLOR_SENSOR_GAIN );
    Serial.println( "Arduino UNO con sensor TCS4725 reportandose para la mision!" );
}

// Todo el código que coloquen dentro de loop() se corre infinitamente mientras el Arduino esté prendido, luego de haber corrido setup()

void loop( ){
    RGB_t rgb;
    HSL_t hsl;

    // El Arduino puede comportarse como "SLAVE" y solo ejecutar una lectura cuando le llega algún dato por el puerto serial.
    // Si no se comporta como SLAVE, siempre está leyendo. 
    if( !( SLAVE && ( Serial.read( ) <= 0 ) ) ){
        //Serial.println(COLOR_getColorName( LIGHT_SOURCE_EXT )); // Se obtiene el nombre del color que esté viendo el sensor y se imprime en el monitor (Herramientas > Monitor Serial)
        rgb = COLOR_getRGB( LIGHT_SOURCE ); // Se obtienen los valores de R, G y B con una fuente lumínica especifica

        // La luz embebida del sensor hace que los colores queden "rojizos".
        // Para mitigar este efecto, si la luz va a ser prendida, se le quita peso al color rojo sensado.
        if( LIGHT_SOURCE != LIGHT_SOURCE_EXT ){
            rgb.red *= MITIGATION_FACTOR_RED;

            // Además se atenuan los demás colores para poder ajustarlo de forma empírica
            rgb.green *= MITIGATION_FACTOR_GREEN;
            rgb.blue *= MITIGATION_FACTOR_BLUE;
        }
        hsl = COLOR_getHSLfromRGB( rgb );

        // Los valores obtenidos se envían por el puerto serial
        Serial.println( "RGB/HSL: " + String( rgb.red ) + ", " + String( rgb.green ) + ", " + String( rgb.blue ) + " | " + String( hsl.hue ) + ", " + String( hsl.saturation ) + ", " + String( hsl.luminosity ) );

    }
    delay( DELAY_BETWEEN_TAKES ); // Este delay no es necesario si ya se incluyen otros delays en el programa que utilizan. Simplemente evita congestionar la consola. 
}
