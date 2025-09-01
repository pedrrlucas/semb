#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "bsp.h"
#include "arduino.h"

int main(void)
{
  /* Initialize the board peripherals */
  bsp_init();

  /* Call Arduino setup function */
  setup();

  while(1)
  {
    /* Call Arduino loop function */
    loop();
  }
  return EXIT_FAILURE;
}
