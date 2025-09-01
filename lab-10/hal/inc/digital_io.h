/****************************************************************************
 * hal/inc/digital_io.h
 *
 *   Authors: Daniel Pereira de Carvalho <daniel.carvalho@ufu.br>
 *
 ****************************************************************************/

#ifndef __HAL_INC_DIGITAL_IO_H
#define __HAL_INC_DIGITAL_IO_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Pin modes */
#define   INPUT 0
#define   OUTPUT 1
#define   INPUT_PULLUP 2

/* Pin states */
#define   INVALID -1
#define   LOW 0
#define   HIGH 1

/**
  * @brief Reads the value from a specified digital pin, either HIGH or LOW.
  *
  * @param The function admits the following parameter:
  *   - pin: The Arduino pin number to read from.
  *
  * @retval The function returns the boolean state of the read pin as HIGH
  *         or LOW.
  */
int digitalRead(int pin);

/**
  * @brief Write a HIGH or a LOW value to a digital pin.
  *
  * @param The function admits the following parameter:
  *   - pin: The Arduino pin number to be controlled.
  *   - value: The value to write. Use HIGH or LOW.
  *
  * @retval The function returns nothing.
  */
void digitalWrite(int pin, int value);

/**
  * @brief Configures the specified pin to behave either as an INPUT or an
  *        OUTPUT.
  *
  * @param pin: the Arduino pin number to set the mode of.
  *   - pin: The Arduino pin number to set the mode of.
  *   - mode: INPUT, OUTPUT, or INPUT_PULLUP. See the Digital Pins page for
  *           a more complete description of the functionality.
  *
  * @retval The function returns nothing.
  */
void pinMode(int pin, int mode);

#endif /* __HAL_INC_DIGITAL_IO_H */