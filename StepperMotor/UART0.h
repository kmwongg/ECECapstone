/*
 * UART0.h
 *
 *  Created on: Oct 4, 2023
 *      Author: kou
 */

#ifndef UART0_H_
#define UART0_H_


#include "msp.h"


void InitializeUART0(void);
void SendChar(char c);

void SendString(char* str);
char ReceiveChar();
const char* ReceiveString();

#endif /* UART0_H_ */
