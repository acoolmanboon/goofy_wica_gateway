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

#endif /* GOOFYHAL_STM32F1XX_DRIVERS_CLOCK_H_ */
