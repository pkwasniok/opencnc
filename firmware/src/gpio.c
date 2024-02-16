#pragma once
#include "rcc.c"

 

// Refer to STM32F411CE Reference manual, page XX
struct gpio {
    volatile long MODER;
    volatile long OTYPER;
    volatile long OSPEEDR;
    volatile long PUPDR;
    volatile long IDR;
    volatile long ODR;
    volatile long BSRR;
    volatile long LCKR;
    volatile long AFRL;
    volatile long AFRH;
};

// Refer to STM32F411CE Reference manual, page XX
#define GPIOA ((struct gpio *) 0x40020000)
#define GPIOB ((struct gpio *) 0x40020400)
#define GPIOC ((struct gpio *) 0x40020800)
#define GPIOD ((struct gpio *) 0x40020c00)
#define GPIOE ((struct gpio *) 0x40021000)
#define GPIOH ((struct gpio *) 0x40021c00)



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

#define MODE_INPUT 0
#define MODE_OUTPUT 1
#define MODE_ALTERNATE_FUNCTION 2
#define MODE_ANALOG 3

void gpio_set_mode(struct gpio *gpio, int port, int mode) {
    if (mode == MODE_INPUT) {
        gpio->MODER &= ~(0b11<<(port*2));
    } else if (mode == MODE_OUTPUT) {
        gpio->MODER |= (0b01<<(port*2));
    } else if (mode == MODE_ALTERNATE_FUNCTION) {
        gpio->MODER |= (0b10<<(port*2));
    } else if (mode == MODE_ANALOG) {
        gpio->MODER |= (0b11<<(port*2));
    }
}

#define AF_00 0b0000
#define AF_01 0b0001
#define AF_02 0b0010
#define AF_03 0b0011
#define AF_04 0b0100
#define AF_05 0b0101
#define AF_06 0b0110
#define AF_07 0b0111
#define AF_08 0b1000
#define AF_09 0b1001
#define AF_10 0b1010
#define AF_11 0b1011
#define AF_12 0b1100
#define AF_13 0b1101
#define AF_14 0b1110
#define AF_15 0b1111

void gpio_set_alternate_function(struct gpio *gpio, int port, int alternate_function) {
    if (port < 8) {
        gpio->AFRL |= (alternate_function << port*4);
    } else {
        gpio->AFRH |= (alternate_function << (port-8)*4);
    }
}

#define STATE_LOW 0
#define STATE_HIGH 1

void gpio_set_state(struct gpio *gpio, int port, int state) {
    if (state == STATE_LOW) {
        gpio->BSRR |= (1<<(port+16));
    } else if (state == STATE_HIGH) {
        gpio->BSRR |= (1<<port);
    }
}

int gpio_get_state(struct gpio *gpio, int port) {
    return gpio->IDR & (1<<port);
}

