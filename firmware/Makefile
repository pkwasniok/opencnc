CFLAGS ?= -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -W -Wall -g
LDFLAGS ?= -T link.ld -nostdlib

build: firmware.bin

upload: build
	st-flash write build/firmware.bin 0x08000000

clean:
	rm -r build/*

firmware.bin: firmware.elf
	arm-none-eabi-objcopy -O binary build/firmware.elf build/firmware.bin

firmware.elf: main.o reset.o
	arm-none-eabi-gcc $(LDFLAGS) $(CFLAGS) build/reset.o build/main.o -o build/firmware.elf

main.o:
	arm-none-eabi-gcc $(CFLAGS) -c src/main.c -o build/main.o

reset.o:
	arm-none-eabi-gcc $(CFLAGS) -c src/reset.c -o build/reset.o

