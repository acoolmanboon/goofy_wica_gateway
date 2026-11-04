#include <stdio.h>

#include "main.h"

#include "../GoofyHAL_STM32F1XX/include.h"
// i will proceed to torture myself by attempting to now make a blinking LED with no HAL
// im gonna keep the files just in case i mess up and for peace of mind i guess

// update never mind i am literally just making a HAL from scratch

int main(void)
{    
	// enable clock to use 8MHZ crystal
	RCC->CR |= RCC_CR_HSEON_MASK; // Enable the HSE flag
	while (!(RCC->CR & RCC_CR_HSERDY_MASK)); // Wait for the HSE to be ready

	RCC->CFGR &= ~(RCC_CFGR_SW_MASK); // clear the SW register
	RCC->CFGR |= (HSE << RCC_CFGR_SW_OFFSET); // set the SW register to use HSE
	while (((RCC->CFGR & RCC_CFGR_SWS_MASK) >> RCC_CFGR_SWS_OFFSET) != HSE); // wait for HSE to be used

	// enable GPIO B port
	RCC->APB2ENR |= RCC_APB2ENR_IOBCEN_MASK; // ENable the APB2 port B to use it

	// configure GPIO PB11
	GPIOB->CRH &= ~GPIO_CRH_PORT11_MASK;
	GPIOB->CRH |= (0x02U << GPIO_CRH_PORT11_OFFSET);

	// FUCK it im gonna just set the bit manually
	GPIOB->BSRR |= (1 << 11);

	while (1) {

	}
}
