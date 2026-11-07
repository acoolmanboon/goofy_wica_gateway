/*
 * clock.h
 *
 *  Created on: Nov 5, 2026
 *      Author: acoolmanboon
 */

#ifndef GOOFYHAL_STM32F1XX_DRIVERS_CLOCK_H_
#define GOOFYHAL_STM32F1XX_DRIVERS_CLOCK_H_

#include "../register_map.h"
#include "../config.h"

typedef enum {
	CLOCK_OSCILLATOR_OFFSET_HSI = 0,
	CLOCK_OSCILLATOR_OFFSET_HSE = 16,
	CLOCK_OSCILLATOR_OFFSET_PLL = 24,
} CLOCK_OSCILLATOR_OFFSET;

typedef enum {
	CLOCK_OSCILLATOR_HSI = 0x00,
	CLOCK_OSCILLATOR_HSE = 0x01,
	CLOCK_OSCILLATOR_PLL = 0x02,
} CLOCK_OSCILLATOR;

static inline void ENABLE_CSS() {
	RCC->CR |= RCC_CR_CSSON_MASK;
}

static inline void DISABLE_CSS() {
	RCC->CR &=~RCC_CR_CSSON_MASK;
}

static inline void ENABLE_OSCILLATOR(CLOCK_OSCILLATOR_OFFSET oscillator) {
	RCC->CR |= (1U << oscillator);
	while (!(RCC->CR & (1U << (oscillator + 1U))));
}

static inline void DISABLE_OSCILLATOR(CLOCK_OSCILLATOR_OFFSET oscillator) {
	RCC->CR &= (1U << oscillator);
	while (RCC->CR & (1U << (oscillator + 1U)));
}

static inline void SWITCH_SYSTEM_CLOCK(CLOCK_OSCILLATOR oscillator) {
	RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_SW_MASK) | oscillator;
	while ((RCC->CFGR & RCC_CFGR_SWS_MASK) != (oscillator << 2U));
}

// PLL stuff

typedef enum {
    PLL_MULTIPLIER_2  = 0x000000,
    PLL_MULTIPLIER_3  = 0x040000,
    PLL_MULTIPLIER_4  = 0x080000,
    PLL_MULTIPLIER_5  = 0x0C0000,
    PLL_MULTIPLIER_6  = 0x100000,
    PLL_MULTIPLIER_7  = 0x140000,
    PLL_MULTIPLIER_8  = 0x180000,
    PLL_MULTIPLIER_9  = 0x1C0000,
    PLL_MULTIPLIER_10 = 0x200000,
    PLL_MULTIPLIER_11 = 0x240000,
    PLL_MULTIPLIER_12 = 0x280000,
    PLL_MULTIPLIER_13 = 0x2C0000,
    PLL_MULTIPLIER_14 = 0x300000,
    PLL_MULTIPLIER_15 = 0x340000,
    PLL_MULTIPLIER_16 = 0x380000
} PLL_MULTIPLIER;

typedef enum {
	AHB_PRESCALER_1   = 0x00,
	AHB_PRESCALER_2   = 0x80,
	AHB_PRESCALER_4   = 0x90,
	AHB_PRESCALER_8   = 0xA0,
	AHB_PRESCALER_16  = 0xB0,
	AHB_PRESCALER_64  = 0xC0,
	AHB_PRESCALER_128 = 0xD0,
	AHB_PRESCALER_256 = 0xE0,
	AHB_PRESCALER_512 = 0xF0
} AHB_PRESCALER;

typedef enum {
	APB_PRESCALER_1  = 0x000,
	APB_PRESCALER_2  = 0x400,
	APB_PRESCALER_4  = 0x500,
	APB_PRESCALER_8  = 0x600,
	APB_PRESCALER_16 = 0x700,
} APB_PRESCALER;

static inline void PLL_SET_APB1_PRESCALER(APB_PRESCALER prescaler) {
	RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_PPRE1_MASK) | prescaler;
}

static inline void PLL_SET_APB2_PRESCALER(APB_PRESCALER prescaler) {
	RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_PPRE2_MASK) | (prescaler << 3);
}

static inline void PLL_SET_AHB_PRESCALER(AHB_PRESCALER prescaler) {
	RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_HPRE_MASK) | prescaler;
}

static inline void PLL_SET_MULTIPLIER(PLL_MULTIPLIER multiplier) {
	RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_PLLMUL_MASK) | multiplier;
}

static inline void PLL_ENABLE_HSE_DIVIDER() {
	RCC->CFGR |= RCC_CFGR_PLLXTPRE_MASK;
}

static inline void PLL_DISABLE_HSE_DIVIDER() {
	RCC->CFGR &= ~RCC_CFGR_PLLXTPRE_MASK;
}

static inline void PLL_SET_CLOCK_SOURCE_HSI() {
	RCC->CFGR &= ~RCC_CFGR_PLLSRC_MASK;
}

static inline void PLL_SET_CLOCK_SOURCE_HSE() {
	RCC->CFGR |= RCC_CFGR_PLLSRC_MASK;
}

// flash latency for higher frequencies
typedef enum {
	FLASH_ACCESS_CONFIG_ZERO_WAIT_STATES_PREFETCH_OFF = 0x00,
	FLASH_ACCESS_CONFIG_ZERO_WAIT_STATES_PREFETCH_ON  = 0x10,
	FLASH_ACCESS_CONFIG_ONE_WAIT_STATES_PREFETCH_OFF  = 0x01,
	FLASH_ACCESS_CONFIG_ONE_WAIT_STATES_PREFETCH_ON   = 0x11,
	FLASH_ACCESS_CONFIG_TWO_WAIT_STATES_PREFETCH_OFF  = 0x02,
	FLASH_ACCESS_CONFIG_TWO_WAIT_STATES_PREFETCH_ON   = 0x12,
} FLASH_ACCESS_CONFIG;

static inline void SET_FLASH_ACCESS_CONFIG(FLASH_ACCESS_CONFIG config) {
	FLASH->ACR = (FLASH->ACR & ~FLASH_ACR_CFG_MASK) | config;
}

#endif /* GOOFYHAL_STM32F1XX_DRIVERS_CLOCK_H_ */
