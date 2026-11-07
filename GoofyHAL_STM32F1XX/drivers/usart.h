/*
 * usart.h
 *
 *  Created on: Nov 7, 2026
 *      Author: User
 */

#ifndef GOOFYHAL_STM32F1XX_DRIVERS_USART_H_
#define GOOFYHAL_STM32F1XX_DRIVERS_USART_H_

#include "../includes/stm32f103xb.h"
#include "../config.h"
#include <stdint.h>

static inline void POWER_ON_USART() {
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN_Msk;
}

static inline void POWER_OFF_USART() {
	RCC->APB2ENR &= ~RCC_APB2ENR_USART1EN_Msk;
}

static inline void ENABLE_USART() {
	USART1->CR1 |= USART_CR1_UE_Msk;
}

static inline void DISABLE_USART() {
	USART1->CR1 &= ~USART_CR1_UE_Msk;
}

static inline void SET_USART_BAUD_RATE_RAW(uint32_t raw) {
	USART1->BRR = raw;
}


#endif /* GOOFYHAL_STM32F1XX_DRIVERS_USART_H_ */
