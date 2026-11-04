#include <stdio.h>

#include "idk.h"
#include "main.h"
// i will proceed to torture myself by attempting to now make a blinking LED with no HAL
// im gonna keep the files just in case i mess up and for peace of mind i guess

// update never mind i am literally just making a HAL from scratch

int main(void)
{    
	RCC->CR |= RCC_CR_HSEON_MASK; // Enable the HSE flag
	while (!(RCC->CR & RCC_CR_HSERDY_MASK)); // Wait for the HSE to be ready

	RCC->CFGR &= ~(RCC_CFGR_SW_MASK); // clear the SW register
	RCC->CFGR |= (RCC_CFGR_SW_HSE << RCC_CFGR_SW_OFFSET); // set the SW register to use HSE
	while(((RCC->CFGR & RCC_CFGR_SW_OFFSET) >> RCC_CFGR_SW_MASK) != RCC_CFGR_SWS_HSE) // wait for HSE to be used


	while (1) {

	}
}
