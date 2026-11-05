/*
 * register_map.h
 *
 *  Created on: Nov 4, 2026
 *      Author: acoolmanboon
 */

#include <stdint.h>

#ifndef GOOFYHAL_STM32F1XX_REGISTER_MAP_H
#define GOOFYHAL_STM32F1XX_REGISTER_MAP_H

#define BIT_MASK(n) (1U << (n))
#define FIELD_MASK(width, pos) (((1U << (width)) - 1U) << (pos)) // this is lowkey genius

// Register maps
typedef struct {
    volatile uint32_t CR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;
    volatile uint32_t APB2RSTR;
    volatile uint32_t APB1RSTR;
    volatile uint32_t AHBENR;
    volatile uint32_t APB2ENR;
    volatile uint32_t APB1ENR;
    volatile uint32_t BDCR;
    volatile uint32_t CSR;
    volatile uint32_t AHBRSTR;
    volatile uint32_t CFGR2;
} RCC_REGISTER_MAP;

typedef struct {
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
} GPIO_REGISTER_MAP;

//typedef enum {
//
//} REGISTER_ADDRESSES;

// Register locations
#define RCC ((RCC_REGISTER_MAP *)0x40021000UL)

#define GPIOA ((GPIO_REGISTER_MAP *)0x40010800UL)
#define GPIOB ((GPIO_REGISTER_MAP *)0x40010C00UL)
#define GPIOC ((GPIO_REGISTER_MAP *)0x40011000UL)
#define GPIOD ((GPIO_REGISTER_MAP *)0x40011400UL)
#define GPIOE ((GPIO_REGISTER_MAP *)0x40011800UL)
#define GPIOF ((GPIO_REGISTER_MAP *)0x40011C00UL)
#define GPIOG ((GPIO_REGISTER_MAP *)0x40012000UL)

// im fucking deleting this im not making like 576 port definitions
// blud
#define GPIO_CRH_PORT11_OFFSET 12U
#define GPIO_CRH_PORT11_MASK FIELD_MASK(4, GPIO_CRH_PORT11_OFFSET)

// Clock control register
#define RCC_CR_HSION_OFFSET 0U
#define RCC_CR_HSION_MASK BIT_MASK(RCC_CR_HSION_OFFSET)

#define RCC_CR_HSIRDY_OFFSET 1U
#define RCC_CR_HSIRDY_MASK BIT_MASK(RCC_CR_HSIRDY_OFFSET)

#define RCC_CR_HSEON_OFFSET 16U // High Speed External Clock Enable
#define RCC_CR_HSEON_MASK BIT_MASK(RCC_CR_HSEON_OFFSET)

#define RCC_CR_HSERDY_OFFSET 17U // High Speed External Clock Ready Flag
#define RCC_CR_HSERDY_MASK BIT_MASK(RCC_CR_HSERDY_OFFSET)

#define RCC_CR_HSEBYP_OFFSET 18U // High Speed External Clock Bypass
#define RCC_CR_HSEBYP_MASK BIT_MASK(RCC_CR_HSEBYP_OFFSET)

#define RCC_CR_CSSON_OFFSET 19U
#define RCC_CR_CSSON_MASK BIT_MASK(RCC_CR_CSSON_OFFSET)

#define RCC_CR_PLLON_OFFSET 24U
#define RCC_CR_PLLON_MASK BIT_MASK(RCC_CR_PLLON_OFFSET)

#define RCC_CR_PLLRDY_OFFSET 25U
#define RCC_CR_PLLRDY_MASK BIT_MASK(RCC_CR_PLLRDY_OFFSET)

// Clock Configuration Register
typedef enum
{
    HSI = 0x00,
    HSE = 0x01,
    PLL = 0x02,
	ERR = 0x03,
} OSCILLATOR;

#define RCC_CFGR_SW_OFFSET 0U
#define RCC_CFGR_SW_MASK FIELD_MASK(2, RCC_CFGR_SW_OFFSET)


#define RCC_CFGR_SWS_OFFSET 2U
#define RCC_CFGR_SWS_MASK FIELD_MASK(2, RCC_CFGR_SWS_OFFSET)


// Backup Domain Control Register

// APB1 peripheral clock enable register
#define RCC_APB1ENR_PWREN_OFFSET 28U
#define RCC_APB1ENR_PWREN_MASK (1U << RCC_APB1ENR_PWREN_OFFSET)

#endif
