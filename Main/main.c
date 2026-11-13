#include <stdio.h>

#include "main.h"

#include "../GoofyHAL_STM32F1XX/include.h"

#define IDK_PORT IO_PORT_B // this is because the devboard has the KEY and LED both on the same port
#define LED_PIN 11
#define KEY_PIN 12

#define USART_PORT IO_PORT_A
#define USART_TX_PIN 9
#define USART_RX_PIN 10

void USART1_Write(char ch) {
    while (!(USART1->SR & USART_SR_TXE_Msk));
    USART1->DR = (ch & 0xFF);
}

void USART1_SendString(char *str) {
    while (*str) {
        USART1_Write(*str++);
    }
}

void USART1_IRQHandler(void) {
    if (USART1->SR & USART_SR_RXNE) {
        uint8_t received_data = USART1->DR;
        USART1_Write(received_data);
    }
}


int main(void)
{    
	// Setup HSE to be used as PLL to set a 72MHz clock
	ENABLE_OSCILLATOR(CLOCK_OSCILLATOR_OFFSET_HSE);

	PLL_CONFIGURE(
			APB_PRESCALER_2,
			APB_PRESCALER_1,
			AHB_PRESCALER_1,
			PLL_MULTIPLIER_9,
			PLL_CLOCK_SOURCE_HSE,
			PLL_HSE_DIVIDER_1
	);

	SET_FLASH_ACCESS_CONFIG(FLASH_ACCESS_CONFIG_TWO_WAIT_STATES_PREFETCH_ON);

	ENABLE_OSCILLATOR(CLOCK_OSCILLATOR_OFFSET_PLL);
	SWITCH_SYSTEM_CLOCK(CLOCK_OSCILLATOR_PLL);

	// enable the debugging ports

	ENABLE_IO_PORT(IDK_PORT); // ENABLE GPIOB
	SETUP_IO_PORT(IDK_PORT, LED_PIN, IO_PORT_MODE_OUTPUT_2MHZ, IO_PORT_CONFIG_OUTPUT_PUSH_PULL);
	SETUP_IO_PORT(IDK_PORT, KEY_PIN, IO_PORT_MODE_INPUT, IO_PORT_CONFIG_INPUT_PULL_UP);

	WRITE_IO_PORT(IDK_PORT, LED_PIN);

	// setup USART and send text

	ENABLE_IO_PORT(USART_PORT);
	SETUP_IO_PORT(USART_PORT, USART_TX_PIN, IO_PORT_MODE_OUTPUT_50MHZ, IO_PORT_CONFIG_OUTPUT_ALTERNATE_PUSH_PULL);
	SETUP_IO_PORT(USART_PORT, USART_RX_PIN, IO_PORT_MODE_INPUT, IO_PORT_CONFIG_INPUT_FLOATING);

	POWER_ON_USART();
	SET_USART_BAUD_RATE_RAW(0x271); // 115200 baud

	ENABLE_USART();
	ENABLE_USART_TRANSMITTER();
	ENABLE_USART_RECEIVER();

	USART1->CR1 |= USART_CR1_RXNEIE;
	NVIC_EnableIRQ(USART1_IRQn);

	USART1_SendString("Hello, senpai.. HUH?! WHAT? Me- Liking YOU?! HMPH! Seriously? You really think I would like a BAKA like you? W-What? O-Okay.. Fine.. Maybe I do like you a little bit, baka. BUT NOT THAT MUCH!! \n\r");

	// test function : turn a LED on when you press the key
	while (1) {
		if (READ_IO_PORT(IDK_PORT, KEY_PIN)) {
			CLEAR_IO_PORT(IDK_PORT, LED_PIN);
		} else {
			WRITE_IO_PORT(IDK_PORT, LED_PIN);
		}
	}
}
