TARGET = main
BAUD = 115200
avrType  = atmega328p
programmerType = arduino
avrFreq = 16000000
programmingPort = /dev/ttyUSB0

CFLAGS  = -DF_CPU=$(avrFreq) -mmcu=$(avrType) -Wall -Werror -Wextra -Os
OBJECTS = $(patsubst %.c,%.o,$(wildcard *.c))

.PHONY: flash clean

all: $(TARGET).hex

$(TARGET).hex: $(TARGET).elf
	avr-objcopy -j .text -j .data -O ihex $^ $@

$(TARGET).elf: $(OBJECTS)
	avr-gcc -o $@ $^ $(CFLAGS)

%.o: %.c
	avr-gcc -c $< -o $@ $(CFLAGS)

flash: $(TARGET).hex
	avrdude -p $(avrType) -c $(programmerType) -P $(programmingPort) -b $(BAUD) -v -U flash:w:$<

clean:
	rm -f $(TARGET).hex $(TARGET).elf $(OBJECTS)
