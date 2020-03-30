#include <foward.h>
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#include "fsl_gpio.h"

typedef enum {
	song_1,
	song_2,
	song_3,
	song_4
}PLAYLIST;

#define Board_Button_Foward 9
#define LED_1	2
#define LED_2	3

PLAYLIST curr_song = song_1;
PLAYLIST next_song = song_1;

int32_t button;


void CANCION(){
	///PLAYLIST canciones;
	CLOCK_EnableClock(kCLOCK_PortD);
	button = GPIO_ReadPinInput(GPIOB, Board_Button_Foward);

	gpio_pin_config_t pin1;
	gpio_pin_config_t pin2;

	pin1.pinDirection = kGPIO_DigitalOutput;
	pin2.pinDirection = kGPIO_DigitalOutput;

	pin1.outputLogic = 0u;
	pin2.outputLogic = 0u;

	GPIO_PinInit(GPIOD, LED_1, &pin1);
	GPIO_PinInit(GPIOD, LED_2, &pin2);

	my_foward(curr_song, button);
}

void my_foward(PLAYLIST curr_song, int32_t button){
	switch(curr_song){
	case song_1:
		if(button==1){

			GPIO_WritePinOutput(GPIOD, LED_1, 0);
			GPIO_WritePinOutput(GPIOD, LED_2, 0);

			next_song = song_2;
			curr_song = next_song;
		}
		break;

	case song_2:
		if(button==1){

			GPIO_WritePinOutput(GPIOD, LED_1, true);
			GPIO_WritePinOutput(GPIOD, LED_2, false);

			next_song = song_3;
			curr_song = next_song;
		}
		break;

	case song_3:
		if(button==1){

			GPIO_WritePinOutput(GPIOD, LED_1, false);
			GPIO_WritePinOutput(GPIOD, LED_2, true);

			next_song = song_3;
			curr_song = next_song;
		}
		break;

	case song_4:
		if(button==1){

			GPIO_WritePinOutput(GPIOD, LED_1, false);
			GPIO_WritePinOutput(GPIOD, LED_2, false);

			next_song = song_1;
			curr_song = next_song;
		}
		break;
	}
}
