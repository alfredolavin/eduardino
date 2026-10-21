#include <eduardino.hpp>
#include <util/delay.h>

void delay_us(u16 us) {
  while( us-- ) {
    _delay_us(1); } }

void delay_ms(u16 ms) {
  while( ms-- ) {
    _delay_ms(1); } }

_weak_ void setup(){

}

_weak_ void loop(){

}

int main() {
  setup();
  while(true) {
    loop(); } }

