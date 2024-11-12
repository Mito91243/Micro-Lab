#ifndef __SS_H__
#define __SS_H__
#include "../../HAL/GPIO/gpio.h"
/*
typedef enum
{
    LED_SWITCH_INVERTED,
    LED_SWITCH_NORMAL
} EN_LED_SWITCH_INV;
*/

typedef struct 
{
    ST_PORT_PIN A;
    ST_PORT_PIN B; 
    ST_PORT_PIN C;
    ST_PORT_PIN D;
    ST_PORT_PIN E;
    ST_PORT_PIN F;
    ST_PORT_PIN G;
    ST_PORT_PIN COM;
    uint8_t value;
} ST_SS_letters;

typedef struct 
{
    ST_SS_letters Seg1;
    ST_SS_letters Seg2;
    ST_SS_letters Seg3;
    uint8_t timer;
    uint16_t totalvalue;
} ST_SS_MUX;

ST_SS_letters InitSevenSegmment(ST_SS_letters seg,ST_PORT_PIN x);
void Disp_Num(uint16_t number);
void Disp_SS(ST_SS_letters seg,uint16_t number);
void InitMux(void);
#endif