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


void Inicializar_pit(){

	pit_config_t configuracionPit;
	PIT_GetDefaultConfig(&configuracionPit);
	PIT_Init(PIT, &configuracionPit);
	PIT_SetTimerPeriod(PIT, kPIT_Chnl_0, TIEMPO_DE_CONTEO);
	PIT_EnableInterrupts(PIT, kPIT_Chnl_0, kPIT_TimerInterruptEnable);
	EnableIRQ(PIT_IRQn);
	PIT_StartTimer(PIT, kPIT_Chnl_0);
}
