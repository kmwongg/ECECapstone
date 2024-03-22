#include "msp.h"
#include "Motor.h"
#include <stdint.h>
#include <stdbool.h>
#include "Defines.h"
#include "Clock.h"
#include "CortexM.h"
#include "TimerA0.h"
#include "TimerA1.h"
#include "UART0.h"
#define TRUE 1
#define FALSE 0
#define MASK 0x01

void main(void)
{
    char command;
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
    InitializeTimerA0();// now using timer interrupts to generate pulses
    InitializeTimerA1();
    InitializeUART0();
    EnableInterrupts();

    UD_STOP;
    LR_STOP;
    while (TRUE) {

        if(EUSCI_A0->IFG & 0x01){ // if data is received then the following is executed
                    command = ReceiveChar(); // reads instruction from python program

                    if ((command & 0x02) >> 1) { //bit mask for left bit and shift 1
                        LR_MOTOR_DR_HIGH;
                        LR_START; // start pulse
                    }
                    else if ((command & 0x01)){ //bit mask for right bit no shift
                        LR_MOTOR_DR_LOW;
                        LR_START; // start pulse
                    }
                    else {
                        LR_STOP; // stop pulses
                    }

                    if ((command & 0x08) >> 3) { //bit mask for left bit and shift 1
                        UD_MOTOR_DR_HIGH;
                        UD_START; // start pulse
                    }
                    else if ((command & 0x04) >> 2){ //bit mask for right bit no shift
                        UD_MOTOR_DR_LOW;
                        UD_START; // start pulse
                    }
                    else {
                        UD_STOP; // stop pulses
                    }

                    //confirmation
                    SendString("Changing command...\n");


                }

    }

}








