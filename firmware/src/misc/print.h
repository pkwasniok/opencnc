#ifndef PRINT_H_
#define PRINT_H_

#include "../peripherals/usart.h"

// Initialization
void print_init(struct usart *usart);

// Utility
void print(char string[]);
void println(char string[]);
void printf(char string[]);
void printlnf(char string[]);

#endif // PRINT_H_

