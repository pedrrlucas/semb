/****************************************************************************
 * stm32/inc/stm32f411_memmap.h
 *
 *   Authors: Daniel Pereira de Carvalho <daniel.carvalho@ufu.br>
 *
 ****************************************************************************/

#ifndef __STM32_INC_STM32F411_MEMMAP_H
#define __STM32_INC_STM32F411_MEMMAP_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/
 
/* STM32F411xC/xE register boundary addresses */
#define STM32_TIM2_BASE       0x40000000 /* 0x40000000-0x400003ff: Timer 2 */
#define STM32_TIM3_BASE       0x40000400 /* 0x40000400-0x400007ff: Timer 3 */
#define STM32_TIM4_BASE       0x40000800 /* 0x40000800-0x40000bff: Timer 4 */
#define STM32_TIM5_BASE       0x40000c00 /* 0x40000c00-0x40000fff: Timer 5 */
#define STM32_RTC_BASE        0x40002800 /* 0x40002800-0x40002bff: Reset and Clock control RCC */
#define STM32_WWDG_BASE       0x40002c00 /* 0x40002c00-0x40002fff: Window watchdog */
#define STM32_IWDG_BASE       0x40003000 /* 0x40003000-0x400033ff: Independent watchdog */

#define STM32_GPIOA_BASE      0x40020000 /* 0x40020000-0x400203ff: GPIO port A */
#define STM32_GPIOB_BASE      0x40020400 /* 0x40020400-0x400207ff: GPIO port B */
#define STM32_GPIOC_BASE      0x40020800 /* 0x40020800-0x40020bff: GPIO port C */
#define STM32_GPIOD_BASE      0x40020c00 /* 0x40020c00-0x40020fff: GPIO port D */
#define STM32_GPIOE_BASE      0x40021000 /* 0x40021000-0x400213ff: GPIO port E */
#define STM32_GPIOH_BASE      0x40021c00 /* 0x40021c00-0x40021fff: GPIO port H */

#define STM32_RCC_BASE        0x40023800 /* 0x40023800-0x40023bff: Reset and Clock control RCC */

#endif /* __STM32_INC_STM32F411_MEMMAP_H */