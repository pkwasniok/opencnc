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

    // Set baud rate (9600 bps)
    // TODO: Calculate USARTDIV value programatically
    usart->BRR = (104<<4) | (3<<0);

    // Enable receiver
    usart->CR1 |= (0b1<<2);

    // Enable transmitter
    usart->CR1 |= (0b1<<3);
}


// Configuration
void usart_config_tx_enable(struct usart *usart) {
    // Enable transmitter
    usart->CR1 |= (0b1<<3);
}

void usart_config_tx_disable(struct usart *usart) {
    // Disable transmitter
    usart->CR1 &= ~(0b1<<3);
}

void usart_config_rx_enable(struct usart *usart) {
    // Enable receiver
    usart->CR1 |= (0b1<<2);
}

void usart_config_rx_disable(struct usart *usart) {
    usart->CR1 &= ~(0b1<<2);
}


// Utility
void usart_write(struct usart *usart, char data) {
    // Write to data register
    usart->DR = data;
}

void usart_write_buffer(struct usart *usart, char buffer[], int length) {
    for (int i=0; i<length; i++) {
        while (!usart_tx_is_buffer_empty(usart)) {}
        usart_write(usart, buffer[i]);
    }
}

char usart_read(struct usart *usart) {
    // Read data register
    return usart->DR;
}

int usart_tx_is_buffer_empty(struct usart *usart) {
    // Read tx buffer empty flag from status register
    return usart->SR & (1<<7);
}

int usart_tx_is_transmission_complete(struct usart *usart) {
    // Read transmission complete flag from status register
    return usart->SR & (1<<6);
}

int usart_rx_is_buffer_not_empty(struct usart *usart) {
    // Read rx buffer not empty flag from status register
    return usart->SR & (1<<5);
}

