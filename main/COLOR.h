#ifndef COLOR_H
#define COLOR_H

#include "Adafruit_TCS34725.h"

// pines donde están conectados los leds
#define OUT_LED_EMB 3 // led embebido en el sensor
#define OUT_LED_EXT 2 // led externo


// intensidad de los leds. 0 es apagado, 255 es la máxima intensidad.
#define LED_OFF 0
#define LED_EMB_INTENSITY 32
#define LED_EXT_INTENSITY 128


#define MAX_HUE_ROJO 14
#define MAX_HUE_NARANJA 30
#define MAX_HUE_AMARILLO 60
#define MAX_HUE_VERDE 150
#define MAX_HUE_AZUL 270
#define MAX_HUE_VIOLETA 355
#define MAX_HUE_ROJO_2 360

#define INDEX_OF_NAME_BLANCO 0
#define INDEX_OF_NAME_NEGRO 1
#define INDEX_OF_NAME_GRIS 2
#define INDEX_START_OF_COLORS 3

#define LUMINOSITY_MIN_BLANCO 31
#define LUMINOSITY_MAX_NEGRO LUMINOSITY_MIN_BLANCO
#define LUMINOSITY_MAX_GRIS LUMINOSITY_MAX_NEGRO
#define SATURATION_MAX_BLANCO 11
#define SATURATION_MAX_NEGRO 20
#define SATURATION_MAX_GRIS 15

#define H_CONVERTER 360.0
#define LS_CONVERTER 100.0

#define CHAR_MAX_VAL 255

#define UNKOWN_COLOR -1

typedef enum {
    LIGHT_SOURCE_OFF  =  0b00000000,
    LIGHT_SOURCE_EMB  =  0b00000001,
    LIGHT_SOURCE_EXT  =  0b00000010,
    LIGHT_SOURCE_BOTH =  0b00000011,
} LIGHT_SOURCE_t;


/**
 * Estructura para almacenar la informacion RGB del color
 */
typedef struct{
    float red;
    float green;
    float blue;
} RGB_t;

/**
 * Estructura para almacenar la informacion HSL del color
 */
typedef struct{
    double hue;
    double saturation;
    double luminosity;
} HSL_t;


void COLOR_init(  tcs34725IntegrationTime_t p_integrationTime, tcs34725Gain_t p_gain );
char * COLOR_getColorName( LIGHT_SOURCE_t p_lightSource );
char* COLOR_getNameFromIndex( int p_index );
int COLOR_getIndex( HSL_t p_hsl );
RGB_t COLOR_getRGB( LIGHT_SOURCE_t p_lightSource );
HSL_t COLOR_getHSLfromRGB( RGB_t p_rgb );

#endif /* COLOR_H */
