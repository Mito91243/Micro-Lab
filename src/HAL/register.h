#ifndef __REGISTER_H__
#define __REGISTER_H__
#include "register_map.h"
#include "../Common/bitop.h"

typedef struct {
    __IO uint32_t GPIO_CRL;
    __IO uint32_t GPIO_CRH;
    __IO uint32_t GPIO_IDR;
    __IO uint32_t GPIO_ODR;
    __IO uint32_t GPIO_BSRR;
    __IO uint32_t GPIO_BRR;
    __IO uint32_t GPIO_LCKR;
} GPIO_Typedef;

typedef struct {
    __IO uint32_t RCC_CR;
    __IO uint32_t RCC_CFGR;
    __IO uint32_t RCC_CIR;
    __IO uint32_t RCC_APB2RSTR;
    __IO uint32_t RCC_APB1RSTR;
    __IO uint32_t RCC_AHBENR;
    __IO uint32_t RCC_APB2ENR;
    __IO uint32_t RCC_APB1ENR;
    __IO uint32_t RCC_BDCR;
    __IO uint32_t RCC_CSR;
    __IO uint32_t RCC_AHBSTR;
    __IO uint32_t RCC_CFGR2;
} RCC_Typedef;

typedef struct {
    __IO uint32_t STK_CTRL;
    __IO uint32_t STK_LOAD;
    __IO uint32_t STK_VAL;
    __IO uint32_t STK_CALIB;
} Systick_Typedef;

#define PORTA   ((GPIO_Typedef*) GPIO_A_BASE)
#define PORTB   ((GPIO_Typedef*) GPIO_B_BASE)
#define PORTC   ((GPIO_Typedef*) GPIO_C_BASE)
#define PORTD   ((GPIO_Typedef*) GPIO_D_BASE)

#define RCC     ((RCC_Typedef*) RCC_BASE)

#define SYSTICK ((Systick_Typedef*) SYSTICK_BASE)

#endif

