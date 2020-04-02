

#include "board.h"
#include "fsl_debug_console.h"
#include "fsl_gpio.h"

#include "clock_config.h"
#include "pin_mux.h"
#include "Reproduccion.h"
#include "Backward.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define BOARD_LED_GPIO_PIN_0 2u
#define BOARD_LED_GPIO_PIN_1 3u
#define BOARD_LED_GPIO_PIN_2 4u

#define LED_1	3
#define LED_2	2


/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
void backward(int  cont, int pressed_time)
{
	PIT_SetTimerPeriod(PIT, kPIT_Chnl_0, USEC_TO_COUNT(100U, PIT_SOURCE_CLOCK));
	while(1)
	{
	if(pressed_time>50)
	{
		PIT_SetTimerPeriod(PIT, kPIT_Chnl_0, USEC_TO_COUNT(100U, PIT_SOURCE_CLOCK));
		contadorinv(cont, pressed_time);
		return;
	}
	else
	{my_back();}
	}   	 
 } 

void contadorinv(int cont, int time_pressed)
{
	if(cont == 1)
	    	{
	    		if(cont>=50)
				{
					if(cont<100)
					{
						contador(cont, time_pressed);
					}
					else if(cont>=100)
					{
						contador(cont, time_pressed);
					}
				}

	    		GPIO_PinInit(GPIOE, BOARD_LED_GPIO_PIN_0, &led_config);
	    		cont=cont-1;
	    	}
			else if (cont == 2)
	    	{
	    		if(cont>=50)
				{
					if(cont<100)
					{
						contador(cont, time_pressed);
					}
					else if(cont>=100)
					{
						contador(cont, time_pressed);
					}
				}
				GPIO_PinInit(GPIOE, BOARD_LED_GPIO_PIN_1, &led_config);
	    		cont--;
	    	}
			else if (cont == 3){
	    		if(cont>=50)
				{
					if(cont<100)
					{
						contador(cont, time_pressed);
					}
					else if(cont>=100)
					{
						contador(cont, time_pressed);
					}
				}
				GPIO_PinInit(GPIOE, BOARD_LED_GPIO_PIN_2, &led_config);
	    		cont--;
	    	}
			else if (cont == 0)
	    	{
	    		if(cont>=50)
				{
					if(cont<100)
					{
						contador(cont, time_pressed);
					}
					else if(cont>=100)
					{
						contador(cont, time_pressed);
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

void my_back(PLAYLIST curr_song, int32_t button){
	switch(curr_song){
	case song_1:
		if(button==0){

			GPIO_SetPinsOutput(GPIOD, 1u << LED_1);
			GPIO_SetPinsOutput(GPIOD, 1u << LED_2);

			next_song = song_4;
			curr_song = next_song;
		}
		break;

	case song_2:
		if(button==0){

			GPIO_TogglePinsOutput(GPIOD, 1u << LED_1);

			next_song = song_1;
			curr_song = next_song;
		}
		break;

	case song_3:
		if(button==0){

			GPIO_TogglePinsOutput(GPIOD, 1u << LED_1);
			GPIO_TogglePinsOutput(GPIOD, 1u << LED_2);

			next_song = song_2;
			curr_song = next_song;
		}
		break;

	case song_4:
		if(button==0){

			GPIO_WritePinOutput(GPIOD, LED_1, false);

			next_song = song_3;
			curr_song = next_song;
		}
		break;
	}
}


