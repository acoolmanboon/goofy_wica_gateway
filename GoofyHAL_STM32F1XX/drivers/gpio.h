/*
 * gpio.h
 *
 *  Created on: Nov 4, 2026
 *      Author: acoolmanboon
 */

#ifndef GOOFYHAL_STM32F1XX_DRIVERS_GPIO_H_
#define GOOFYHAL_STM32F1XX_DRIVERS_GPIO_H_

#include "../register_map.h"
#include "../config.h"

#ifdef GOOFYHAL_DEBUG_GPIO
#include <stdio.h>
#endif

typedef enum {
	IO_PORT_A = 2,
	IO_PORT_B = 3,
	IO_PORT_C = 4,
	IO_PORT_D = 5,
	IO_PORT_E = 6,
	IO_PORT_F = 7,
	IO_PORT_G = 8,
} IO_PORT;

typedef enum {
	IO_PORT_MODE_INPUT = 0x00,
	IO_PORT_MODE_OUTPUT_10MHZ = 0x01,
	IO_PORT_MODE_OUTPUT_2MHZ = 0x02,
	IO_PORT_MODE_OUTPUT_50MHZ = 0x03,
} IO_PORT_MODE;

typedef enum {
	IO_PORT_CONFIG_INPUT_ANALOG = 0x00,
	IO_PORT_CONFIG_INPUT_FLOATING = 0x04,
	IO_PORT_CONFIG_INPUT_PULL = 0x08,

	IO_PORT_CONFIG_OUTPUT_PUSH_PULL = 0x00,
	IO_PORT_CONFIG_OUTPUT_OPEN_DRAIN = 0x04,
	IO_PORT_CONFIG_OUTPUT_ALTERNATE_PUSH_PULL = 0x08,
	IO_PORT_CONFIG_OUTPUT_ALTERNATE_OPEN_DRAIN = 0x0C,
} IO_PORT_CONFIG;

static inline void ENABLE_IO_PORT(IO_PORT port) {
	RCC->APB2ENR |= (1U << port);
}

static inline void DISABLE_IO_PORT(IO_PORT port) {
	RCC->APB2ENR &= ~(1U << port);
}

static inline void SETUP_IO_PORT(IO_PORT port, uint8_t pin, IO_PORT_MODE mode, IO_PORT_CONFIG config) {
#ifdef GOOFYHAL_DEBUG_GPIO
	if (!(RCC->APB2ENR & (1U << port))) {
		printf("Tried to setup IO pin of port %c but it is not enabled, enabling now. \n\r", port + 65);
		ENABLE_IO_PORT(port);
	}
#endif

	GPIO_REGISTER_MAP* gpioRegister = (GPIO_REGISTER_MAP*)(0x40010000UL + (0x400UL * port));
	if (pin < 8) {
		gpioRegister->CRL = (gpioRegister->CRL & ~(0x0F << (pin << 2))) | ((mode | config) << (pin << 2));
	} else {
		gpioRegister->CRH = (gpioRegister->CRH & ~(0x0F << ((pin - 8) << 2))) | ((mode | config) << ((pin - 8) << 2));
	}

}
#endif
