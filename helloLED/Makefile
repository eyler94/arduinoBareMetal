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

%.o: %.c
	avr-gcc -c $< -o $@ $(CFLAGS)

$(TARGET).elf: $(OBJECTS)
	avr-gcc -o $@ $^ $(CFLAGS)

$(TARGET).hex: $(TARGET).elf
	avr-objcopy -j .text -j .data -O ihex $^ $@

flash: $(TARGET).hex
	# avrdude -p $(avrType) -c $(programmerType) -P $(programmingPort) -b $(BAUD) -v -U flash:w:$<
	avrdude -F -V -c $(programmerType) -p $(avrType) -P $(programmingPort) -b $(BAUD) -U flash:w:$< #blinkLED.hex

clean:
	rm -f $(TARGET).hex $(TARGET).elf $(OBJECTS)
