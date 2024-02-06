CFLAGS ?= -mcpu=cortex-m4 -mthumb -W -Wall
LDFLAGS ?= -T link.ld -nostdlib

firmware.bin: firmware.elf
	arm-none-eabi-objcopy -O binary build/firmware.elf build/firmware.bin

firmware.elf: main.o reset.o
	arm-none-eabi-gcc $(LDFLAGS) $(CFLAGS) build/reset.o build/main.o -o build/firmware.elf

main.o:
	arm-none-eabi-gcc $(CFLAGS) -c src/main.c -o build/main.o

reset.o:
	arm-none-eabi-gcc $(CFLAGS) -c src/reset.c -o build/reset.o

clean:
	rm -r build/*

