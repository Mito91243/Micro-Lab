#include "app.h"

void APP_Init(void) {
    Disable_JTAG_Enable_GPIO();
    InitMux();

    // Initialize the LCD
    LCD_Init();
    //LCD_ClearDisplay();
    // Set cursor to the first column of the first row
    LCD_SetCursor( 1, 1);
    LCD_Printstring("zeb ziad so8ayar");




}

void APP_Loop(void) {
    Disp_Num(624);
    //Disp_Num(156);
    //Disp_Float(1.64);
    //Disp_Float(15.4);

}

void APP_Start(void) {
    APP_Init();
    while (1) {
        APP_Loop();
    }
}