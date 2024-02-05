MEMORY
{
    RAM : ORIGIN = 0x20000000, LENGTH = 128K
    FLASH : ORIGIN = 0x08000000, LENGTH = 512K
}

SECTIONS
{   
    .vectors : { KEEP(*(.vectors)) } > FLASH

    .text : { *(.text*) } > FLASH

    .rodata : { *(.rodata*) } > FLASH

    .bss : {
        __bss_start__ = .;
        *(.bss*)
        __bss_end__ = .;
    } > RAM

    .data : {
        __data_start__ = .;
        *(.data*)
        __data_end__ = .;
    } > RAM AT > FLASH
    __data_source__ = LOADADDR(.data);
}

__stack_pointer__ = ORIGIN(RAM) + LENGTH(RAM);

