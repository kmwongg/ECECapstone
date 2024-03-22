//Timer A1 will generate a 1 kHz square wave signal on port 2.6

#include "TimerA1.h"


void InitializeTimerA1(void){

    //Stopping and clearing timer
    TIMER_A1->CTL = (TIMER_A_CTL_MC__STOP | TIMER_A_CTL_CLR);

    //Setting timer period
    TIMER_A1->CCR[0] = (TIMER_A1_PERIOD - 1);

    //Enabling interrupt
    TIMER_A1->CCTL[0] = TIMER_A_CCTLN_CCIE;

    //Enabling NVIC interrupt
    NVIC->ISER[0] |= (0x00000001 << TA1_0_IRQn);//=10

    //Setting the priority
    NVIC->IP[(TA1_0_IRQn)] = 0;

    //Clock division by 8
    TIMER_A1->EX0 = TIMER_A_EX0_IDEX__8;

    //Selecting the SMCLK, Count Up mode, and clock division by 1
    //TIMER_A1->CTL = (TIMER_A_CTL_SSEL__SMCLK | TIMER_A_CTL_MC__UP | TIMER_A_CTL_ID__1);

}

void TA1_0_IRQHandler(void){

    TIMER_A1->CCTL[0] &= ~TIMER_A_CCTLN_CCIFG; // Clears the flag
    TOGGLE_UD_MOTOR_STEP;
}
