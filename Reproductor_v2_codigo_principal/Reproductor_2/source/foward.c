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

typedef enum {
	song_1,
	song_2,
	song_3,
	song_4
}PLAYLIST;

#define LED_1	3
#define LED_2	2

PLAYLIST curr_song = song_1;
PLAYLIST next_song = song_1;


void F_NEXT(int32_t button, int time_pressed){
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
	}
	else{
		my_next(curr_song, button);
	}
}

void my_next(PLAYLIST curr_song, int32_t button){
	switch(curr_song){
	case song_1:
		if(button==0){

			GPIO_SetPinsOutput(GPIOD, 1u << LED_1);
			GPIO_SetPinsOutput(GPIOD, 1u << LED_2);

			next_song = song_2;
			curr_song = next_song;
		}
		break;

	case song_2:
		if(button==0){

			GPIO_TogglePinsOutput(GPIOD, 1u << LED_1);

			next_song = song_3;
			curr_song = next_song;
		}
		break;

	case song_3:
		if(button==0){

			GPIO_TogglePinsOutput(GPIOD, 1u << LED_1);
			GPIO_TogglePinsOutput(GPIOD, 1u << LED_2);

			next_song = song_3;
			curr_song = next_song;
		}
		break;

	case song_4:
		if(button==0){

			GPIO_WritePinOutput(GPIOD, LED_1, false);

			next_song = song_1;
			curr_song = next_song;
		}
		break;
	}
}

void my_foward(){
	/*codigo para acelerar la cancion*/
	    PIT_SetTimerPeriod(PIT, kPIT_Chnl_0, USEC_TO_COUNT(100U, CLOCK_GetFreq(kCLOCK_BusClk)));
}
