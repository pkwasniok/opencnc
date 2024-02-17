#include "usart.h"
#include "rcc.h"


// Initialization
void usart_init(struct usart *usart) {
    // Enable peripheral clock
    if (usart == USART1) {
        rcc_clock_enable(RCC, RCC_CLOCK_USART1);
    } else if (usart == USART2) {
        rcc_clock_enable(RCC, RCC_CLOCK_USART2);
    } else if (usart == USART6) {
        rcc_clock_enable(RCC, RCC_CLOCK_USART6);
    }

    // Enable usart
    usart->CR1 |= (1<<13);

    // Set word shape (1 start, 8 data, n stop)
    usart->CR1 |= (0b0<<12); // 8 data bits
    usart->CR2 |= (0b00<<12); // 1 stop bit

    // Set baud rate
    usart->BRR = (104<<4) | (3<<0);

    // Enable transmitter
    usart->CR1 |= (1<<3);

    // Enable receiver
    usart->CR1 |= (1<<2);
}


// Utility
void usart_write(struct usart *usart, char data) {
    usart->DR = data;
}

char usart_read(struct usart *usart) {
    return usart->DR;
}

void usart_write_buffer(struct usart *usart, char buffer[], int length) {
    for (int i=0; i<length; i++) {
        while (!usart_tx_is_empty(usart)) {}
        usart_write(usart, buffer[i]);
    }
}

void usart_write_string(struct usart *usart, char string[]) {
    int i = 0;
    while (string[i] != '\0') {
        while (!usart_tx_is_empty(usart)) {}
        usart_write(usart, string[i]);
        i += 1;
    }
}

int usart_tx_is_empty(struct usart *usart) {
    return usart->SR & (1<<7);
}

int usart_rx_is_empty(struct usart *usart) {
    return !(usart->SR & (1<<5));
}

