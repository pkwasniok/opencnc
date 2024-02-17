#ifndef GPIO_H_
#define GPIO_H_

#include "rcc.h"

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

// Refer to STM32F411CE Reference manual, page XX
#define GPIO_MODE_INPUT 0
#define GPIO_MODE_OUTPUT 1
#define GPIO_MODE_ALTERNATE_FUNCTION 2
#define GPIO_MODE_ANALOG 3

// Refer to STM32F411CE Reference manual, page XX
#define GPIO_ALTERNATE_FUNCTION_00 0b0000
#define GPIO_ALTERNATE_FUNCTION_01 0b0001
#define GPIO_ALTERNATE_FUNCTION_02 0b0010
#define GPIO_ALTERNATE_FUNCTION_03 0b0011
#define GPIO_ALTERNATE_FUNCTION_04 0b0100
#define GPIO_ALTERNATE_FUNCTION_05 0b0101
#define GPIO_ALTERNATE_FUNCTION_06 0b0110
#define GPIO_ALTERNATE_FUNCTION_07 0b0111
#define GPIO_ALTERNATE_FUNCTION_08 0b1000
#define GPIO_ALTERNATE_FUNCTION_09 0b1001
#define GPIO_ALTERNATE_FUNCTION_10 0b1010
#define GPIO_ALTERNATE_FUNCTION_11 0b1011
#define GPIO_ALTERNATE_FUNCTION_12 0b1100
#define GPIO_ALTERNATE_FUNCTION_13 0b1101
#define GPIO_ALTERNATE_FUNCTION_14 0b1110
#define GPIO_ALTERNATE_FUNCTION_15 0b1111

// Refer to STM32F411CE Reference manual, page XX
#define GPIO_STATE_LOW 0
#define GPIO_STATE_HIGH 1

// Initialization
void gpio_init(struct rcc *rcc, struct gpio *gpio);

// Configuration
void gpio_pin_set_mode(struct gpio *gpio, int pin, int mode);
void gpio_pin_set_alternate_function(struct gpio *gpio, int pin, int alternate_function);

// Utility
void gpio_pin_set_mode(struct gpio *gpio, int pin, int mode);
void gpio_pin_set_state(struct gpio *gpio, int pin, int state);

#endif // GPIO_H_
