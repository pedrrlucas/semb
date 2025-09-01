/****************************************************************************
 * stm32/inc/stm32_gpio.h
 *
 *   Authors: Daniel Pereira de Carvalho <daniel.carvalho@ufu.br>
 *
 ****************************************************************************/

#ifndef __STM32_INC_STM32_GPIO_H
#define __STM32_INC_STM32_GPIO_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <stdbool.h>
#include <stdint.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Configset bit definitions
 *  0 -  3: GPIO port
 *  4 -  7: GPIO pin
 *  8 -  9: GPIO mode
 *      10: GPIO output type
 * 11 - 12: GPIO output speed
 * 13 - 14: GPIO pull-up/pull-down
 * 15 - 18: GPIO alternate function
 */

#define GPIO_PORT_SHIFT     0
#define GPIO_PORT_MASK      (0x0f << GPIO_PORT_SHIFT)
#define GPIO_PORTA          (0x00 << GPIO_PORT_SHIFT)
#define GPIO_PORTB          (0x01 << GPIO_PORT_SHIFT)
#define GPIO_PORTC          (0x02 << GPIO_PORT_SHIFT)
#define GPIO_PORTD          (0x03 << GPIO_PORT_SHIFT)
#define GPIO_PORTE          (0x04 << GPIO_PORT_SHIFT)
#define GPIO_PORTH          (0x07 << GPIO_PORT_SHIFT)

#define GPIO_PIN_SHIFT      4
#define GPIO_PIN_MASK       (0x0f << GPIO_PIN_SHIFT)
#define GPIO_PIN0           (0x00 << GPIO_PIN_SHIFT)
#define GPIO_PIN1           (0x01 << GPIO_PIN_SHIFT)
#define GPIO_PIN2           (0x02 << GPIO_PIN_SHIFT)
#define GPIO_PIN3           (0x03 << GPIO_PIN_SHIFT)
#define GPIO_PIN4           (0x04 << GPIO_PIN_SHIFT)
#define GPIO_PIN5           (0x05 << GPIO_PIN_SHIFT)
#define GPIO_PIN6           (0x06 << GPIO_PIN_SHIFT)
#define GPIO_PIN7           (0x07 << GPIO_PIN_SHIFT)
#define GPIO_PIN8           (0x08 << GPIO_PIN_SHIFT)
#define GPIO_PIN9           (0x09 << GPIO_PIN_SHIFT)
#define GPIO_PIN10          (0x0a << GPIO_PIN_SHIFT)
#define GPIO_PIN11          (0x0b << GPIO_PIN_SHIFT)
#define GPIO_PIN12          (0x0c << GPIO_PIN_SHIFT)
#define GPIO_PIN13          (0x0d << GPIO_PIN_SHIFT)
#define GPIO_PIN14          (0x0e << GPIO_PIN_SHIFT)
#define GPIO_PIN15          (0x0f << GPIO_PIN_SHIFT)

#define GPIO_MODE_SHIFT     8
#define GPIO_MODE_MASK      (0x03 << GPIO_MODE_SHIFT)
#define GPIO_MODE_INPUT     (0x00 << GPIO_MODE_SHIFT)
#define GPIO_MODE_OUTPUT    (0x01 << GPIO_MODE_SHIFT)
#define GPIO_MODE_ALT       (0x02 << GPIO_MODE_SHIFT)
#define GPIO_MODE_ANALOG    (0x03 << GPIO_MODE_SHIFT)

#define GPIO_OTYPE_SHIFT    10
#define GPIO_OTYPE_MASK     (0x01 << GPIO_OTYPE_SHIFT)
#define GPIO_OTYPE_PP       (0x00 << GPIO_OTYPE_SHIFT) /* Push-pull */
#define GPIO_OTYPE_OD       (0x01 << GPIO_OTYPE_SHIFT) /* Open-drain */

#define GPIO_OSPEED_SHIFT   11
#define GPIO_OSPEED_MASK    (0x03 << GPIO_OSPEED_SHIFT)
#define GPIO_OSPEED_LOW     (0x00 << GPIO_OSPEED_SHIFT) /* Low speed */
#define GPIO_OSPEED_MEDIUM  (0x01 << GPIO_OSPEED_SHIFT) /* Medium speed */
#define GPIO_OSPEED_FAST    (0x02 << GPIO_OSPEED_SHIFT) /* Fast speed */
#define GPIO_OSPEED_HIGH    (0x03 << GPIO_OSPEED_SHIFT) /* High speed */

#define GPIO_PUPD_SHIFT     13
#define GPIO_PUPD_MASK      (0x03 << GPIO_PUPD_SHIFT)
#define GPIO_PUPD_NONE      (0x00 << GPIO_PUPD_SHIFT) /* No pull-up, pull-down */
#define GPIO_PUPD_PULLUP    (0x01 << GPIO_PUPD_SHIFT) /* Pull-up */
#define GPIO_PUPD_PULLDOWN  (0x02 << GPIO_PUPD_SHIFT) /* Pull-down */

#define GPIO_AF_SHIFT       15
#define GPIO_AF_MASK        (0x0f << GPIO_AF_SHIFT)
#define GPIO_AF0            (0x00 << GPIO_AF_SHIFT) /* AF0 */
#define GPIO_AF1            (0x01 << GPIO_AF_SHIFT) /* AF1 */
#define GPIO_AF2            (0x02 << GPIO_AF_SHIFT) /* AF2 */
#define GPIO_AF3            (0x03 << GPIO_AF_SHIFT) /* AF3 */
#define GPIO_AF4            (0x04 << GPIO_AF_SHIFT) /* AF4 */
#define GPIO_AF5            (0x05 << GPIO_AF_SHIFT) /* AF5 */
#define GPIO_AF6            (0x06 << GPIO_AF_SHIFT) /* AF6 */
#define GPIO_AF7            (0x07 << GPIO_AF_SHIFT) /* AF7 */
#define GPIO_AF8            (0x08 << GPIO_AF_SHIFT) /* AF8 */
#define GPIO_AF9            (0x09 << GPIO_AF_SHIFT) /* AF9 */
#define GPIO_AF10           (0x0a << GPIO_AF_SHIFT) /* AF10 */
#define GPIO_AF11           (0x0b << GPIO_AF_SHIFT) /* AF11 */
#define GPIO_AF12           (0x0c << GPIO_AF_SHIFT) /* AF12 */
#define GPIO_AF13           (0x0d << GPIO_AF_SHIFT) /* AF13 */
#define GPIO_AF14           (0x0e << GPIO_AF_SHIFT) /* AF14 */
#define GPIO_AF15           (0x0f << GPIO_AF_SHIFT) /* AF15 */

 /****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

/**
 * @brief Read GPIO pin state.
 * @param pinset Configuration set containing port and pin.
 * @return true if the pin is set, false if it is reset.
 * This function reads the state of a specific GPIO pin based on the provided
 * configuration set. It checks the input data register for the specified pin.
 */
bool stm32_gpio_read(uint32_t pinset);

/**
 * @brief Write GPIO pin state.
 * @param pinset Configuration set containing port and pin.
 * @param value true to set the pin, false to reset it.
 * This function writes a value to a specific GPIO pin based on the provided
 * configuration set. It modifies the output data register for the specified pin.
 */
void stm32_gpio_write(uint32_t pinset, bool value);

/**
 * @brief Configure GPIO pin based on the provided configuration set.
 * @param configset Configuration set containing port, pin, mode, type, speed,
 *                  pull-up/pull-down, and alternate function.
 * @return 0 on success, or a negative error code on failure.
 * This function sets up the GPIO pin according to the specified parameters.
 * It modifies the appropriate registers to configure the pin's mode,
 * output type, speed, pull-up/pull-down configuration, and alternate function.
 */
int stm32_gpio_config(uint32_t configset);

#endif /* __STM32_INC_STM32_GPIO_H */