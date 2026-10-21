#pragma once
#include <eduardino.hpp>

/*74HC595N*/
pin_0(_74HC595N_update_pin);
pin_1(_74HC595N_dat_pin);
pin_2(_74HC595N_clk_pin);

struct c74HC595N {
public:
  void begin() {
    _74HC595N_update_pin.oupinLo();
    _74HC595N_dat_pin.oupinLo();
    _74HC595N_clk_pin.oupinLo();
    update(0x00);

  }

  void update(const u8 byte) {
    u8 temp = byte;
    for (auto i : range(8)) {
      _74HC595N_clk_pin.Lo();
      _74HC595N_dat_pin = temp & 1;
      _74HC595N_clk_pin.Hi();
      temp >>= 1; }

    _74HC595N_update_pin.Hi();
    _74HC595N_update_pin.Lo(); } };
