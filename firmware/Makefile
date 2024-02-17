CFLAGS ?= -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -W -Wall -g
LDFLAGS ?= -T link.ld -nostdlib

build: firmware.bin
	@echo " -- Build: done"

upload: build
	st-flash write build/firmware.bin 0x08000000
	@echo " -- Upload: done"

clean:
	rm -r build/*

firmware.bin: firmware.elf
	arm-none-eabi-objcopy -O binary build/firmware.elf build/firmware.bin

firmware.elf: main.o reset.o rcc.o gpio.o usart.o print.o
	arm-none-eabi-gcc $(LDFLAGS) $(CFLAGS) build/reset.o build/main.o build/rcc.o build/gpio.o build/usart.o build/print.o -o build/firmware.elf

main.o:
	arm-none-eabi-gcc $(CFLAGS) -c src/main.c -o build/main.o

reset.o:
	arm-none-eabi-gcc $(CFLAGS) -c src/reset.c -o build/reset.o

rcc.o:
	arm-none-eabi-gcc $(CFLAGS) -c src/peripherals/rcc.c -o build/rcc.o

gpio.o:
	arm-none-eabi-gcc $(CFLAGS) -c src/peripherals/gpio.c -o build/gpio.o

usart.o:
	arm-none-eabi-gcc $(CFLAGS) -c src/peripherals/usart.c -o build/usart.o

print.o:
	arm-none-eabi-gcc $(CFLAGS) -c src/misc/print.c -o build/print.o

