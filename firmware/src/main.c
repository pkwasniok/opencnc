#include "rcc.c"
#include "gpio.c"
#include "usart.c"

int main(void) {
    gpio_init(RCC, GPIOB);

    gpio_set_mode(GPIOB, 13, MODE_OUTPUT);
    gpio_set_mode(GPIOB, 14, MODE_OUTPUT);
    gpio_set_mode(GPIOB, 15, MODE_OUTPUT);

    gpio_set_state(GPIOB, 13, STATE_HIGH);
    gpio_set_state(GPIOB, 14, STATE_LOW);
    gpio_set_state(GPIOB, 15, STATE_HIGH);

    return 0;
}

