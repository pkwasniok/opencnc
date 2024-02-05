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

// Refer to STM32F411CE Reference manual, page 
#define USART1 ((struct usart *) 0x40011000)
#define USART2 ((struct usart *) 0x40004400)
#define USART6 ((struct usart *) 0x40011400)

void usart_init(struct usart *usart, int baud_rate) {
    
}

