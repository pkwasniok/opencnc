#include "peripherals/gpio.h"
#include "peripherals/usart.h"

int main(void) {
    // Initialize peripherals
    gpio_init(GPIOA);
    usart_init(USART2);

    // Configure GPIOA2 and GPIOA3 to AF07 (USART2 Rx/Tx)
    gpio_pin_init_alternate_function(GPIOA, 2, GPIO_ALTERNATE_FUNCTION_07);
    gpio_pin_init_alternate_function(GPIOA, 3, GPIO_ALTERNATE_FUNCTION_07);

    // Echo USART2 data
    while (1) {
        while (usart_rx_is_buffer_not_empty(USART2)) {
            char data = usart_read(USART2);
            usart_write(USART2, data);
        }
    }

    return 0;
}

