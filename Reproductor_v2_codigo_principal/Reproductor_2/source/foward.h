/*
 * song_counter.h
 *
 *  Created on: Mar 27, 2020
 *      Author: khris
 */

#ifndef FOWARD_H_
#define FOWARD_H_

#include "stdint.h"

typedef enum {
	song_1_F,
	song_2_F,
	song_3_F,
	song_4_F
}PLAYLIST_F;

extern uint32_t F_NEXT(uint32_t,uint32_t,PLAYLIST_F);


#endif /* FOWARD_H_ */
