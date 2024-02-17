#include "gpio.h"
#include "rcc.h"


// Peripheral initialization
void gpio_init(struct rcc *rcc, struct gpio *gpio) {
    if (gpio == GPIOA) {
        rcc->AHB1ENR |= (1<<0);
    } else if (gpio == GPIOB) {
        rcc->AHB1ENR |= (1<<1);
    } else if (gpio == GPIOC) {
        rcc->AHB1ENR |= (1<<2);
    } else if (gpio == GPIOD) {
        rcc->AHB1ENR |= (1<<3);
    } else if (gpio == GPIOE) {
        rcc->AHB1ENR |= (1<<4);
    } else if (gpio == GPIOH) {
        rcc->AHB1ENR |= (1<<7);
    }
}


// Configuration
void gpio_pin_set_mode(struct gpio *gpio, int pin, int mode) {
    if (mode == GPIO_MODE_INPUT) {
        gpio->MODER &= ~(0b11<<(pin*2));
    } else if (mode == GPIO_MODE_OUTPUT) {
        gpio->MODER |= (0b01<<(pin*2));
    } else if (mode == GPIO_MODE_ALTERNATE_FUNCTION) {
        gpio->MODER |= (0b10<<(pin*2));
    } else if (mode == GPIO_MODE_ANALOG) {
        gpio->MODER |= (0b11<<(pin*2));
    }
}

void gpio_pin_set_alternate_function(struct gpio *gpio, int pin, int alternate_function) {
    if (pin < 8) {
        gpio->AFRL |= (alternate_function << pin*4);
    } else {
        gpio->AFRH |= (alternate_function << (pin-8)*4);
    }
}


// Utility
void gpio_pin_set_state(struct gpio *gpio, int pin, int state) {
    if (state == GPIO_STATE_LOW) {
        gpio->BSRR |= (1<<(pin+16));
    } else if (state == GPIO_STATE_HIGH) {
        gpio->BSRR |= (1<<pin);
    }
}

int gpio_pin_get_state(struct gpio *gpio, int pin) {
    return gpio->IDR & (1<<pin);
}

