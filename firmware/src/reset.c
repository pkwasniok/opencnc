// extern declarations
extern void __stack_pointer__(void);
extern int main(void);

// reset handler
__attribute__((naked, noreturn)) void __reset(void) {
    // sections boundaries pointers
    extern long __bss_start__, __bss_end__, __data_start__, __data_end__, __data_source__;

    // initialize bss section (fill bss with zeroes)
    long *bss_dst = &__bss_start__;
    while (bss_dst < &__bss_end__) {
        *bss_dst++ = 0;
    }

    // initialize data section (copy data from flash to ram)
    long *data_dst = &__data_start__;
    long *data_src = &__data_source__;
    while (data_dst < &__data_end__) {
        *data_dst++ = *data_src++;
    }

    main();

    while (1);
}

// vectors table (refer to Cortex-M and STM32 docs)
__attribute__((section(".vectors"))) void (*const vectors[100])(void) = {
    __stack_pointer__,
    __reset,
};

