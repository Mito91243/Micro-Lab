#include "app.h"

void APP_Init(void) {
    InitMux();
}

void APP_Loop(void) {
    Disable_JTAG_Enable_GPIO();
    //Disp_Num(624);
    //Disp_Num(156);
    //Disp_Float(1.64);
    Disp_Float(15.4);
}

void APP_Start(void) {
    APP_Init();
    while (1) {
        APP_Loop();
    }
}