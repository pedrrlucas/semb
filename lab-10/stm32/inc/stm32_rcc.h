/****************************************************************************
 * stm32/inc/stm32_rcc.h
 *
 *   Authors: Daniel Pereira de Carvalho <daniel.carvalho@ufu.br>
 *
 ****************************************************************************/

#ifndef __STM32_INC_STM32_RCC_H
#define __STM32_INC_STM32_RCC_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include "stm32f411_rcc.h"

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

/**
 * @brief Enable AHB1 peripheral clock.
 * @param peripheral The peripheral to enable (e.g., RCC_AHB1ENR_GPIOCEN).
 * @return true if the peripheral clock was enabled, false if it was already enabled.
 */
bool stm32_rcc_enableahb1(uint32_t peripheral);

/**
 * @brief Disable AHB1 peripheral clock.
 * @param peripheral The peripheral to disable (e.g., RCC_AHB1ENR_GPIOCEN).
 * @return true if the peripheral clock was disabled, false if it was already disabled.
 */
bool stm32_rcc_disableahb1(uint32_t peripheral);

#endif /* __STM32_INC_STM32_RCC_H */