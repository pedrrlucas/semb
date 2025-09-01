/****************************************************************************
 * bsp/src/bsp.c
 *
 *   Authors: Daniel Pereira de Carvalho <daniel.carvalho@ufu.br>
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <stdint.h>

#include "bsp.h"

#include "stm32_gpio.h"
#include "stm32_rcc.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Public Variables
 ****************************************************************************/

/* Digital IO pin mapping */
uint32_t pin_map[MAX_DIGITAL_IO] =
{
  0,                       /* D0 - Not compatible with Arduino */
  0,                       /* D1 - Not compatible with Arduino */
  GPIO_PORTC | GPIO_PIN13, /* D2 */
  GPIO_PORTB | GPIO_PIN3,  /* D3 */
  GPIO_PORTB | GPIO_PIN5,  /* D4 */
  GPIO_PORTA | GPIO_PIN0,  /* D5 */
  GPIO_PORTB | GPIO_PIN10, /* D6 */
  GPIO_PORTA | GPIO_PIN8,  /* D7 */
  GPIO_PORTA | GPIO_PIN9,  /* D8 */
  0,                       /* D9 - Not compatible with Arduino */
  GPIO_PORTB | GPIO_PIN6,  /* D10 */
  GPIO_PORTA | GPIO_PIN7,  /* D11 */
  GPIO_PORTA | GPIO_PIN6,  /* D12 */
  GPIO_PORTA | GPIO_PIN5,  /* D13 */
  GPIO_PORTB | GPIO_PIN9,  /* D14 */
  GPIO_PORTB | GPIO_PIN8   /* D15 */
};

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

void bsp_init(void)
{
  /* Enable AHB1 peripherals */
  stm32_rcc_enableahb1(RCC_AHB1ENR_GPIOCEN);
}
