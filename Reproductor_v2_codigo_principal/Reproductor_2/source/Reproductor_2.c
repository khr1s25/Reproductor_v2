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
 * @file    Reproductor_2.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#include "fsl_pit.h"
/* TODO: insert other include files here. */
#include "foward.h"
#include "interrupt.h"
#include "Reproduccion.h"
/* TODO: insert other definitions and declarations here. */

#define FALSE 0
#define TRUE 1
#define B_1 8u
#define B_2 9u
#define B_3 10u

unsigned char pit_flag = FALSE;

/*
 * @brief   Application entry point.
 */
int main(void) {

  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
  	/* Init FSL debug console. */
    BOARD_InitDebugConsole();

    Inicializar_pit();

    PRINTF("Hello World\n");

    for(;;){
    	if(pit_flag = TRUE){

    		/* FALTA INICIALIZAR BOTONES Y RECIBIRLOS*/
    		uint32_t B1 = GPIO_ReadPinInput(GPIOB,B_1);
    		uint32_t B2 = GPIO_ReadPinInput(GPIOB,B_2);
    		uint32_t B3 = GPIO_ReadPinInput(GPIOB,B_3);

    		/*printf("%i \n",B1);
    		printf("%i \n",B2);
    		printf("%i \n",B3);*/

    		uint32_t DB1 = 0;
    		uint32_t DB2 = 0;
    		uint32_t DB3 = 0;

    		if(B1==0)
    		DB1 = Debouncer(B_1);
    		if(B2==0)
    		DB2 = Debouncer(B_2);
    		if(B3==0)
    		DB3 = Debouncer(B_3);


    		/*printf("%i \n",DB1);
    		printf("%i \n",DB2);
    		printf("%i \n",DB3);*/

    		//contador(0, DB1);
    		//F_NEXT(B2, DB2);
    		/*B_BACK(B3, DB3);  */
    	}
    }

    /* Force the counter to be placed into memory. */
    volatile static int i = 0 ;
    /* Enter an infinite loop, just incrementing a counter. */
    while(1) {
        i++ ;
        /* 'Dummy' NOP to allow source level single stepping of
            tight while() loop */
        __asm volatile ("nop");
    }
    return 0 ;
}

void RUN_PIT(){
	PIT_ClearStatusFlags(PIT, kPIT_Chnl_0, kPIT_TimerFlag);
	pit_flag = TRUE;
}
