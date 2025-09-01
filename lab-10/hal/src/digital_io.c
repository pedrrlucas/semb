/****************************************************************************
 * hal/src/digital_io.c
 *
 *   Authors: Daniel Pereira de Carvalho <daniel.carvalho@ufu.br>
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <stdbool.h>
#include <stdint.h>

#include "bsp.h"
#include "stm32_gpio.h"

#include "digital_io.h"


/****************************************************************************
 * Private Variables
 ****************************************************************************/

/* Pin mapping for digital I/O */
extern uint32_t pin_map[MAX_DIGITAL_IO];

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/**
  * @brief Reads the value from a specified digital pin, either HIGH or LOW.
  */
int digitalRead(int pin)
{
  uint32_t pinset;
  bool value;

  /* Checks for valid pin number */
  if (pin < 0 || pin >= MAX_DIGITAL_IO) {
    return INVALID;
  }

  /* Maps pin number to GPIO pin */
  pinset = pin_map[pin];

  value = stm32_gpio_read(pinset);

  return (value == true ? HIGH : LOW);
}

/**
  * @brief Write a HIGH or a LOW value to a digital pin.
  */
void digitalWrite(int pin, int value)
{
  uint32_t pinset;

  /* Checks for valid pin number */
  if (pin < 0 || pin >= MAX_DIGITAL_IO) {
    return;
  }

  /* Maps pin number to GPIO pin */
  pinset = pin_map[pin];

  stm32_gpio_write(pinset, (value == HIGH ? true : false));
}

/**
  * @brief Configures the specified pin to behave either as an INPUT or an
  *        OUTPUT.
  */
void pinMode(int pin, int mode)
{
  uint32_t configset;

  /* Checks for valid pin number */
  if (pin < 0 || pin >= MAX_DIGITAL_IO) {
    return;
  }

  /* Maps pin number to GPIO pin */
  configset = pin_map[pin];

  switch (mode) 
  {
    case INPUT_PULLUP:
      configset |= GPIO_PUPD_PULLUP;
    case INPUT:
      configset |= GPIO_MODE_INPUT;
      break;

    case OUTPUT:
      configset |= GPIO_MODE_OUTPUT | GPIO_OTYPE_PP |
                   GPIO_OSPEED_HIGH;
      break;

    default:
      /* Invalid mode */
      return;
  }

  stm32_gpio_config(configset);
}