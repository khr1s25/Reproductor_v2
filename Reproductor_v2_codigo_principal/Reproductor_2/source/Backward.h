/*
 * Backward.h
 *
 *  Created on: Apr 2, 2020
 *      Author: khris
 */

#ifndef BACKWARD_H_
#define BACKWARD_H_

typedef enum {
	song_1_B,
	song_2_B,
	song_3_B,
	song_4_B
}PLAYLIST_B;

extern uint32_t B_BACK(int,int,PLAYLIST_B,uint32_t);

#endif /* BACKWARD_H_ */
