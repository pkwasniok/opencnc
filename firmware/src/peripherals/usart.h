#ifndef USART_H_
#define USART_H_

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

// Refer to STM32F411CE Reference manual, page 38
#define USART1 ((struct usart *) 0x40011000)
#define USART2 ((struct usart *) 0x40004400)
#define USART6 ((struct usart *) 0x40011400)

// Initialization
void usart_init(struct usart *usart);

// Configuration
void usart_config_tx_enable(struct usart *usart);
void usart_config_tx_disable(struct usart *usart);
void usart_config_rx_enable(struct usart *usart);
void usart_config_rx_disable(struct usart *usart);

// Utility
void usart_write(struct usart *usart, char byte);
void usart_write_buffer(struct usart *usart, char buffer[], int length);
char usart_read(struct usart *usart);
int usart_tx_is_buffer_empty(struct usart *usart);
int usart_tx_is_transmission_complete(struct usart *usart);
int usart_rx_is_buffer_not_empty(struct usart *usart);

#endif // USART_H_

