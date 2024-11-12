#include "app.h"

void APP_Init(void) {
    InitMux();
}

void APP_Loop(void) {
    Disp_Num(3);
}

void APP_Start(void) {
    APP_Init();
    while (1) {
        APP_Loop();
    }
}