# README... if you want... you don't have to
## Intro
This is a scratchpad of sorts for me to resharpen my skills in bare metal embedded programming. No promises about how pretty this code it, but I hope it will become so (and keep its functionality.)

My main goals are to be able to run basic arduino sketches using just C (and some headers...) and compile it with Cmake and flash using the terminal. Wish me luck!

![Electro Boom is the best... FuLL BrIDge ReCTiFIER](https://media.tenor.com/KVq7WxhhrUgAAAAd/electro-boom.gif) 


## Necessary packages for current usage
```sh
sudo apt install gcc-avr binutils-avr avr-libc avrdude
```

## Method to determine Arduino connection
```sh
# Unplug Arduino
ls /dev/tty*
# Plug in Arduino
ls /dev/tty*
# The difference is the Arduino target!
```

## Compiling

Navigate to the proper directory.
```sh
make # This will compile the code.
make flash # This will compile and flash the Arduino.
```

<!-- ## Current compilation step until I get a working Makefile or CMAKELISTS
```sh
avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o blinkLED.o blinkLED.c
avr-gcc -mmcu=atmega328p blinkLED.o -o blinkLED.exe
avr-objcopy -O ihex -R .eeprom blinkLED.exe blinkLED.hex
avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyUSB0 -b 115200 -U flash:w:blinkLED.hex
``` -->

## Thanks
Big thanks to the following resources:
* https://create.arduino.cc/projecthub/milanistef/introduction-to-bare-metal-programming-in-arduino-uno-f3e2b4
* https://fabacademy.org/2022/labs/charlotte/students/aaron-logan/images/week09/Bare%20Metal%20Programming%20.pdf
* http://www.florentflament.com/blog/arduino-hello-world-without-ide.html
* https://maumagnaguagno.github.io/baremetal