

#include "board.h"
#include "fsl_debug_console.h"
#include "fsl_gpio.h"
#include "fsl_pit.h"

#include "clock_config.h"
#include "pin_mux.h"
#include "Reproduccion.h"
#include "Backward.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define TIEMPO_DE_CONTEO USEC_TO_COUNT(100u, RELOJ_DE_CONFIGURACION)
#define RELOJ_DE_CONFIGURACION CLOCK_GetFreq(kCLOCK_BusClk)
#define BOARD_LED_GPIO_PIN_0 2u
#define BOARD_LED_GPIO_PIN_1 3u
#define BOARD_LED_GPIO_PIN_2 4u

#define LED_1	3
#define LED_2	2

gpio_pin_config_t led_config_b = {
        kGPIO_DigitalOutput, 0,
    };

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

uint32_t my_back(PLAYLIST_B,uint32_t);
void contadorinv(int,int);

uint32_t B_BACK(int  cont, int pressed_time, PLAYLIST_B curr_song, uint32_t button)
{
	PIT_SetTimerPeriod(PIT, kPIT_Chnl_0, TIEMPO_DE_CONTEO);
	if(pressed_time>50)
	{
		PIT_SetTimerPeriod(PIT, kPIT_Chnl_0, TIEMPO_DE_CONTEO);
		contadorinv(cont, pressed_time);
		return curr_song;
	}
	else{
		 return my_back(curr_song, button);
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

	    		GPIO_PinInit(GPIOE, BOARD_LED_GPIO_PIN_0, &led_config_b);
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
				GPIO_PinInit(GPIOE, BOARD_LED_GPIO_PIN_1, &led_config_b);
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
				GPIO_PinInit(GPIOE, BOARD_LED_GPIO_PIN_2, &led_config_b);
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

uint32_t my_back(PLAYLIST_B curr_song, uint32_t button){
	PLAYLIST_B next_song = curr_song;
	switch(curr_song){
	case song_1_B:
		if(button==0){

			GPIO_SetPinsOutput(GPIOD, 1u << LED_1);
			GPIO_SetPinsOutput(GPIOD, 1u << LED_2);

			next_song = song_4_B;
			curr_song = next_song;
		}
		break;

	case song_2_B:
		if(button==0){

			GPIO_TogglePinsOutput(GPIOD, 1u << LED_1);

			next_song = song_1_B;
			curr_song = next_song;
		}
		break;

	case song_3_B:
		if(button==0){

			GPIO_TogglePinsOutput(GPIOD, 1u << LED_1);
			GPIO_TogglePinsOutput(GPIOD, 1u << LED_2);

			next_song = song_2_B;
			curr_song = next_song;
		}
		break;

	case song_4_B:
		if(button==0){

			GPIO_WritePinOutput(GPIOD, LED_1, false);

			next_song = song_3_B;
			curr_song = next_song;
		}
		break;
	}
	return curr_song;
}


