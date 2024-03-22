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

// Start and stop commands
#define LR_START TIMER_A0->CTL = (TIMER_A_CTL_SSEL__SMCLK | TIMER_A_CTL_MC__UP | TIMER_A_CTL_ID__8)
#define LR_STOP TIMER_A0->CTL = (TIMER_A_CTL_MC__STOP | TIMER_A_CTL_CLR)


////////Motor for up and down movement////////////

//Step signal. Choosing port 2 pin  6
#define UD_MOTOR_STEP_BIT 6
#define UD_MOTOR_STEP_MASK (0x01 << UD_MOTOR_STEP_BIT)
#define UD_MOTOR_STEP_OUT P2->OUT
#define UD_MOTOR_STEP_DIR P2->DIR
#define SET_UD_MOTOR_STEP_AS_AN_OUTPUT UD_MOTOR_STEP_DIR |= UD_MOTOR_STEP_MASK
#define UD_MOTOR_STEP_HIGH UD_MOTOR_STEP_OUT |= UD_MOTOR_STEP_MASK
#define UD_MOTOR_STEP_LOW UD_MOTOR_STEP_OUT &= ~UD_MOTOR_STEP_MASK
#define TOGGLE_UD_MOTOR_STEP UD_MOTOR_STEP_OUT ^= UD_MOTOR_STEP_MASK

// Dir signal. Choosing port 6 pin 7
#define UD_MOTOR_DR_BIT 7
#define UD_MOTOR_DR_MASK (0x01 << UD_MOTOR_DR_BIT)
#define UD_MOTOR_DR_OUT P6->OUT
#define UD_MOTOR_DR_DIR P6->DIR
#define SET_UD_MOTOR_DR_AS_AN_OUTPUT UD_MOTOR_DR_DIR |= UD_MOTOR_DR_MASK
#define UD_MOTOR_DR_HIGH UD_MOTOR_DR_OUT |= UD_MOTOR_DR_MASK
#define UD_MOTOR_DR_LOW UD_MOTOR_DR_OUT &= ~UD_MOTOR_DR_MASK
#define TOGGLE_UD_MOTOR_DR UD_MOTOR_DR_OUT ^= UD_MOTOR_DR_MASK

// Start and stop commands
#define UD_START TIMER_A1->CTL = (TIMER_A_CTL_SSEL__SMCLK | TIMER_A_CTL_MC__UP | TIMER_A_CTL_ID__8)
#define UD_STOP TIMER_A1->CTL = (TIMER_A_CTL_MC__STOP | TIMER_A_CTL_CLR)

//Function Prototypes
void InitializeMotorPortPins(void);
void Motor_Step(uint16_t numOfSteps, uint16_t direction, uint16_t speed);

#endif
