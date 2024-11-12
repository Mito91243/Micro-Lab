#include "SS.h"

ST_SS_MUX Mux;

void InitMux () {
    ST_SS_letters SevenSeg = {{EN_PORTA, 11},{EN_PORTA, 8},{EN_PORTB, 15},{EN_PORTB, 14},{EN_PORTB, 13},{EN_PORTB, 12},{EN_PORTA, 12},{EN_PORTB, 8},0};
    ST_PORT_PIN Seg1 = {EN_PORTB, 3};
    ST_PORT_PIN Seg2 = {EN_PORTB, 8};
    ST_PORT_PIN Seg3 = {EN_PORTB, 9};
    ST_SS_letters x = InitSevenSegmment(SevenSeg,Seg1);
    ST_SS_letters y = InitSevenSegmment(SevenSeg,Seg2);
    ST_SS_letters z = InitSevenSegmment(SevenSeg,Seg3);
    ST_SS_MUX tempmux = {x,y,z,0,0};
    Mux = tempmux;
}

ST_SS_letters InitSevenSegmment(ST_SS_letters seg,ST_PORT_PIN COM) {
    seg.COM = COM;
    // Configure each segment pin as output
    CONF_GPIO(seg.A, (ST_PORT_PIN_CONF){OUTPUT, GEN_OUT_PUSH, OUT_SPEED_10MHZ});
    CONF_GPIO(seg.B, (ST_PORT_PIN_CONF){OUTPUT, GEN_OUT_PUSH, OUT_SPEED_10MHZ});
    CONF_GPIO(seg.C, (ST_PORT_PIN_CONF){OUTPUT, GEN_OUT_PUSH, OUT_SPEED_10MHZ});
    CONF_GPIO(seg.D, (ST_PORT_PIN_CONF){OUTPUT, GEN_OUT_PUSH, OUT_SPEED_10MHZ});
    CONF_GPIO(seg.E, (ST_PORT_PIN_CONF){OUTPUT, GEN_OUT_PUSH, OUT_SPEED_10MHZ});
    CONF_GPIO(seg.F, (ST_PORT_PIN_CONF){OUTPUT, GEN_OUT_PUSH, OUT_SPEED_10MHZ});
    CONF_GPIO(seg.G, (ST_PORT_PIN_CONF){OUTPUT, GEN_OUT_PUSH, OUT_SPEED_10MHZ});
    CONF_GPIO(seg.COM, (ST_PORT_PIN_CONF){OUTPUT, GEN_OUT_PUSH, OUT_SPEED_10MHZ});
    return seg;
}

void Disp_Num(uint16_t number) {
    Mux.totalvalue = number;
    if (number < 10) {
        GPIO_OUTPUT_LEVEL(Mux.Seg1.COM, HIGH);
        Disp_SS(Mux.Seg1,number);
    } else if (number < 100 && number >= 10) {
        GPIO_OUTPUT_LEVEL(Mux.Seg1.COM, HIGH);
        GPIO_OUTPUT_LEVEL(Mux.Seg2.COM, HIGH);
        Disp_SS(Mux.Seg1,number/10);
        Disp_SS(Mux.Seg2,number%10);        
    } else if(number < 1000 && number >= 100) {
        GPIO_OUTPUT_LEVEL(Mux.Seg1.COM, HIGH);
        GPIO_OUTPUT_LEVEL(Mux.Seg2.COM, HIGH);
        GPIO_OUTPUT_LEVEL(Mux.Seg3.COM, HIGH);
        uint16_t digit1 = number / 100;         // Hundreds place
        uint16_t digit2 = (number / 10) % 10;   // Tens place
        uint16_t digit3 = number % 10;          // Units place
        Disp_SS(Mux.Seg1,digit1);
        Disp_SS(Mux.Seg2,digit2);
        Disp_SS(Mux.Seg2,digit3);        
    }
}

void Disp_SS(ST_SS_letters seg,uint16_t number) {
        // Function to set the segments High or Low based on the input number
    // Assume HIGH and LOW are defined appropriately
    switch(number) {
        case 0:
            // Segments A, B, C, D, E, F are HIGH; G is LOW
            GPIO_OUTPUT_LEVEL(seg.A, HIGH);
            GPIO_OUTPUT_LEVEL(seg.B, HIGH);
            GPIO_OUTPUT_LEVEL(seg.C, HIGH);
            GPIO_OUTPUT_LEVEL(seg.D, HIGH);
            GPIO_OUTPUT_LEVEL(seg.E, HIGH);
            GPIO_OUTPUT_LEVEL(seg.F, HIGH);
            GPIO_OUTPUT_LEVEL(seg.G, LOW);
            break;
        case 1:
            // Segments B, C are HIGH; others are LOW
            GPIO_OUTPUT_LEVEL(seg.A, LOW);
            GPIO_OUTPUT_LEVEL(seg.B, HIGH);
            GPIO_OUTPUT_LEVEL(seg.C, HIGH);
            GPIO_OUTPUT_LEVEL(seg.D, LOW);
            GPIO_OUTPUT_LEVEL(seg.E, LOW);
            GPIO_OUTPUT_LEVEL(seg.F, LOW);
            GPIO_OUTPUT_LEVEL(seg.G, LOW);
            break;
        case 2:
            // Segments A, B, D, E, G are HIGH; C, F are LOW
            GPIO_OUTPUT_LEVEL(seg.A, HIGH);
            GPIO_OUTPUT_LEVEL(seg.B, HIGH);
            GPIO_OUTPUT_LEVEL(seg.C, LOW);
            GPIO_OUTPUT_LEVEL(seg.D, HIGH);
            GPIO_OUTPUT_LEVEL(seg.E, HIGH);
            GPIO_OUTPUT_LEVEL(seg.F, LOW);
            GPIO_OUTPUT_LEVEL(seg.G, HIGH);
            break;
        case 3:
            // Segments A, B, C, D, G are HIGH; E, F are LOW
            GPIO_OUTPUT_LEVEL(seg.A, HIGH);
            GPIO_OUTPUT_LEVEL(seg.B, HIGH);
            GPIO_OUTPUT_LEVEL(seg.C, HIGH);
            GPIO_OUTPUT_LEVEL(seg.D, HIGH);
            GPIO_OUTPUT_LEVEL(seg.E, LOW);
            GPIO_OUTPUT_LEVEL(seg.F, LOW);
            GPIO_OUTPUT_LEVEL(seg.G, HIGH);
            break;
        case 4:
            // Segments B, C, F, G are HIGH; A, D, E are LOW
            GPIO_OUTPUT_LEVEL(seg.A, LOW);
            GPIO_OUTPUT_LEVEL(seg.B, HIGH);
            GPIO_OUTPUT_LEVEL(seg.C, HIGH);
            GPIO_OUTPUT_LEVEL(seg.D, LOW);
            GPIO_OUTPUT_LEVEL(seg.E, LOW);
            GPIO_OUTPUT_LEVEL(seg.F, HIGH);
            GPIO_OUTPUT_LEVEL(seg.G, HIGH);
            break;
        case 5:
            // Segments A, C, D, F, G are HIGH; B, E are LOW
            GPIO_OUTPUT_LEVEL(seg.A, HIGH);
            GPIO_OUTPUT_LEVEL(seg.B, LOW);
            GPIO_OUTPUT_LEVEL(seg.C, HIGH);
            GPIO_OUTPUT_LEVEL(seg.D, HIGH);
            GPIO_OUTPUT_LEVEL(seg.E, LOW);
            GPIO_OUTPUT_LEVEL(seg.F, HIGH);
            GPIO_OUTPUT_LEVEL(seg.G, HIGH);
            break;
        case 6:
            // Segments A, C, D, E, F, G are HIGH; B is LOW
            GPIO_OUTPUT_LEVEL(seg.A, HIGH);
            GPIO_OUTPUT_LEVEL(seg.B, LOW);
            GPIO_OUTPUT_LEVEL(seg.C, HIGH);
            GPIO_OUTPUT_LEVEL(seg.D, HIGH);
            GPIO_OUTPUT_LEVEL(seg.E, HIGH);
            GPIO_OUTPUT_LEVEL(seg.F, HIGH);
            GPIO_OUTPUT_LEVEL(seg.G, HIGH);
            break;
        case 7:
            // Segments A, B, C are HIGH; D, E, F, G are LOW
            GPIO_OUTPUT_LEVEL(seg.A, HIGH);
            GPIO_OUTPUT_LEVEL(seg.B, HIGH);
            GPIO_OUTPUT_LEVEL(seg.C, HIGH);
            GPIO_OUTPUT_LEVEL(seg.D, LOW);
            GPIO_OUTPUT_LEVEL(seg.E, LOW);
            GPIO_OUTPUT_LEVEL(seg.F, LOW);
            GPIO_OUTPUT_LEVEL(seg.G, LOW);
            break;
        case 8:
            // All segments are HIGH
            GPIO_OUTPUT_LEVEL(seg.A, HIGH);
            GPIO_OUTPUT_LEVEL(seg.B, HIGH);
            GPIO_OUTPUT_LEVEL(seg.C, HIGH);
            GPIO_OUTPUT_LEVEL(seg.D, HIGH);
            GPIO_OUTPUT_LEVEL(seg.E, HIGH);
            GPIO_OUTPUT_LEVEL(seg.F, HIGH);
            GPIO_OUTPUT_LEVEL(seg.G, HIGH);
            break;
        case 9:
            // Segments A, B, C, D, F, G are HIGH; E is LOW
            GPIO_OUTPUT_LEVEL(seg.A, HIGH);
            GPIO_OUTPUT_LEVEL(seg.B, HIGH);
            GPIO_OUTPUT_LEVEL(seg.C, HIGH);
            GPIO_OUTPUT_LEVEL(seg.D, HIGH);
            GPIO_OUTPUT_LEVEL(seg.E, LOW);
            GPIO_OUTPUT_LEVEL(seg.F, HIGH);
            GPIO_OUTPUT_LEVEL(seg.G, HIGH);
            break;
        default:
            // Turn off all segments
            GPIO_OUTPUT_LEVEL(seg.A, LOW);
            GPIO_OUTPUT_LEVEL(seg.B, LOW);
            GPIO_OUTPUT_LEVEL(seg.C, LOW);
            GPIO_OUTPUT_LEVEL(seg.D, LOW);
            GPIO_OUTPUT_LEVEL(seg.E, LOW);
            GPIO_OUTPUT_LEVEL(seg.F, LOW);
            GPIO_OUTPUT_LEVEL(seg.G, LOW);
            break;
    }
    seg.value = number;
}