/*
 * Copyright 2016-2020 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
 * @file    Maquina_estado.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#include "fsl_gpio.h"

/* TODO: insert other include files here. */



/* TODO: insert other definitions and declarations here. */
typedef enum {
	DISABLE,
	COUNT_ENABLE,
	ENABLE,
	COUNT_DIS,
	NUM_OF_STATES
}MACH_STATES;

#define BOARD_LED_GPIO BOARD_LED_RED_GPIO
#define BOARD_LED_GPIO_PIN_0 8u

MACH_STATES curr_state = DISABLE;
MACH_STATES next_state = DISABLE;

int32_t button;


/*
 * @brief   Application entry point.
 */
void my_state_machine(MACH_STATES curr_state, int32_t button){
	int contador = 0;
	switch(curr_state){
	case DISABLE:
		if(button==1){
			contador = 0;
			next_state = COUNT_ENABLE;
			//output = DISABLE;
			curr_state = next_state;
		}
		break;

	case COUNT_ENABLE:
		if(button==1 && contador < 4){
			contador = contador +1;
			//output = DISABLE;
			next_state = COUNT_ENABLE;
			curr_state = next_state;
		}
		else if(button==1 && contador >=4){
			//output = ENABLE;
			next_state = ENABLE;
			curr_state = next_state;
		}
		else {
			contador = 0;
			//output = DISABLE;
			next_state = DISABLE;
			curr_state = next_state;
		}
		break;

	case ENABLE:
		if(button==0){
			contador = 0;
			//output = ENABLE;
			next_state = COUNT_DIS;
			curr_state = next_state;
		}
		break;

	case COUNT_DIS:
		if(button==1){
			contador = 0;
			//output = ENABLE;
			next_state = ENABLE;
			curr_state = next_state;
		}
		else if(button==0 && contador < 3){
			contador = contador + 1;
			//output = ENABLE;
			next_state = COUNT_DIS;
			curr_state = next_state;
		}
		else{
			//output = DISABLE;
			next_state = DISABLE;
			curr_state = next_state;
		}
		break;
	}
}

int main(void) {

  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
  	/* Init FSL debug console. */
    BOARD_InitDebugConsole();


    /* Force the counter to be placed into memory. */
    volatile static int i = 0 ;
    /* Enter an infinite loop, just incrementing a counter. */
    while(1) {
    	button = GPIO_ReadPinInput(GPIOA, BOARD_LED_GPIO_PIN_0);
    	my_state_machine(curr_state, button);
        i++ ;
        /* 'Dummy' NOP to allow source level single stepping of
            tight while() loop */
        __asm volatile ("nop");
    }
    return 0 ;
}

