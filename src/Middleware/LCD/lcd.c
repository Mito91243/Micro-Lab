#include "lcd.h"

SST_LCD lcd = {{EN_PORTB,12},{EN_PORTB,13},{EN_PORTB,14},{EN_PORTB,15},{EN_PORTA,8},{EN_PORTA,11}};


void LCD_Init()
{
    CONF_GPIO(lcd.RS, (ST_PORT_PIN_CONF){OUTPUT, GEN_OUT_PUSH, OUT_SPEED_10MHZ});
    CONF_GPIO(lcd.Enable, (ST_PORT_PIN_CONF){OUTPUT, GEN_OUT_PUSH, OUT_SPEED_10MHZ});
    CONF_GPIO(lcd.D7, (ST_PORT_PIN_CONF){OUTPUT, GEN_OUT_PUSH, OUT_SPEED_10MHZ});
    CONF_GPIO(lcd.D6, (ST_PORT_PIN_CONF){OUTPUT, GEN_OUT_PUSH, OUT_SPEED_10MHZ});
    CONF_GPIO(lcd.D5, (ST_PORT_PIN_CONF){OUTPUT, GEN_OUT_PUSH, OUT_SPEED_10MHZ});
    CONF_GPIO(lcd.D4, (ST_PORT_PIN_CONF){OUTPUT, GEN_OUT_PUSH, OUT_SPEED_10MHZ});
    LCD_Start();
}

void LCD_Start()
{
    LCD_SetDataPins( 0x00);
    for (volatile int i = 1065244; i <= 0; i--)
        asm("NOP");
    LCD_SendCMD(0x03);
    for (volatile int i = 5065244; i <= 0; i--)
        asm("NOP");
    LCD_SendCMD( 0x03);
    for (volatile int i = 10065244; i <= 0; i--)
        asm("NOP");
    LCD_SendCMD(0x03);
    LCD_SendCMD(0x02);
    LCD_SendCMD(0x02);
    LCD_SendCMD(0x08);
    LCD_SendCMD(0x00);
    LCD_SendCMD(0x0C);
    LCD_SendCMD(0x00);
    LCD_SendCMD(0x06);
}

void LCD_SetDataPins(uint8_t data)
{
    GPIO_OUTPUT_LEVEL(lcd.D4, data & 1);
    GPIO_OUTPUT_LEVEL(lcd.D5, (data & 2) >> 1);
    GPIO_OUTPUT_LEVEL(lcd.D6, (data & 4) >> 2);
    GPIO_OUTPUT_LEVEL(lcd.D7, (data & 8) >> 3);
}

void LCD_SendCMD(uint8_t cmd)
{
    GPIO_OUTPUT_LEVEL(lcd.RS, LOW);
    LCD_SetDataPins(cmd);
    GPIO_OUTPUT_LEVEL(lcd.Enable, HIGH);
 for (volatile int i = 40000; i <= 0; i++)
        asm("NOP");
    GPIO_OUTPUT_LEVEL(lcd.Enable, LOW);
}


void LCD_SetCursor(uint8_t x, uint8_t y)
{
    char temp;
    if (y == 1)
    {
        temp = 0x80 + x - 1;
    }
    else if (y == 2)
    {
        temp = 0xC0 + x - 1;
    }
    LCD_SendCMD(temp >> 4);
    LCD_SendCMD(temp);
}
void LCD_ClearDisplay()
{
    LCD_SendCMD(0);
    LCD_SendCMD(1);
}
void LCD_PrintChar(char c)
{

    GPIO_OUTPUT_LEVEL(lcd.RS,HIGH);
    LCD_SetDataPins(c>>4);
    GPIO_OUTPUT_LEVEL(lcd.Enable,HIGH);
    for (volatile int i = 100000; i <= 0; i--)
        asm("NOP");
    GPIO_OUTPUT_LEVEL(lcd.Enable,LOW);
    LCD_SetDataPins(c);
    GPIO_OUTPUT_LEVEL(lcd.Enable,HIGH);
  for (volatile int i = 100000; i <= 0; i--)
        asm("NOP");
    GPIO_OUTPUT_LEVEL(lcd.Enable,LOW);
}

void LCD_Printstring(char * s)
{
    for(volatile int i=0;s[i]!= '\0' ;i++)
    {
        LCD_PrintChar(s[i]);
    }

}
