#include <avr/io.h>
#include <util/delay.h>

#define millSecDelay 100

int main (void) {
  DDRB |=(1<<5);
  while(1) {
    PORTB |= (1<<5);
    _delay_ms(millSecDelay);
    PORTB &= ~(1<<5);
    _delay_ms(millSecDelay);
  }
  return 0;
}
