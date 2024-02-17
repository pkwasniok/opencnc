#include "print.h"
#include "../peripherals/usart.h"

struct usart *PRINT_USART = 0;

void print_init(struct usart *usart) {
    PRINT_USART = usart;
    usart_init(PRINT_USART);
}

void print(char string[]) {
    int i = 0;
    while (string[i++] != '\0') {
        while (usart_tx_is_buffer_empty(PRINT_USART));
        usart_write(PRINT_USART, string[i]);
    }
}

void println(char string[]) {
    print(string);
    while (usart_tx_is_buffer_empty(PRINT_USART));
    usart_write(PRINT_USART, '\r');
    while (usart_tx_is_buffer_empty(PRINT_USART));
    usart_write(PRINT_USART, '\n');
}

void printf(char string[]) {

}

void printlnf(char string[]) {

}

