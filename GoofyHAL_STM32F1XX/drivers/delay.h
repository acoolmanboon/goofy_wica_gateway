/*
 * delay.h
 *
 *  Created on: Nov 13, 2026
 *      Author: User
 */

#ifndef GOOFYHAL_STM32F1XX_DRIVERS_DELAY_H_
#define GOOFYHAL_STM32F1XX_DRIVERS_DELAY_H_


void SYSTICK_INIT(unsigned long int frequency)
{
    SysTick->CTRL = 0;
    SysTick->LOAD = (frequency / 1000000UL) - 1;
    SysTick->VAL = 0;

    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk;
}

void SYSTICK_DELAY_US(uint32_t us)
{
    while (us--)
    {
        while (!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));
    }
}

void SYSTICK_DELAY_MS(uint32_t ms)
{
    while (ms--)
    {
    	SYSTICK_DELAY_US(1000);
    }
}

#endif /* GOOFYHAL_STM32F1XX_DRIVERS_DELAY_H_ */
