#ifndef __LIQUIDCRYSTAL_H__
#define __LIQUIDCRYSTAL_H__
#include"../../HAL/GPIO\gpio.h"

typedef struct
{
ST_PORT_PIN D7;
ST_PORT_PIN D6;
ST_PORT_PIN D5;
ST_PORT_PIN D4;
ST_PORT_PIN Enable;
ST_PORT_PIN RS;

}SST_LCD;

void LCD_Init(void);
void LCD_Start(void);
void LCD_SetDataPins( uint8_t data);
void LCD_SendCMD(uint8_t cmd);
void LCD_ClearDisplay(void);
void LCD_SetCursor(uint8_t x, uint8_t y);
void LCD_PrintChar(char c);
void LCD_Printstring (char* s);

#endif