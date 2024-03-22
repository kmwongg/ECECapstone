/*
 * Motor.c
 *
 *  Created on: Sep 23, 2023
 *      Author: kou
 */
#include "Motor.h"
#include "Clock.h"
#include "msp.h"

void InitializeMotorPortPins(void)
{
    // Sets both pins as outputs and pull them low
    LR_MOTOR_DR_LOW;
    SET_LR_MOTOR_DR_AS_AN_OUTPUT;
    LR_MOTOR_STEP_LOW;
    SET_LR_MOTOR_STEP_AS_AN_OUTPUT;
    UD_MOTOR_DR_LOW;
    SET_UD_MOTOR_DR_AS_AN_OUTPUT;
    UD_MOTOR_STEP_LOW;
    SET_UD_MOTOR_STEP_AS_AN_OUTPUT;
}

void Motor_Step(uint16_t numOfSteps, uint16_t direction, uint16_t speed){

    uint32_t stepCounter = 0;

    // Sets the direction
    if (direction){
        LR_MOTOR_DR_HIGH;
    }
    else{
        LR_MOTOR_DR_LOW;
    }

    // Moves the motor with the appropriate num of steps
    while (numOfSteps > stepCounter )   {
    TOGGLE_LR_MOTOR_STEP;
    Clock_Delay(speed);
    TOGGLE_LR_MOTOR_STEP;
    Clock_Delay(speed);
    stepCounter++;
    }

}




