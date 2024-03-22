#ifndef CLOCK_H_
#define CLOCK_H_

#include "msp.h"
#include "Defines.h"
#include <stdbool.h>

// Function prototypes
bool InitializeClockSystem(void);

void Clock_Delay(uint32_t n);


#endif /* CLOCK_H_ */
