/*
 * TimerA0.h
 *
 *  Created on: Sep 19, 2022
 *      Author: kouda
 */

#ifndef TIMERA0_H_
#define TIMERA0_H_

#include "msp.h"
#include "Motor.h"
#define TIMER_A0_PERIOD 500 // formula for this number = (T/2) * (12 Mhz / 64) where T is the desired period of the pulse
void InitializeTimerA0(void);


#endif /* TIMERA0_H_ */
