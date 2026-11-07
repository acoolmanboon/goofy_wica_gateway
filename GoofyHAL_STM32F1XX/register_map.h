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

typedef struct {
	volatile uint32_t ACR;
	volatile uint32_t KEYR;
	volatile uint32_t OPTKEYR;
	volatile uint32_t SR;
	volatile uint32_t CR;
	volatile uint32_t AR;
	volatile uint32_t GIGGITY;
	volatile uint32_t OBR;
	volatile uint32_t WRPR;
} FLASH_REGISTER_MAP;

//typedef enum {
//
//} REGISTER_ADDRESSES;

// Register locations
#define RCC ((RCC_REGISTER_MAP *)0x40021000UL)
#define FLASH ((FLASH_REGISTER_MAP *)0x40022000UL)
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

#define RCC_CFGR_SW_OFFSET 0U
#define RCC_CFGR_SW_MASK FIELD_MASK(2, RCC_CFGR_SW_OFFSET)

#define RCC_CFGR_SWS_OFFSET 2U
#define RCC_CFGR_SWS_MASK FIELD_MASK(2, RCC_CFGR_SWS_OFFSET)

#define RCC_CFGR_HPRE_OFFSET 4U
#define RCC_CFGR_HPRE_MASK FIELD_MASK(4, RCC_CFGR_HPRE_OFFSET)

#define RCC_CFGR_PPRE1_OFFSET 8U
#define RCC_CFGR_PPRE1_MASK FIELD_MASK(3, RCC_CFGR_PPRE1_OFFSET)

#define RCC_CFGR_PPRE2_OFFSET 11U
#define RCC_CFGR_PPRE2_MASK FIELD_MASK(3, RCC_CFGR_PPRE2_OFFSET)

#define RCC_CFGR_PLLMUL_OFFSET 18U
#define RCC_CFGR_PLLMUL_MASK FIELD_MASK(3, RCC_CFGR_PLLMUL_OFFSET)

#define RCC_CFGR_PLLXTPRE_OFFSET 17U
#define RCC_CFGR_PLLXTPRE_MASK BIT_MASK(RCC_CFGR_PLLXTPRE_OFFSET)

#define RCC_CFGR_PLLSRC_OFFSET 16U
#define RCC_CFGR_PLLSRC_MASK BIT_MASK(RCC_CFGR_PLLSRC_OFFSET)

// Backup Domain Control Register

// Flash access control register
#define FLASH_ACR_CFG_MASK FIELD_MASK(0, 5) // this is a combination of fetch buffer and wait latency, special mask

// APB1 peripheral clock enable register
#define RCC_APB1ENR_PWREN_OFFSET 28U
#define RCC_APB1ENR_PWREN_MASK (1U << RCC_APB1ENR_PWREN_OFFSET)

#endif
