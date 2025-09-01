/****************************************************************************
 * stm32/inc/stm32f411_gpio.h
 *
 *   Authors: Daniel Pereira de Carvalho <daniel.carvalho@ufu.br>
 *
 ****************************************************************************/

#ifndef __STM32_INC_STM32F411_GPIO_H
#define __STM32_INC_STM32F411_GPIO_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include "stm32f411_memmap.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Register Offsets *********************************************************/
#define STM32_GPIO_MODER_OFFSET   0x0000 /* GPIO port mode register */
#define STM32_GPIO_OTYPER_OFFSET  0x0004 /* GPIO port output type register */
#define STM32_GPIO_OSPEEDR_OFFSET 0x0008 /* GPIO port output speed register */
#define STM32_GPIO_PUPDR_OFFSET   0x000c /* GPIO port pull-up/pull-down register */
#define STM32_GPIO_IDR_OFFSET     0x0010 /* GPIO port input data register */
#define STM32_GPIO_ODR_OFFSET     0x0014 /* GPIO port output data register */
#define STM32_GPIO_BSRR_OFFSET    0x0018 /* GPIO port bit set/reset register */
#define STM32_GPIO_LOCKR_OFFSET   0x001c /* GPIO port configuration lock register */
#define STM32_GPIO_AFRL_OFFSET    0x0020 /* GPIO alternate function low register */
#define STM32_GPIO_AFRH_OFFSET    0x0024 /* GPIO alternate function high register */

/* Register Addresses *******************************************************/
#define STM32_GPIOA_MODER       (STM32_GPIOA_BASE + STM32_GPIO_MODER_OFFSET)
#define STM32_GPIOA_OTYPER      (STM32_GPIOA_BASE + STM32_GPIO_OTYPER_OFFSET)
#define STM32_GPIOA_OSPEEDR     (STM32_GPIOA_BASE + STM32_GPIO_OSPEEDR_OFFSET)
#define STM32_GPIOA_PUPDR       (STM32_GPIOA_BASE + STM32_GPIO_PUPDR_OFFSET)
#define STM32_GPIOA_IDR         (STM32_GPIOA_BASE + STM32_GPIO_IDR_OFFSET)
#define STM32_GPIOA_ODR         (STM32_GPIOA_BASE + STM32_GPIO_ODR_OFFSET)
#define STM32_GPIOA_BSRR        (STM32_GPIOA_BASE + STM32_GPIO_BSRR_OFFSET)
#define STM32_GPIOA_LOCKR       (STM32_GPIOA_BASE + STM32_GPIO_LOCKR_OFFSET)
#define STM32_GPIOA_AFRL        (STM32_GPIOA_BASE + STM32_GPIO_AFRL_OFFSET)
#define STM32_GPIOA_AFRH        (STM32_GPIOA_BASE + STM32_GPIO_AFRH_OFFSET)

#define STM32_GPIOB_MODER       (STM32_GPIOB_BASE + STM32_GPIO_MODER_OFFSET)
#define STM32_GPIOB_OTYPER      (STM32_GPIOB_BASE + STM32_GPIO_OTYPER_OFFSET)
#define STM32_GPIOB_OSPEEDR     (STM32_GPIOB_BASE + STM32_GPIO_OSPEEDR_OFFSET)
#define STM32_GPIOB_PUPDR       (STM32_GPIOB_BASE + STM32_GPIO_PUPDR_OFFSET)
#define STM32_GPIOB_IDR         (STM32_GPIOB_BASE + STM32_GPIO_IDR_OFFSET)
#define STM32_GPIOB_ODR         (STM32_GPIOB_BASE + STM32_GPIO_ODR_OFFSET)
#define STM32_GPIOB_BSRR        (STM32_GPIOB_BASE + STM32_GPIO_BSRR_OFFSET)
#define STM32_GPIOB_LOCKR       (STM32_GPIOB_BASE + STM32_GPIO_LOCKR_OFFSET)
#define STM32_GPIOB_AFRL        (STM32_GPIOB_BASE + STM32_GPIO_AFRL_OFFSET)
#define STM32_GPIOB_AFRH        (STM32_GPIOB_BASE + STM32_GPIO_AFRH_OFFSET)

#define STM32_GPIOC_MODER       (STM32_GPIOC_BASE + STM32_GPIO_MODER_OFFSET)
#define STM32_GPIOC_OTYPER      (STM32_GPIOC_BASE + STM32_GPIO_OTYPER_OFFSET)
#define STM32_GPIOC_OSPEEDR     (STM32_GPIOC_BASE + STM32_GPIO_OSPEEDR_OFFSET)
#define STM32_GPIOC_PUPDR       (STM32_GPIOC_BASE + STM32_GPIO_PUPDR_OFFSET)
#define STM32_GPIOC_IDR         (STM32_GPIOC_BASE + STM32_GPIO_IDR_OFFSET)
#define STM32_GPIOC_ODR         (STM32_GPIOC_BASE + STM32_GPIO_ODR_OFFSET)
#define STM32_GPIOC_BSRR        (STM32_GPIOC_BASE + STM32_GPIO_BSRR_OFFSET)
#define STM32_GPIOC_LOCKR       (STM32_GPIOC_BASE + STM32_GPIO_LOCKR_OFFSET)
#define STM32_GPIOC_AFRL        (STM32_GPIOC_BASE + STM32_GPIO_AFRL_OFFSET)
#define STM32_GPIOC_AFRH        (STM32_GPIOC_BASE + STM32_GPIO_AFRH_OFFSET)

/* Register Bitfield Definitions ***************************************/

/* GPIO port mode register */
#define GPIO_MODER_INPUT         (0x0)      /* Input mode */
#define GPIO_MODER_OUTPUT        (0x1)      /* Output mode */
#define GPIO_MODER_ALT           (0x2)      /* Alternate function mode */
#define GPIO_MODER_ANALOG        (0x3)      /* Analog mode */

#define GPIO_MODER_SHIFT(n)      (n * 2)
#define GPIO_MODER_MASK(n)       (3 << GPIO_MODER_SHIFT(n))

/* GPIO port output type register */
#define GPIO_OTYPER_PP           (0x0)      /* Output push-pull */
#define GPIO_OTYPER_OD           (0x1)      /* Output open-drain */

#define GPIO_OTYPER_SHIFT(n)     (n)
#define GPIO_OTYPER_MASK(n)      (1 << GPIO_OTYPER_SHIFT(n))

/* GPIO port output speed register */
#define GPIO_OSPEEDR_LOW         (0x0)      /* Low speed */
#define GPIO_OSPEEDR_MEDIUM      (0x1)      /* Medium speed */
#define GPIO_OSPEEDR_FAST        (0x2)      /* Fast speed */
#define GPIO_OSPEEDR_HIGH        (0x3)      /* High speed */

#define GPIO_OSPEEDR_SHIFT(n)    (n * 2)
#define GPIO_OSPEEDR_MASK(n)     (3 << GPIO_OSPEEDR_SHIFT(n))

/* GPIO port pull-up/pull-down register */
#define GPIO_PUPDR_NONE          (0x0)      /* No pull-up, pull-down */
#define GPIO_PUPDR_PULLUP        (0x1)      /* Pull-up */
#define GPIO_PUPDR_PULLDOWN      (0x2)      /* Pull-down */

#define GPIO_PUPDR_SHIFT(n)      (n * 2)
#define GPIO_PUPDR_MASK(n)       (3 << GPIO_PUPDR_SHIFT(n))

/* GPIO port input data register */
#define GPIO_IDR_SHIFT(n)        (n)
#define GPIO_IDR_MASK(n)         (1 << GPIO_IDR_SHIFT(n))

/* GPIO port output data register */
#define GPIO_ODR_SHIFT(n)        (n)
#define GPIO_ODR_MASK(n)         (1 << GPIO_ODR_SHIFT(n))

/* GPIO port bit set/reset register */
#define GPIO_BSRR_SET(n)         (1 << (n))        /* Bit set */
#define GPIO_BSRR_RESET(n)       (1 << ((n) + 16)) /* Bit reset */

#endif /* __STM32_INC_STM32F411_GPIO_H */