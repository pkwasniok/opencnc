#ifndef RCC_H_
#define RCC_H_

// Refer to STM32F411CE Reference manual, page XX
struct rcc {
    volatile long CR;
    volatile long PLLCFGR;
    volatile long CFGR;
    volatile long CIR;
    volatile long AHB1RSTR;
    volatile long AHB2RSTR;
    volatile long reserved1;
    volatile long reserved2;
    volatile long APB1RSTR;
    volatile long APB2RSTR;
    volatile long reserved3;
    volatile long reserved4;
    volatile long AHB1ENR;
    volatile long AHB2ENR;
    volatile long reserved5;
    volatile long reserved6;
    volatile long APB1ENR;
    volatile long APB2ENR;
    volatile long reserved7;
    volatile long reserved8;
    volatile long AHB1LPENR;
    volatile long AHB2LPENR;
    volatile long reserved9;
    volatile long reserved10;
    volatile long APB1LPENR;
    volatile long APB2LPENR;
    volatile long reserved11;
    volatile long reserved12;
    volatile long BDCR;
    volatile long CSR;
    volatile long reserved13;
    volatile long reserved14;
    volatile long SSCGR;
    volatile long PLLI2SCFGR;
    volatile long reserved15;
    volatile long DCKCFGR;
};

// Refer to STM32F411CE Reference manual, page XX
#define RCC ((struct rcc *) 0x40023800)

// Refer to STM32F411CE Reference manual, page XX
#define RCC_CLOCK_DMA2 1
#define RCC_CLOCK_DMA1 2
#define RCC_CLOCK_CRC 3
#define RCC_CLOCK_GPIOA 4
#define RCC_CLOCK_GPIOB 5
#define RCC_CLOCK_GPIOC 6
#define RCC_CLOCK_GPIOD 7
#define RCC_CLOCK_GPIOE 8
#define RCC_CLOCK_GPIOH 9
#define RCC_CLOCK_OTGFS 10
#define RCC_CLOCK_PWR 11
#define RCC_CLOCK_I2C3 12
#define RCC_CLOCK_I2C2 13
#define RCC_CLOCK_I2C1 14
#define RCC_CLOCK_USART2 15
#define RCC_CLOCK_SPI3 16
#define RCC_CLOCK_SPI2 17
#define RCC_CLOCK_WWDG 18
#define RCC_CLOCK_TIM5 19
#define RCC_CLOCK_TIM4 20
#define RCC_CLOCK_TIM3 21
#define RCC_CLOCK_TIM2 22
#define RCC_CLOCK_SPI5 23
#define RCC_CLOCK_TIM11 24
#define RCC_CLOCK_TIM10 25
#define RCC_CLOCK_TIM9 26
#define RCC_CLOCK_SYSCFG 27
#define RCC_CLOCK_SPI4 28
#define RCC_CLOCK_SPI1 29
#define RCC_CLOCK_SDIO 30
#define RCC_CLOCK_ADC1 31
#define RCC_CLOCK_USART6 32
#define RCC_CLOCK_USART1 33
#define RCC_CLOCK_TIM1 34


// Utilities
void rcc_clock_reset_enable(struct rcc *rcc, int clock);
void rcc_clock_reset_disable(struct rcc *rcc, int clock);
void rcc_clock_enable(struct rcc *rcc, int clock);
void rcc_clock_disable(struct rcc *rcc, int clock);

#endif // RCC_H_
