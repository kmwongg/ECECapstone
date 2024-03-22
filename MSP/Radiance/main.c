#include "msp.h"
#include "Motor.h"
#include <stdint.h>
#include <stdbool.h>
#include "Defines.h"
#include "Clock.h"
#include "CortexM.h"
#include "TimerA0.h"
#include "UART0.h"
#define TRUE 1
#define FALSE 0
#define MASK 0x01

/**
 * main.c
 */


char command;
void main(void)
{
    bool ClockSystemError = false;

    // Stop the watchdog timer.
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;
    DisableInterrupts();

    // Configure the clock system. If there is an error,
    // continue trying to initialize.
    ClockSystemError = InitializeClockSystem();
    while (ClockSystemError) {
        ClockSystemError = InitializeClockSystem();
    }

    // Initialize the hardware
    InitializeMotorPortPins();
    InitializeTimerA0();//
    InitializeUART0();

    EnableInterrupts();



    while (TRUE) {

        if(EUSCI_A0->IFG & 0x01){

                    TIMER_A0->CTL = (TIMER_A_CTL_MC__STOP | TIMER_A_CTL_CLR); // stop pulses
                    command = ReceiveChar(); // read instruction from python program
                    //selecting command
                    if(command == '0'){
                        LR_MOTOR_DR_LOW;
                        TIMER_A0->CTL = (TIMER_A_CTL_SSEL__SMCLK | TIMER_A_CTL_MC__UP | TIMER_A_CTL_ID__8); // start pulse
                     }
                    else if(command == '1') {
                        LR_MOTOR_DR_HIGH;
                        TIMER_A0->CTL = (TIMER_A_CTL_SSEL__SMCLK | TIMER_A_CTL_MC__UP | TIMER_A_CTL_ID__8); // start pulse
                    } else{
                        TIMER_A0->CTL = (TIMER_A_CTL_MC__STOP | TIMER_A_CTL_CLR); // stop pulses

                    }


                    //confirmation
                    SendString("Changing command...\n");


                }

        //WaitForInterrupt();
    }

}








