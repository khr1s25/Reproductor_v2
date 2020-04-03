#include <foward.h>
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#include "fsl_gpio.h"
#include "fsl_pit.h"


#define LED_1	3
#define LED_2	2


uint32_t my_next(PLAYLIST_F, uint32_t);
void my_foward();


uint32_t F_NEXT(uint32_t button, uint32_t time_pressed, PLAYLIST_F curr_song){
	///PLAYLIST canciones;
	CLOCK_EnableClock(kCLOCK_PortD);


	gpio_pin_config_t pin1;
	gpio_pin_config_t pin2;

	pin1.pinDirection = kGPIO_DigitalOutput;
	pin2.pinDirection = kGPIO_DigitalOutput;

	pin1.outputLogic = 0u;
	pin2.outputLogic = 0u;

	GPIO_PinInit(GPIOD, LED_1, &pin1);
	GPIO_PinInit(GPIOD, LED_2, &pin2);

	if(time_pressed > 50){
		my_foward();
		PIT_SetTimerPeriod(PIT, kPIT_Chnl_0, USEC_TO_COUNT(1000U, CLOCK_GetFreq(kCLOCK_BusClk)));
		return curr_song;
	}
	else{
		return my_next(curr_song, button);
	}
}

uint32_t my_next(PLAYLIST_F curr_song, uint32_t button){
	PLAYLIST_F next_song = curr_song;
	switch(curr_song){
	case song_1_F:
		if(button==0){

			GPIO_SetPinsOutput(GPIOD, 1u << LED_1);
			GPIO_SetPinsOutput(GPIOD, 1u << LED_2);

			next_song = song_2_F;
			curr_song = next_song;
		}
		break;

	case song_2_F:
		if(button==0){

			GPIO_TogglePinsOutput(GPIOD, 1u << LED_1);

			next_song = song_3_F;
			curr_song = next_song;
		}
		break;

	case song_3_F:
		if(button==0){

			GPIO_TogglePinsOutput(GPIOD, 1u << LED_1);
			GPIO_TogglePinsOutput(GPIOD, 1u << LED_2);

			next_song = song_4_F;
			curr_song = next_song;
		}
		break;

	case song_4_F:
		if(button==0){

			GPIO_WritePinOutput(GPIOD, LED_1, false);

			next_song = song_1_F;
			curr_song = next_song;
		}
		break;
	}
	return curr_song;
}

void my_foward(){
	/*codigo para acelerar la cancion*/
	    PIT_SetTimerPeriod(PIT, kPIT_Chnl_0, USEC_TO_COUNT(100U, CLOCK_GetFreq(kCLOCK_BusClk)));
}
