

#include "board.h"
#include "fsl_debug_console.h"
#include "fsl_gpio.h"

#include "clock_config.h"
#include "pin_mux.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define BOARD_LED_GPIO_PIN_0 2u
#define BOARD_LED_GPIO_PIN_1 3u
#define BOARD_LED_GPIO_PIN_2 4u


/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
void backward(int  cont)
{
	PIT_SetTimerPeriod(PIT, kPIT_Chnl_0, USEC_TO_COUNT(100U, PIT_SOURCE_CLOCK));
	while(1)
	{
    contadorinv(cont);
	if(/*B2V==0*/)
	{
		PIT_SetTimerPeriod(PIT, kPIT_Chnl_0, USEC_TO_COUNT(100U, PIT_SOURCE_CLOCK));
		return;
	}
	else
	{}
	}   	 
 } 

void contador(int cont)
{
	if(cont == 1)
	    	{
	    		if(/*Funcion del Debounce ()*/==1)
				{
					if(/*Type_Large()*/==0)
					{
						Pause(cont);
					}
					else if(/*Type_Large()*/==1)
					{
                         Stop(cont);
					}
				}
	    		delay();
	    		GPIO_PinInit(GPIOE, BOARD_LED_GPIO_PIN_0, &led_config);
	    		cont--;
	    	}
			else if (cont == 2)
	    	{
	    		delay();
	    		if(/*Funcion del Debounce ()*/==1)
				{
					if(/*Type_Large()*/==0)
					{
						Pause(cont);
					}
					else if(/*Type_Large()*/==1)
					{
                         Stop(cont);
					}
				}
				GPIO_PinInit(GPIOE, BOARD_LED_GPIO_PIN_1, &led_config);
	    		cont--;
	    	}
			else if (cont == 3)
	    		if(/*Funcion del Debounce ()*/==1)
				{
					if(/*Type_Large()*/==0)
					{
						Pause(cont);
					}
					else if(/*Type_Large()*/==1)
					{
                         Stop(cont);
					}
				}
				GPIO_PinInit(GPIOE, BOARD_LED_GPIO_PIN_2, &led_config);
	    		cont--;
	    	}
			else if (cont == 0)
	    	{
	    		delay();
	    		if(/*Funcion del Debounce ()*/==1)
				{
					if(/*Type_Large()*/==0)
					{
						Pause(cont);
					}
					else if(/*Type_Large()*/==1)
					{
                         Stop(cont);
					}
				}
				GPIO_TogglePinsOutput(GPIOE, 1u << BOARD_LED_GPIO_PIN_0);
	    		GPIO_TogglePinsOutput(GPIOE, 1u << BOARD_LED_GPIO_PIN_1);
	    		GPIO_TogglePinsOutput(GPIOE, 1u << BOARD_LED_GPIO_PIN_2);
	    		cont = 3;
	    	}
			else
			{
	    		cont--;
	    	}
	return;
}


