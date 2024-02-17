#include "rcc.h"

void rcc_clock_reset_enable(struct rcc *rcc, int clock) {
    switch (clock) {
        case RCC_CLOCK_DMA2:
            rcc->AHB1RSTR |= (1<<22);
            break;
        case RCC_CLOCK_DMA1:
            rcc->AHB1RSTR |= (1<<21);
            break;
        case RCC_CLOCK_CRC:
            rcc->AHB1RSTR |= (1<<12);
            break;
        case RCC_CLOCK_GPIOH:
            rcc->AHB1RSTR |= (1<<7);
            break;
        case RCC_CLOCK_GPIOE:
            rcc->AHB1RSTR |= (1<<4);
            break;
        case RCC_CLOCK_GPIOD:
            rcc->AHB1RSTR |= (1<<3);
            break;
        case RCC_CLOCK_GPIOC:
            rcc->AHB1RSTR |= (1<<2);
            break;
        case RCC_CLOCK_GPIOB:
            rcc->AHB1RSTR |= (1<<1);
            break;
        case RCC_CLOCK_GPIOA:
            rcc->AHB1RSTR |= (1<<0);
            break;
        case RCC_CLOCK_OTGFS:
            rcc->AHB2RSTR |= (1<<7);
            break;
        case RCC_CLOCK_PWR:
            rcc->APB1RSTR |= (1<<28);
            break;
        case RCC_CLOCK_I2C3:
            rcc->APB1RSTR |= (1<<23);
            break;
        case RCC_CLOCK_I2C2:
            rcc->APB1RSTR |= (1<<22);
            break;
        case RCC_CLOCK_I2C1:
            rcc->APB1RSTR |= (1<<21);
            break;
        case RCC_CLOCK_USART2:
            rcc->APB1RSTR |= (1<<17);
            break;
        case RCC_CLOCK_SPI3:
            rcc->APB1RSTR |= (1<<15);
            break;
        case RCC_CLOCK_SPI2:
            rcc->APB1RSTR |= (1<<14);
            break;
        case RCC_CLOCK_WWDG:
            rcc->APB1RSTR |= (1<<11);
            break;
        case RCC_CLOCK_TIM5:
            rcc->APB1RSTR |= (1<<3);
            break;
        case RCC_CLOCK_TIM4:
            rcc->APB1RSTR |= (1<<2);
            break;
        case RCC_CLOCK_TIM3:
            rcc->APB1RSTR |= (1<<1);
            break;
        case RCC_CLOCK_TIM2:
            rcc->APB1RSTR |= (1<<0);
            break;
        case RCC_CLOCK_SPI5:
            rcc->APB2RSTR |= (1<<20);
            break;
        case RCC_CLOCK_TIM11:
            rcc->APB2RSTR |= (1<<18);
            break;
        case RCC_CLOCK_TIM10:
            rcc->APB2RSTR |= (1<<17);
            break;
        case RCC_CLOCK_TIM9:
            rcc->APB2RSTR |= (1<<16);
            break;
        case RCC_CLOCK_SYSCFG:
            rcc->APB2RSTR |= (1<<14);
            break;
        case RCC_CLOCK_SPI4:
            rcc->APB2RSTR |= (1<<13);
            break;
        case RCC_CLOCK_SPI1:
            rcc->APB2RSTR |= (1<<12);
            break;
        case RCC_CLOCK_SDIO:
            rcc->APB2RSTR |= (1<<11);
            break;
        case RCC_CLOCK_ADC1:
            rcc->APB2RSTR |= (1<<8);
            break;
        case RCC_CLOCK_USART6:
            rcc->APB2RSTR |= (1<<5);
            break;
        case RCC_CLOCK_USART1:
            rcc->APB2RSTR |= (1<<4);
            break;
        case RCC_CLOCK_TIM1:
            rcc->APB2RSTR |= (1<<1);
            break;
    }
}

void rcc_clock_reset_disable(struct rcc *rcc, int clock) {
    switch (clock) {
        case RCC_CLOCK_DMA2:
            rcc->AHB1RSTR &= ~(1<<22);
            break;
        case RCC_CLOCK_DMA1:
            rcc->AHB1RSTR &= ~(1<<21);
            break;
        case RCC_CLOCK_CRC:
            rcc->AHB1RSTR &= ~(1<<12);
            break;
        case RCC_CLOCK_GPIOH:
            rcc->AHB1RSTR &= ~(1<<7);
            break;
        case RCC_CLOCK_GPIOE:
            rcc->AHB1RSTR &= ~(1<<4);
            break;
        case RCC_CLOCK_GPIOD:
            rcc->AHB1RSTR &= ~(1<<3);
            break;
        case RCC_CLOCK_GPIOC:
            rcc->AHB1RSTR &= ~(1<<2);
            break;
        case RCC_CLOCK_GPIOB:
            rcc->AHB1RSTR &= ~(1<<1);
            break;
        case RCC_CLOCK_GPIOA:
            rcc->AHB1RSTR &= ~(1<<0);
            break;
        case RCC_CLOCK_OTGFS:
            rcc->AHB2RSTR &= ~(1<<7);
            break;
        case RCC_CLOCK_PWR:
            rcc->APB1RSTR &= ~(1<<28);
            break;
        case RCC_CLOCK_I2C3:
            rcc->APB1RSTR &= ~(1<<23);
            break;
        case RCC_CLOCK_I2C2:
            rcc->APB1RSTR &= ~(1<<22);
            break;
        case RCC_CLOCK_I2C1:
            rcc->APB1RSTR &= ~(1<<21);
            break;
        case RCC_CLOCK_USART2:
            rcc->APB1RSTR &= ~(1<<17);
            break;
        case RCC_CLOCK_SPI3:
            rcc->APB1RSTR &= ~(1<<15);
            break;
        case RCC_CLOCK_SPI2:
            rcc->APB1RSTR &= ~(1<<14);
            break;
        case RCC_CLOCK_WWDG:
            rcc->APB1RSTR &= ~(1<<11);
            break;
        case RCC_CLOCK_TIM5:
            rcc->APB1RSTR &= ~(1<<3);
            break;
        case RCC_CLOCK_TIM4:
            rcc->APB1RSTR &= ~(1<<2);
            break;
        case RCC_CLOCK_TIM3:
            rcc->APB1RSTR &= ~(1<<1);
            break;
        case RCC_CLOCK_TIM2:
            rcc->APB1RSTR &= ~(1<<0);
            break;
        case RCC_CLOCK_SPI5:
            rcc->APB2RSTR &= ~(1<<20);
            break;
        case RCC_CLOCK_TIM11:
            rcc->APB2RSTR &= ~(1<<18);
            break;
        case RCC_CLOCK_TIM10:
            rcc->APB2RSTR &= ~(1<<17);
            break;
        case RCC_CLOCK_TIM9:
            rcc->APB2RSTR &= ~(1<<16);
            break;
        case RCC_CLOCK_SYSCFG:
            rcc->APB2RSTR &= ~(1<<14);
            break;
        case RCC_CLOCK_SPI4:
            rcc->APB2RSTR &= ~(1<<13);
            break;
        case RCC_CLOCK_SPI1:
            rcc->APB2RSTR &= ~(1<<12);
            break;
        case RCC_CLOCK_SDIO:
            rcc->APB2RSTR &= ~(1<<11);
            break;
        case RCC_CLOCK_ADC1:
            rcc->APB2RSTR &= ~(1<<8);
            break;
        case RCC_CLOCK_USART6:
            rcc->APB2RSTR &= ~(1<<5);
            break;
        case RCC_CLOCK_USART1:
            rcc->APB2RSTR &= ~(1<<4);
            break;
        case RCC_CLOCK_TIM1:
            rcc->APB2RSTR &= ~(1<<1);
            break;
    }
}

void rcc_clock_enable(struct rcc *rcc, int clock) {
    switch (clock) {
        case RCC_CLOCK_DMA2:
            rcc->AHB1ENR |= (1<<22);
            break;
        case RCC_CLOCK_DMA1:
            rcc->AHB1ENR |= (1<<21);
            break;
        case RCC_CLOCK_CRC:
            rcc->AHB1ENR |= (1<<12);
            break;
        case RCC_CLOCK_GPIOH:
            rcc->AHB1ENR |= (1<<7);
            break;
        case RCC_CLOCK_GPIOE:
            rcc->AHB1ENR |= (1<<4);
            break;
        case RCC_CLOCK_GPIOD:
            rcc->AHB1ENR |= (1<<3);
            break;
        case RCC_CLOCK_GPIOC:
            rcc->AHB1ENR |= (1<<2);
            break;
        case RCC_CLOCK_GPIOB:
            rcc->AHB1ENR |= (1<<1);
            break;
        case RCC_CLOCK_GPIOA:
            rcc->AHB1ENR |= (1<<0);
            break;
        case RCC_CLOCK_OTGFS:
            rcc->AHB2ENR |= (1<<7);
            break;
        case RCC_CLOCK_PWR:
            rcc->APB1ENR |= (1<<28);
            break;
        case RCC_CLOCK_I2C3:
            rcc->APB1ENR |= (1<<23);
            break;
        case RCC_CLOCK_I2C2:
            rcc->APB1ENR |= (1<<22);
            break;
        case RCC_CLOCK_I2C1:
            rcc->APB1ENR |= (1<<21);
            break;
        case RCC_CLOCK_USART2:
            rcc->APB1ENR |= (1<<17);
            break;
        case RCC_CLOCK_SPI3:
            rcc->APB1ENR |= (1<<15);
            break;
        case RCC_CLOCK_SPI2:
            rcc->APB1ENR |= (1<<14);
            break;
        case RCC_CLOCK_WWDG:
            rcc->APB1ENR |= (1<<11);
            break;
        case RCC_CLOCK_TIM5:
            rcc->APB1ENR |= (1<<3);
            break;
        case RCC_CLOCK_TIM4:
            rcc->APB1ENR |= (1<<2);
            break;
        case RCC_CLOCK_TIM3:
            rcc->APB1ENR |= (1<<1);
            break;
        case RCC_CLOCK_TIM2:
            rcc->APB1ENR |= (1<<0);
            break;
        case RCC_CLOCK_SPI5:
            rcc->APB2ENR |= (1<<20);
            break;
        case RCC_CLOCK_TIM11:
            rcc->APB2ENR |= (1<<18);
            break;
        case RCC_CLOCK_TIM10:
            rcc->APB2ENR |= (1<<17);
            break;
        case RCC_CLOCK_TIM9:
            rcc->APB2ENR |= (1<<16);
            break;
        case RCC_CLOCK_SYSCFG:
            rcc->APB2ENR |= (1<<14);
            break;
        case RCC_CLOCK_SPI4:
            rcc->APB2ENR |= (1<<13);
            break;
        case RCC_CLOCK_SPI1:
            rcc->APB2ENR |= (1<<12);
            break;
        case RCC_CLOCK_SDIO:
            rcc->APB2ENR |= (1<<11);
            break;
        case RCC_CLOCK_ADC1:
            rcc->APB2ENR |= (1<<8);
            break;
        case RCC_CLOCK_USART6:
            rcc->APB2ENR |= (1<<5);
            break;
        case RCC_CLOCK_USART1:
            rcc->APB2ENR |= (1<<4);
            break;
        case RCC_CLOCK_TIM1:
            rcc->APB2ENR |= (1<<1);
            break;
    }
}

void rcc_clock_disable(struct rcc *rcc, int clock) {
    switch (clock) {
        case RCC_CLOCK_DMA2:
            rcc->AHB1ENR &= ~(1<<22);
            break;
        case RCC_CLOCK_DMA1:
            rcc->AHB1ENR &= ~(1<<21);
            break;
        case RCC_CLOCK_CRC:
            rcc->AHB1ENR &= ~(1<<12);
            break;
        case RCC_CLOCK_GPIOH:
            rcc->AHB1ENR &= ~(1<<7);
            break;
        case RCC_CLOCK_GPIOE:
            rcc->AHB1ENR &= ~(1<<4);
            break;
        case RCC_CLOCK_GPIOD:
            rcc->AHB1ENR &= ~(1<<3);
            break;
        case RCC_CLOCK_GPIOC:
            rcc->AHB1ENR &= ~(1<<2);
            break;
        case RCC_CLOCK_GPIOB:
            rcc->AHB1ENR &= ~(1<<1);
            break;
        case RCC_CLOCK_GPIOA:
            rcc->AHB1ENR &= ~(1<<0);
            break;
        case RCC_CLOCK_OTGFS:
            rcc->AHB2ENR &= ~(1<<7);
            break;
        case RCC_CLOCK_PWR:
            rcc->APB1ENR &= ~(1<<28);
            break;
        case RCC_CLOCK_I2C3:
            rcc->APB1ENR &= ~(1<<23);
            break;
        case RCC_CLOCK_I2C2:
            rcc->APB1ENR &= ~(1<<22);
            break;
        case RCC_CLOCK_I2C1:
            rcc->APB1ENR &= ~(1<<21);
            break;
        case RCC_CLOCK_USART2:
            rcc->APB1ENR &= ~(1<<17);
            break;
        case RCC_CLOCK_SPI3:
            rcc->APB1ENR &= ~(1<<15);
            break;
        case RCC_CLOCK_SPI2:
            rcc->APB1ENR &= ~(1<<14);
            break;
        case RCC_CLOCK_WWDG:
            rcc->APB1ENR &= ~(1<<11);
            break;
        case RCC_CLOCK_TIM5:
            rcc->APB1ENR &= ~(1<<3);
            break;
        case RCC_CLOCK_TIM4:
            rcc->APB1ENR &= ~(1<<2);
            break;
        case RCC_CLOCK_TIM3:
            rcc->APB1ENR &= ~(1<<1);
            break;
        case RCC_CLOCK_TIM2:
            rcc->APB1ENR &= ~(1<<0);
            break;
        case RCC_CLOCK_SPI5:
            rcc->APB2ENR &= ~(1<<20);
            break;
        case RCC_CLOCK_TIM11:
            rcc->APB2ENR &= ~(1<<18);
            break;
        case RCC_CLOCK_TIM10:
            rcc->APB2ENR &= ~(1<<17);
            break;
        case RCC_CLOCK_TIM9:
            rcc->APB2ENR &= ~(1<<16);
            break;
        case RCC_CLOCK_SYSCFG:
            rcc->APB2ENR &= ~(1<<14);
            break;
        case RCC_CLOCK_SPI4:
            rcc->APB2ENR &= ~(1<<13);
            break;
        case RCC_CLOCK_SPI1:
            rcc->APB2ENR &= ~(1<<12);
            break;
        case RCC_CLOCK_SDIO:
            rcc->APB2ENR &= ~(1<<11);
            break;
        case RCC_CLOCK_ADC1:
            rcc->APB2ENR &= ~(1<<8);
            break;
        case RCC_CLOCK_USART6:
            rcc->APB2ENR &= ~(1<<5);
            break;
        case RCC_CLOCK_USART1:
            rcc->APB2ENR &= ~(1<<4);
            break;
        case RCC_CLOCK_TIM1:
            rcc->APB2ENR &= ~(1<<1);
            break;
    }
}

