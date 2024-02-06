#pragma once
#include "rcc.c"

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
#define MODE_ALTERNATE 2
#define MODE_ANALOG 3

void gpio_set_mode(struct gpio *gpio, int port, int mode) {
    if (mode == MODE_INPUT) {
        gpio->MODER &= ~(0b11<<(port*2));
    } else if (mode == MODE_OUTPUT) {
        gpio->MODER |= (0b01<<(port*2));
    } else if (mode == MODE_ALTERNATE) {
        gpio->MODER |= (0b10<<(port*2));
    } else if (mode == MODE_ANALOG) {
        gpio->MODER |= (0b11<<(port*2));
    }
}

#define STATE_LOW 0
#define STATE_HIGH 1

void gpio_set_state(struct gpio *gpio, int port, int state) {
    if (state == STATE_LOW) {
        gpio->BSRR |= (1<<(port*2));
    } else if (state == STATE_HIGH) {
        gpio->BSRR |= (1<<port);
    }
}

int gpio_get_state(struct gpio *gpio, int port) {
    return gpio->IDR & (1<<port);
}

