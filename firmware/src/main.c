#include "peripherals/gpio.h"
#include "peripherals/usart.h"

int main(void) {
    // Initialize peripherals
    gpio_init(RCC, GPIOA);
    usart_init(USART2, 9600);

    // Configure GPIOA2 and GPIOA3 to AF07 (USART2 Rx/Tx)
    gpio_pin_set_mode(GPIOA, 2, GPIO_MODE_ALTERNATE_FUNCTION);
    gpio_pin_set_mode(GPIOA, 3, GPIO_MODE_ALTERNATE_FUNCTION);
    gpio_pin_set_alternate_function(GPIOA, 2, GPIO_ALTERNATE_FUNCTION_07);
    gpio_pin_set_alternate_function(GPIOA, 3, GPIO_ALTERNATE_FUNCTION_07);

    usart_write_string(USART2, "Hello world\r\n");

    while (1) {
        if (!usart_rx_is_empty(USART2)) {
            char data = usart_read(USART2);
            while (!usart_tx_is_empty(USART2)) {}
            usart_write(USART2, data);
        }
    }

    return 0;
}

