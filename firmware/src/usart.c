#pragma once
#include "rcc.c"



// Refer to STM32F411CE Reference manual, page 557
struct usart {
    volatile long SR;
    volatile long DR;
    volatile long BRR;
    volatile long CR1;
    volatile long CR2;
    volatile long CR3;
    volatile long GTPR;
};

// Refer to STM32F411CE Reference manual, page XX
#define USART1 ((struct usart *) 0x40011000)
#define USART2 ((struct usart *) 0x40004400)
#define USART6 ((struct usart *) 0x40011400)



void usart_init(struct usart *usart, int baud_rate) {
    // Enable clock
    if (usart == USART1) {
        RCC->APB1ENR |= (1<<4);
    } else if (usart == USART2) {
        RCC->APB1ENR |= (1<<17);
    } else if (usart == USART6) {
        RCC->APB1ENR |= (1<<5);
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

void usart_write(struct usart *usart, char data) {
    usart->DR = data;
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

char usart_read(struct usart *usart) {
    return usart->DR;
}

int usart_tx_is_empty(struct usart *usart) {
    return usart->SR & (1<<7);
}

int usart_rx_is_not_empty(struct usart *usart) {
    return usart->SR & (1<<5);
}
