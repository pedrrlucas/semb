/****************************************************************************
 * hal/inc/sketch.h
 *
 *   Authors: Daniel Pereira de Carvalho <daniel.carvalho@ufu.br>
 *
 ****************************************************************************/

#ifndef __HAL_INC_SKETCH_H
#define __HAL_INC_SKETCH_H

/**
  * @brief The setup() function is called when a sketch starts. Use it to
  *        initialize variables, pin modes, start using libraries, etc. The
  *        setup() function will only run once, after each powerup or reset
  *        of the Arduino board.
  *
  * @retval None
  */
void setup(void);

/**
 * @brief After creating a setup() function, which initializes and sets the
 *        initial values, the loop() function does precisely what its name
 *        suggests, and loops consecutively, allowing your program to change
 *        and respond. Use it to actively control the Arduino board.
 *
 * @retval None
 */
void loop(void);

#endif /* __HAL_INC_SKETCH_H */