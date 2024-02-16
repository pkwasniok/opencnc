#include "rcc.c"
#include "gpio.c"
#include "usart.c"

int main(void) {
    // Initialize peripherals
    gpio_init(RCC, GPIOA);
    usart_init(USART2, 9600);

    // Setup USART2 Tx and Rx GPIOs
    gpio_set_mode(GPIOA, 2, MODE_ALTERNATE_FUNCTION);
    gpio_set_mode(GPIOA, 3, MODE_ALTERNATE_FUNCTION);
    gpio_set_alternate_function(GPIOA, 2, AF_07);
    gpio_set_alternate_function(GPIOA, 3, AF_07);

    usart_write_string(USART2, "Hello world\r\n");

    while (1) {
        if (usart_rx_is_not_empty(USART2)) {
            char data = usart_read(USART2);
            while (!usart_tx_is_empty(USART2)) {}
            usart_write(USART2, data);
        }
    }

    return 0;
}

