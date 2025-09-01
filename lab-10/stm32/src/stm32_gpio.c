/****************************************************************************
 * stm32/src/stm32_gpio.c
 *
 *   Authors: Daniel Pereira de Carvalho <daniel.carvalho@ufu.br>
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <stdbool.h>
#include <stdint.h>

#include "stm32_gpio.h"
#include "stm32f411_gpio.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define getreg32(a)    (*(volatile uint32_t *)(a))
#define putreg32(v, a) (*(volatile uint32_t *)(a) = (v))

/****************************************************************************
 * Private Variables
 ****************************************************************************/

static uint32_t gpio_base[] =
{
  STM32_GPIOA_BASE,
  STM32_GPIOB_BASE,
  STM32_GPIOC_BASE,
  STM32_GPIOD_BASE,
  STM32_GPIOE_BASE,
  0, /* Reserved for GPIOF */
  0, /* Reserved for GPIOG */
  STM32_GPIOH_BASE
};

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * stm32_gpio_read - Read the state of a GPIO pin based on the provided
 *                   configuration set.
 * @param pinset Configuration set containing port and pin.
 * @return true if the pin is set, false if it is reset.
 ****************************************************************************/
bool stm32_gpio_read(uint32_t pinset)
{
#warning "stm32_gpio_read not implemented yet"
  return false;
}

/****************************************************************************
 * stm32_gpio_write - Write a value to a GPIO pin based on the provided
 *                    configuration set.
 *
 * @param pinset Configuration set containing port and pin.
 * @param value true to set the pin, false to reset it.
 ****************************************************************************/
void stm32_gpio_write(uint32_t pinset, bool value)
{
  uint32_t pin;
  uint32_t port;

  uint32_t base_address;

  /* Extract port and pin from the configuration set */
  pin = (pinset & GPIO_PIN_MASK) >> GPIO_PIN_SHIFT;
  port = (pinset & GPIO_PORT_MASK) >> GPIO_PORT_SHIFT;
  base_address = gpio_base[port];

  if (value)
    {
      putreg32(GPIO_BSRR_SET(pin), base_address + STM32_GPIO_BSRR_OFFSET);
    }
  else
    {  
      putreg32(GPIO_BSRR_RESET(pin), base_address + STM32_GPIO_BSRR_OFFSET);
    }
}

/****************************************************************************
 * stm32_gpio_config - Configure GPIO pin based on the provided configuration
 *                     set.
 *
 * @param configset Configuration set containing port, pin, mode, type, speed,
 *                  pull-up/pull-down, and alternate function.
 * @return 0 on success, or a negative error code on failure.
 ****************************************************************************/
int stm32_gpio_config(uint32_t configset)
{
  uint32_t pin;
  uint32_t port;
  uint32_t pin_mode;

  uint32_t regval;
  uint32_t base_address;

  /* Extract port and pin from the configuration set */
  pin = (configset & GPIO_PIN_MASK) >> GPIO_PIN_SHIFT;
  port = (configset & GPIO_PORT_MASK) >> GPIO_PORT_SHIFT;
  base_address = gpio_base[port];

  /* Configure the GPIO pin mode */
  switch (configset & GPIO_MODE_MASK)
  {
    case GPIO_MODE_INPUT:
      pin_mode = GPIO_MODER_INPUT << GPIO_MODER_SHIFT(pin);
      break;

    case GPIO_MODE_OUTPUT:
      pin_mode = GPIO_MODER_OUTPUT << GPIO_MODER_SHIFT(pin);
      break;

    case GPIO_MODE_ALT:
      return -1; // Not implemented yet
      break;
    
    case GPIO_MODE_ANALOG:
      return -1; // Not implemented yet
      break;
  }

  regval = getreg32(base_address + STM32_GPIO_MODER_OFFSET);
  regval &= ~GPIO_MODER_MASK(pin);
  regval |= pin_mode;
  putreg32(regval, base_address + STM32_GPIO_MODER_OFFSET);

  if ((configset & GPIO_MODE_MASK) == GPIO_MODE_OUTPUT)
  {
    /* Configure output type and speed */
    uint32_t pin_otype = (configset & GPIO_OTYPE_MASK) >> GPIO_OTYPE_SHIFT;
    pin_otype <<= GPIO_OTYPER_SHIFT(pin);
    regval = getreg32(base_address + STM32_GPIO_OTYPER_OFFSET);
    regval &= ~GPIO_OTYPER_MASK(pin);
    regval |= pin_otype;
    putreg32(regval, base_address + STM32_GPIO_OTYPER_OFFSET);
  
    uint32_t pin_speed = (configset & GPIO_OSPEED_MASK) >> GPIO_OSPEED_SHIFT;
    pin_speed <<= GPIO_OSPEEDR_SHIFT(pin);
    regval = getreg32(base_address + STM32_GPIO_OSPEEDR_OFFSET);
    regval &= ~GPIO_OSPEEDR_MASK(pin);
    regval |= pin_speed;
    putreg32(regval, base_address + STM32_GPIO_OSPEEDR_OFFSET);
  }

  if ((configset & GPIO_MODE_MASK) != GPIO_MODE_ANALOG)
  {
    /* Configure pull-up/pull-down */
    uint32_t pin_pupd = (configset & GPIO_PUPD_MASK) >> GPIO_PUPD_SHIFT;
    pin_pupd <<= GPIO_PUPDR_SHIFT(pin);
    regval = getreg32(base_address + STM32_GPIO_PUPDR_OFFSET);
    regval &= ~GPIO_PUPDR_MASK(pin);
    regval |= pin_pupd;
    putreg32(regval, base_address + STM32_GPIO_PUPDR_OFFSET);
  }

  return 0;
}