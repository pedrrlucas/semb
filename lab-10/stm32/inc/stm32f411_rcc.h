/****************************************************************************
 * stm32/inc/stm32f411_rcc.h
 *
 *   Authors: Daniel Pereira de Carvalho <daniel.carvalho@ufu.br>
 *
 ****************************************************************************/

#ifndef __STM32_INC_STM32F411_RCC_H
#define __STM32_INC_STM32F411_RCC_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include "stm32f411_memmap.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Register Offsets *********************************************************/
#define STM32_RCC_CR_OFFSET         0x0000 /* Clock control register */
#define STM32_RCC_PLLCFGR_OFFSET    0x0004 /* PLL configuration register */
#define STM32_RCC_CFGR_OFFSET       0x0008 /* Clock configuration register */
#define STM32_RCC_CIR_OFFSET        0x000c /* Clock interrupt register */
#define STM32_RCC_AHB1RSTR_OFFSET   0x0010 /* AHB1 peripheral reset register */
#define STM32_RCC_AHB2RSTR_OFFSET   0x0014 /* AHB2 peripheral reset register */
#define STM32_RCC_APB1RSTR_OFFSET   0x0020 /* APB1 peripheral reset register */
#define STM32_RCC_APB2RSTR_OFFSET   0x0024 /* APB2 peripheral reset register */
#define STM32_RCC_AHB1ENR_OFFSET    0x0030 /* AHB1 Peripheral Clock enable register */
#define STM32_RCC_AHB2ENR_OFFSET    0x0034 /* AHB2 Peripheral Clock enable register */
#define STM32_RCC_APB1ENR_OFFSET    0x0040 /* APB1 Peripheral Clock enable register */
#define STM32_RCC_APB2ENR_OFFSET    0x0044 /* APB2 Peripheral Clock enable register */
#define STM32_RCC_AHB1LPENR_OFFSET  0x0050 /* AHB1 Peripheral Clock enable in low power mode register */
#define STM32_RCC_AHB2LPENR_OFFSET  0x0054 /* AHB2 Peripheral Clock enable in low power mode register */
#define STM32_RCC_APB1LPENR_OFFSET  0x0060 /* APB1 Peripheral Clock enable in low power mode register */
#define STM32_RCC_APB2LPENR_OFFSET  0x0064 /* APB2 Peripheral Clock enable in low power mode register */
#define STM32_RCC_BDCR_OFFSET       0x0070 /* Backup domain control register */
#define STM32_RCC_CSR_OFFSET        0x0074 /* Control/status register */
#define STM32_RCC_SSCGR_OFFSET      0x0080 /* Spread spectrum clock generation register */
#define STM32_RCC_PLLI2SCFGR_OFFSET 0x0084 /* PLLI2S configuration register */
#define STM32_RCC_DCKCFGR_OFFSET    0x008c /* Dedicated clock configuration register */

/* Register Addresses *******************************************************/
#define RCC_CR         (STM32_RCC_BASE + STM32_RCC_CR_OFFSET)
#define RCC_PLLCFGR    (STM32_RCC_BASE + STM32_RCC_PLLCFGR_OFFSET)
#define RCC_CFGR       (STM32_RCC_BASE + STM32_RCC_CFGR_OFFSET)
#define RCC_CIR        (STM32_RCC_BASE + STM32_RCC_CIR_OFFSET)
#define RCC_AHB1RSTR   (STM32_RCC_BASE + STM32_RCC_AHB1RSTR_OFFSET)
#define RCC_AHB2RSTR   (STM32_RCC_BASE + STM32_RCC_AHB2RSTR_OFFSET)
#define RCC_APB1RSTR   (STM32_RCC_BASE + STM32_RCC_APB1RSTR_OFFSET)
#define RCC_APB2RSTR   (STM32_RCC_BASE + STM32_RCC_APB2RSTR_OFFSET)
#define RCC_AHB1ENR    (STM32_RCC_BASE + STM32_RCC_AHB1ENR_OFFSET)
#define RCC_AHB2ENR    (STM32_RCC_BASE + STM32_RCC_AHB2ENR_OFFSET)
#define RCC_APB1ENR    (STM32_RCC_BASE + STM32_RCC_APB1ENR_OFFSET)
#define RCC_APB2ENR    (STM32_RCC_BASE + STM32_RCC_APB2ENR_OFFSET)
#define RCC_AHB1LPENR  (STM32_RCC_BASE + STM32_RCC_AHB1LPENR_OFFSET)
#define RCC_AHB2LPENR  (STM32_RCC_BASE + STM32_RCC_AHB2LPENR_OFFSET)
#define RCC_APB1LPENR  (STM32_RCC_BASE + STM32_RCC_APB1LPENR_OFFSET)
#define RCC_APB2LPENR  (STM32_RCC_BASE + STM32_RCC_APB2LPENR_OFFSET)
#define RCC_BDCR       (STM32_RCC_BASE + STM32_RCC_BDCR_OFFSET)
#define RCC_CSR        (STM32_RCC_BASE + STM32_RCC_CSR_OFFSET)
#define RCC_SSCGR      (STM32_RCC_BASE + STM32_RCC_SSCGR_OFFSET)
#define RCC_PLLI2SCFGR (STM32_RCC_BASE + STM32_RCC_PLLI2SCFGR_OFFSET)
#define RCC_DCKCFGR    (STM32_RCC_BASE + STM32_RCC_DCKCFGR_OFFSET)

/* Register Bitfield Definitions ********************************************/

/* Clock control register */
#define RCC_CR_HSION          (1 << 0)  /* Bit 0: HSI clock enable */
#define RCC_CR_HSIRDY         (1 << 1)  /* Bit 1: HSI clock ready flag */
#define RCC_CR_HSEON          (1 << 16) /* Bit 16: HSE clock enable */
#define RCC_CR_HSERDY         (1 << 17) /* Bit 17: HSE clock ready flag */
#define RCC_CR_PLLON          (1 << 24) /* Bit 24: PLL clock enable */
#define RCC_CR_PLLRDY         (1 << 25) /* Bit 25: PLL clock ready flag */

/* AHB1 peripheral clock enable register */
#define RCC_AHB1ENR_GPIOAEN      (1 << 0)  /* Bit 0:  IO port A clock enable */
#define RCC_AHB1ENR_GPIOBEN      (1 << 1)  /* Bit 1:  IO port B clock enable */
#define RCC_AHB1ENR_GPIOCEN      (1 << 2)  /* Bit 2:  IO port C clock enable */
#define RCC_AHB1ENR_GPIODEN      (1 << 3)  /* Bit 3:  IO port D clock enable */
#define RCC_AHB1ENR_GPIOEEN      (1 << 4)  /* Bit 4:  IO port E clock enable */
#define RCC_AHB1ENR_GPIOHEN      (1 << 7)  /* Bit 7:  IO port H clock enable */
#define RCC_AHB1ENR_CRCEN        (1 << 12) /* Bit 12: CRC clock enable */
#define RCC_AHB1ENR_DMA1EN       (1 << 21) /* Bit 21: DMA1 clock enable */
#define RCC_AHB1ENR_DMA2EN       (1 << 22) /* Bit 22: DMA2 clock enable */

#endif /* __STM32_INC_STM32F411_RCC_H */