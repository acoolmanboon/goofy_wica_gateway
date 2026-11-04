#include <stdint.h>

#define _BIT_MASK(n) (1U << (n))
#define _FIELD_MASK(width, pos) (((1U << (width)) - 1U) << (pos)) // this is lowkey genius
typedef struct
{
    volatile uint32 CR;
    volatile uint32 CFGR;
    volatile uint32 CIR;
    volatile uint32 APB2RSTR;
    volatile uint32 APB1RSTR;
    volatile uint32 AHBENR;
    volatile uint32 APB2ENR;
    volatile uint32 APB1ENR;
    volatile uint32 BDCR;
    volatile uint32 CSR;
    volatile uint32 AHBSTR;
    volatile uint32 CFGR2;
} RCC_REGISTER_MAP;

#define RCC ((RCC_REGISTER_MAP *)0x40021000UL)

// Clock control register
#define RCC_CR_HSION_OFFSET 0U
#define RCC_CR_HSION_MASK _BIT_MASK(RCC_CR_HSION_OFFSET)

#define RCC_CR_HSIRDY_OFFSET 1U
#define RCC_CR_HSIRDY_MASK _BIT_MASK(RCC_CR_HSIRDY_OFFSET)

#define RCC_CR_HSEON_OFFSET 16U // High Speed External Clock Enable
#define RCC_CR_HSEON_MASK _BIT_MASK(RCC_CR_HSEON_OFFSET)

#define RCC_CR_HSERDY_OFFSET 17U // High Speed External Clock Ready Flag
#define RCC_CR_HSERDY_MASK _BIT_MASK(RCC_CR_HSERDY_OFFSET)

#define RCC_CR_HSEBYP_OFFSET 18U // High Speed External Clock Bypass
#define RCC_CR_HSEBYP_MASK _BIT_MASK(RCC_CR_HSEBYP_OFFSET)

#define RCC_CR_CSSON_OFFSET 19U
#define RCC_CR_CSSON_MASK _BIT_MASK(RCC_CR_CSSON_OFFSET)

#define RCC_CR_PLLON_OFFSET 24U
#define RCC_CR_PLLON_MASK _BIT_MASK(RCC_CR_PLLON_OFFSET)

#define RCC_CR_PLLRDY_OFFSET 25U
#define RCC_CR_PLLRDY_MASK _BIT_MASK(RCC_CR_PLLRDY_OFFSET)

// Clock Configuration Register
#define RCC_CFGR_SW_OFFSET 0U
#define RCC_CFGR_SW_MASK _FIELD_MASK(RCC_CFGR_SW_OFFSET, 2)
#define RCC_CFGR_SW_HSI 0x00
#define RCC_CFGR_SW_HSE 0x01
#define RCC_CFGR_SW_PLL 0x02

#define RCC_CFGR_SWS_OFFSET 2U
#define RCC_CFGR_SWS_MASK _FIELD_MASK(RCC_CFGR_SWS_OFFSET, 2)
#define RCC_CFGR_SWS_HSI 0x00
#define RCC_CFGR_SWS_HSE 0x01
#define RCC_CFGR_SWS_PLL 0x02

// Backup Domain Control Register


// APB1 peripheral clock enable register
#define RCC_APB1ENR_PWREN_OFFSET 28U
#define RCC_APB1ENR_PWREN_MASK (1U << RCC_APB1ENR_PWREN_OFFSET)

