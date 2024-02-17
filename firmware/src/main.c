#include "peripherals/gpio.h"
#include "peripherals/usart.h"

int main(void) {
    // Initialize peripherals
    gpio_init(GPIOA);
    gpio_init(GPIOB);
    usart_init(USART2);

    // Configure GPIOA2 and GPIOA3 to AF07 (USART2 Rx/Tx)
    gpio_pin_init_alternate_function(GPIOA, 2, GPIO_ALTERNATE_FUNCTION_07);
    gpio_pin_init_alternate_function(GPIOA, 3, GPIO_ALTERNATE_FUNCTION_07);

    // Configure GPIOB13 (B), GPIOB14 (R), GPIOB15 (G) to output
    gpio_pin_init_output_push_pull(GPIOB, 13);
    gpio_pin_init_output_push_pull(GPIOB, 14);
    gpio_pin_init_output_push_pull(GPIOB, 15);

    // Configure GPIOB12 (USER_BUTTON) to input
    gpio_pin_init_input(GPIOB, 12);

    gpio_pin_output_set_high(GPIOB, 13);
    gpio_pin_output_set_high(GPIOB, 14);
    gpio_pin_output_set_high(GPIOB, 15);

    usart_write_string(USART2, "Hello world\r\n");

    while (1) {
        if (!gpio_pin_input_read(GPIOB, 12)) {
            gpio_pin_output_toggle(GPIOB, 14);
            while(!gpio_pin_input_read(GPIOB, 12));
        }
    }

    return 0;
}

