#include "peripherals/gpio.h"
#include "misc/print.h"

int main(void) {
    // Initialize peripherals
    gpio_init(GPIOA);
    print_init(USART2);

    // Configure GPIOA2 and GPIOA3 to AF07 (USART2 Rx/Tx)
    gpio_pin_init_alternate_function(GPIOA, 2, GPIO_ALTERNATE_FUNCTION_07);
    gpio_pin_init_alternate_function(GPIOA, 3, GPIO_ALTERNATE_FUNCTION_07);

    // Echo USART2 data
    while (1) {
        println("Hello, world!");
        for (int i=0; i<800000; i++);
    }

    return 0;
}

