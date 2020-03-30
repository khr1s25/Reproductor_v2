/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
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
 * o Neither the name of the copyright holder nor the names of its
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

/*!
 * @brief delay a while.
 */
void delay(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
void delay(void)
{
    volatile uint32_t i = 0;
    for (i = 0; i < 800000; ++i)
    {
        __asm("NOP"); /* delay */
    }
}

void contador(int cont)
{
	if(cont == 0)
	    	{
	    		delay();
	    		GPIO_PinInit(GPIOE, BOARD_LED_GPIO_PIN_0, &led_config);
	    		printf("\r\n Led 1 \r\n");
	    		cont++;
	    	}
			else if (cont == 1)
	    	{
	    		delay();
	    		GPIO_PinInit(GPIOE, BOARD_LED_GPIO_PIN_1, &led_config);
	    		printf("\r\n Led 2 \r\n");
	    		cont++;
	    	}
			else if (cont == 2)
	    	{
	    		delay();
	    		GPIO_PinInit(GPIOE, BOARD_LED_GPIO_PIN_2, &led_config);
	    		printf("\r\n Led 3 \r\n");
	    		cont++;
	    	}
			else if (cont == 3)
	    	{
	    		delay();
	    		GPIO_TogglePinsOutput(GPIOE, 1u << BOARD_LED_GPIO_PIN_0);
	    		GPIO_TogglePinsOutput(GPIOE, 1u << BOARD_LED_GPIO_PIN_1);
	    		GPIO_TogglePinsOutput(GPIOE, 1u << BOARD_LED_GPIO_PIN_2);
	    		cont = 0;
	    	}
			else
			{

	    		cont++;
	    	}
	return;
}

/*!
 * @brief Main function
 */

int main(void)
{
    /* Define the init structure for the output LED pin*/
    gpio_pin_config_t led_config = {
        kGPIO_DigitalOutput, 0,
    };
    unsigned int cont = 0;

    /* Board pin, clock, debug console init */
    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();

    /* Print a note to terminal. */

    /* Init output LED GPIO. */

    while (1)
    {
		contador(icont);
    }
}
