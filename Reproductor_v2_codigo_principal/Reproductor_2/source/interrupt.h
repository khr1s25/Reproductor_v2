/*
 * interrupt.h
 *
 *  Created on: Mar 30, 2020
 *      Author: khris
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

extern void RUN_PIT();
extern void Inicializar_pit();

unsigned char pit_flag = FALSE;

#endif /* INTERRUPT_H_ */