#pragma once

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

#define RCC ((struct rcc *) 0x40023800)

