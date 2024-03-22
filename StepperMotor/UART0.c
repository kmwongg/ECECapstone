/*
 * UART0.c
 *
 *  Created on: Oct 4, 2023
 *      Author: kou
 */



#include "UART0.h"
char r;
char rec;
char *st ;
uint8_t i = 0;

void InitializeUART0(void) {
    EUSCI_A0->CTLW0 |= EUSCI_A_CTLW0_SWRST;             // Reset mode to set up
    EUSCI_A0->MCTLW = 0x0201;              // settings on page919 TRM
    EUSCI_A0->CTLW0 = 0x0081;         // TRM pg 924
    EUSCI_A0->BRW = 78;
    P1->SEL0 |= 0x0C;                 // Use P1.3, P1.2 for UART. pg 7 and 138 in datasheet
    P1->SEL1 &= ~0x0C;
    EUSCI_A0->CTLW0 &= ~1;            // Disable reset mode
}
void SendChar(char c){

    while(!(EUSCI_A0->IFG & 0x02)) { }  // waiting for transfer buffer to empty
        EUSCI_A0->TXBUF = c;              // load next char

}

void SendString(char* str){
    while (*str != 0)            //sends characters one by one
    SendChar(*str++);
}

char ReceiveChar(){

    while(!(EUSCI_A0->IFG & 0x01)) { }  //waiting for buffer to receive 1 char
        rec = EUSCI_A0->RXBUF;              // storing received char

        return rec;
}

// This doesn't work yet. I haven't figured out a good way to do it
const char* ReceiveString(){
*st = " ";
    while (i < 3){
    strcat(*st, ReceiveChar());
    i++;
    }
    return st;
}

