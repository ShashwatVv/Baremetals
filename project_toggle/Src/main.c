
/**
 * The pin to be toggled is
 * orange LED, a user LED connected to the I/O PD13 of the
 * STM32F407VGT6.
 * */

#include "Register_Definitions.h"

/* Sets pin for output              bit 26 to 1       bit 27 to 0 */
#define SET_MODE_PIN(PIN_NUM) ((1<<2*PIN_NUM) & (~(1<<(2*PIN_NUM+1))))
#define TRUE                  1

void delay(void)
{
  for(uint32_t i=0; i<0x100000; i++);
}

int main(void)
{
	/* enable clock to the GPIO_D */
	RCC_AHB1_CLKEN_R = RCC_AHB1_CLKEN_R | (uint32_t)(GPIOD_EN);

	/* Set mode as output */
	GPIOD_MODE_R = GPIOD_MODE_R | SET_MODE_PIN(PIN);

	while(TRUE)
	{
		/* Set the output to high */
		GPIOD_OD_R = GPIOD_OD_R | LED;
		delay();
		/* Set the output to low */
		GPIOD_OD_R = GPIOD_OD_R & ~(LED);
		delay();
	}

	return 0;
}
