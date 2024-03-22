#ifndef Motor_H
#define Motor_H

#include "msp.h"

////////Motor for left and right movement////////////

//Step signal. Choosing port 2 pin  5
#define LR_MOTOR_STEP_BIT 5
#define LR_MOTOR_STEP_MASK (0x01 << LR_MOTOR_STEP_BIT)
#define LR_MOTOR_STEP_OUT P2->OUT
#define LR_MOTOR_STEP_DIR P2->DIR
#define SET_LR_MOTOR_STEP_AS_AN_OUTPUT LR_MOTOR_STEP_DIR |= LR_MOTOR_STEP_MASK
#define LR_MOTOR_STEP_HIGH LR_MOTOR_STEP_OUT |= LR_MOTOR_STEP_MASK
#define LR_MOTOR_STEP_LOW LR_MOTOR_STEP_OUT &= ~LR_MOTOR_STEP_MASK
#define TOGGLE_LR_MOTOR_STEP LR_MOTOR_STEP_OUT ^= LR_MOTOR_STEP_MASK

// Dir signal. Choosing port 1 pin 6
#define LR_MOTOR_DR_BIT 6
#define LR_MOTOR_DR_MASK (0x01 << LR_MOTOR_DR_BIT)
#define LR_MOTOR_DR_OUT P1->OUT
#define LR_MOTOR_DR_DIR P1->DIR
#define SET_LR_MOTOR_DR_AS_AN_OUTPUT LR_MOTOR_DR_DIR |= LR_MOTOR_DR_MASK
#define LR_MOTOR_DR_HIGH LR_MOTOR_DR_OUT |= LR_MOTOR_DR_MASK
#define LR_MOTOR_DR_LOW LR_MOTOR_DR_OUT &= ~LR_MOTOR_DR_MASK
#define TOGGLE_LR_MOTOR_DR LR_MOTOR_DR_OUT ^= LR_MOTOR_DR_MASK



//Function Prototypes
void InitializeMotorPortPins(void);

#endif
