/*
 * TimerA0.c
 *
 *  Created on: Sep 19, 2022
 *      Author: kouda
 */

#include "TimerA0.h"
// Global variables


void InitializeTimerA0(void){

    TIMER_A0->CTL = (TIMER_A_CTL_MC__STOP | TIMER_A_CTL_CLR); // stops and clears timer

    TIMER_A0->CCR[0] = (TIMER_A0_PERIOD - 1);

    TIMER_A0->CCTL[0] = TIMER_A_CCTLN_CCIE;

    NVIC->ISER[0] |= (0x00000001 << TA0_0_IRQn);//=8

    NVIC->IP[(TA0_0_IRQn)] = 0;

    TIMER_A0->EX0 = TIMER_A_EX0_IDEX__8;

    //TIMER_A0->CTL = (TIMER_A_CTL_SSEL__SMCLK | TIMER_A_CTL_MC__UP | TIMER_A_CTL_ID__8); // this line actually starts the timer

}

void TA0_0_IRQHandler(void){

    TIMER_A0->CCTL[0] &= ~TIMER_A_CCTLN_CCIFG; // Clears the flag
    TOGGLE_LR_MOTOR_STEP;

}
