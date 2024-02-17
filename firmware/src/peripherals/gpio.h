#ifndef GPIO_H_
#define GPIO_H_

#include "rcc.h"

// Refer to STM32F411CE Reference manual, page 163
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

// Refer to STM32F411CE Reference manual, page 38
#define GPIOA ((struct gpio *) 0x40020000)
#define GPIOB ((struct gpio *) 0x40020400)
#define GPIOC ((struct gpio *) 0x40020800)
#define GPIOD ((struct gpio *) 0x40020c00)
#define GPIOE ((struct gpio *) 0x40021000)
#define GPIOH ((struct gpio *) 0x40021c00)

// Refer to STM32F411CE Reference manual, page 161
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

// Refer to STM32F411CE Reference manual, page 158
#define GPIO_SPEED_LOW 0
#define GPIO_SPEED_MEDIUM 1
#define GPIO_SPEED_FAST 2
#define GPIO_SPEED_HIGH 3

// Refer to STM32F411CE Reference manual, page 158
#define GPIO_RESISTOR_DISABLE 0
#define GPIO_RESISTOR_PULL_UP 1
#define GPIO_RESISTOR_PULL_DOWN 2

// Initialization
void gpio_init(struct gpio *gpio);
void gpio_pin_init_output_open_drain(struct gpio *gpio, int pin);
void gpio_pin_init_output_push_pull(struct gpio *gpio, int pin);
void gpio_pin_init_input(struct gpio *gpio, int pin);
void gpio_pin_init_alternate_function(struct gpio *gpio, int pin, int alternate_function);
void gpio_pin_init_analog(struct gpio *gpio, int pin);

// Configuration
void gpio_pin_config_pull_resistor(struct gpio *gpio, int pin, int resistor);
void gpio_pin_config_output_speed(struct gpio *gpio, int pin, int speed);

// Utility
void gpio_pin_output_set_high(struct gpio *gpio, int pin);
void gpio_pin_output_set_low(struct gpio *gpio, int pin);
void gpio_pin_output_toggle(struct gpio *gpio, int pin);
int gpio_pin_output_read(struct gpio *gpio, int pin);
int gpio_pin_input_read(struct gpio *gpio, int pin);

#endif // GPIO_H_
