/****************************************************************************
 * stm32/src/stm32_rcc.c
 *
 *   Authors: Daniel Pereira de Carvalho <daniel.carvalho@ufu.br>
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <stdbool.h>
#include <stdint.h>

#include "stm32_rcc.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define getreg32(a)    (*(volatile uint32_t *)(a))
#define putreg32(v, a) (*(volatile uint32_t *)(a) = (v))

/****************************************************************************
 * Public Functions
 ****************************************************************************/
/**
 * @brief Enable AHB1 peripheral clock.
 * @param peripheral The peripheral to enable (e.g., RCC_AHB1ENR_GPIOCEN).
 * @return true if the peripheral clock was enabled, false if it was already enabled.
 */
bool stm32_rcc_enableahb1(uint32_t peripherals)
{
  uint32_t regval;

  /* Read the current AHB1ENR register value */
  regval = getreg32(RCC_AHB1ENR);

  /* Enable the specified peripheral clock */
  regval |= peripherals;
  putreg32(regval, RCC_AHB1ENR);

  return true;
}

/**
 * @brief Disable AHB1 peripheral clock.
 * @param peripheral The peripheral to disable (e.g., RCC_AHB1ENR_GPIOCEN).
 * @return true if the peripheral clock was disabled, false if it was already disabled.
 */
bool stm32_rcc_disableahb1(uint32_t peripherals)
{
  uint32_t regval;

  /* Read the current AHB1ENR register value */
  regval = getreg32(RCC_AHB1ENR);

  /* Disable the specified peripheral clock */
  regval &= ~peripherals;
  putreg32(regval, RCC_AHB1ENR);

  return true;
}