#include "gpio.h"
#include "rcc.h"


// Peripheral initialization
void gpio_init(struct gpio *gpio) {
    // Enable peripheral clock
    if (gpio == GPIOA) {
        rcc_clock_enable(RCC, RCC_CLOCK_GPIOA);
    } else if (gpio == GPIOB) {
        rcc_clock_enable(RCC, RCC_CLOCK_GPIOB);
    } else if (gpio == GPIOC) {
        rcc_clock_enable(RCC, RCC_CLOCK_GPIOC);
    } else if (gpio == GPIOD) {
        rcc_clock_enable(RCC, RCC_CLOCK_GPIOD);
    } else if (gpio == GPIOE) {
        rcc_clock_enable(RCC, RCC_CLOCK_GPIOE);
    } else if (gpio == GPIOH) {
        rcc_clock_enable(RCC, RCC_CLOCK_GPIOH);
    }
}

void gpio_pin_init_output_push_pull(struct gpio *gpio, int pin) {
    // Set mode to output
    gpio->MODER |= (0b01<<(pin*2));

    // Set type to push-pull
    gpio->OTYPER &= ~(0b1<<pin);
}

void gpio_pin_init_output_open_drain(struct gpio *gpio, int pin) {
    // Set mode to output
    gpio->MODER |= (0b01<<(pin*2));

    // Set type to open-drain
    gpio->OTYPER |= (0b1<<pin);
}

void gpio_pin_init_input(struct gpio *gpio, int pin) {
    // Set mode to input
    gpio->MODER |= (0b00<<(pin*2));
}

void gpio_pin_init_alternate_function(struct gpio *gpio, int pin, int alternate_function) {
    // Set mode to alternate function
    gpio->MODER |= (0b10<<(pin*2));

    // Set alternate function
    // Configuration of pins 0-7 is done in AFRL register, 8-15 is done in AFRH register
    if (pin <= 7) {
        gpio->AFRL |= (alternate_function<<(pin*4));
    } else {
        gpio->AFRH |= (alternate_function<<((pin-8)*4));
    }
}

void gpio_pin_init_analog(struct gpio *gpio, int pin) {
    // Set mode to analog
    gpio->MODER |= (0b11<<(pin*2));
}


// Configuration
void gpio_pin_config_pull_resistor(struct gpio *gpio, int pin, int resistor) {
    switch (resistor) {
        case GPIO_RESISTOR_DISABLE:
            // Disable internal pull-up and pull-down resistor
            gpio->PUPDR &= ~(0b11<<(pin*2));
            break;
        case GPIO_RESISTOR_PULL_UP:
            // Enable internal pull-up resistor
            gpio->PUPDR |= (0b01<<(pin*2));
            break;
        case GPIO_RESISTOR_PULL_DOWN:
            // Enable internal pull-down resistor
            gpio->PUPDR |= (0b10<<(pin*2));
            break;
    }
}

void gpio_pin_config_output_speed(struct gpio *gpio, int pin, int speed) {
    switch (speed) {
        case GPIO_SPEED_LOW:
            // Set output speed to low (1/4)
            gpio->OSPEEDR &= ~(0b11<<(pin*2));
            break;
        case GPIO_SPEED_MEDIUM:
            // Set output speed to medium (2/4)
            gpio->OSPEEDR |= (0b01<<(pin*2));
            break;
        case GPIO_SPEED_FAST:
            // Set output speed to fast (3/4)
            gpio->OSPEEDR |= (0b10<<(pin*2));
            break;
        case GPIO_SPEED_HIGH:
            // Set output speed to high (4/4)
            gpio->OSPEEDR |= (0b11<<(pin*2));
            break;
    }
}


// Utility
void gpio_pin_output_set_low(struct gpio *gpio, int pin) {
    // Set pin state to low
    gpio->BSRR |= (0b1<<(pin+16));
}

void gpio_pin_output_set_high(struct gpio *gpio, int pin) {
    // Set pin state to high
    gpio->BSRR |= (0b1<<pin);
}

void gpio_pin_output_toggle(struct gpio *gpio, int pin) {
    // Toggle pin state
    gpio->ODR ^= (0b1<<pin);
}

int gpio_pin_output_read(struct gpio *gpio, int pin) {
    // Read ODR bit corresponding to ping
    return gpio->ODR & (0b1<<pin);
}

int gpio_pin_input_read(struct gpio *gpio, int pin) {
    // Read IDR pin corresponding to pin
    return gpio->IDR & (0b1<<pin);
}

