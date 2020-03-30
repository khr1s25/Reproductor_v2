/*
 * interrupt.c
 *
 *  Created on: Mar 30, 2020
 *      Author: khris
 */

#include "interrupt.h"
#include "fsl_pit.h"

#define RELOJ_DE_CONFIGURACION CLOCK_GetFreq(kCLOCK_BusClk)
#define FALSE 0
#define TRUE 1
#define TIEMPO_DE_CONTEO USEC_TO_COUNT(1000u, RELOJ_DE_CONFIGURACION)
#define RUN_PIT PIT_IRQHandler

unsigned char pit_flag = FALSE;


void Inicializar_pit(){

	pit_config_t configuracionPit;

	/*
	 * pitConfig.enableRunInDebug = false;
	 */
	PIT_GetDefaultConfig(&configuracionPit);
		/* Init pit module */
	PIT_Init(PIT, &configuracionPit);
		/* Set timer period for channel 0 */
	PIT_SetTimerPeriod(PIT, kPIT_Chnl_0, TIEMPO_DE_CONTEO);
		/* Enable timer interrupts for channel 0 */
	PIT_EnableInterrupts(PIT, kPIT_Chnl_0, kPIT_TimerInterruptEnable);
		/* Enable at the NVIC */
	EnableIRQ(PIT_IRQn);
		/* Start channel 0 */
	PIT_StartTimer(PIT, kPIT_Chnl_0);

}

void RUN_PIT(){
	PIT_ClearStatusFlags(PIT, kPIT_Chnl_0, kPIT_TimerFlag);
	pit_flag = true;
}
