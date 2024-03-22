/*
 * Motor.c
 *
 *  Created on: Sep 23, 2023
 *      Author: kou
 */
#include "Motor.h"

void InitializeMotorPortPins(void)
{
    // Sets both pins as outputs and pull them low
    LR_MOTOR_DR_LOW;
    SET_LR_MOTOR_DR_AS_AN_OUTPUT;
    LR_MOTOR_STEP_LOW;
    SET_LR_MOTOR_STEP_AS_AN_OUTPUT;
}






