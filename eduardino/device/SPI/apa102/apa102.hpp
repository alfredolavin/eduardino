#pragma once
#include <eduardino.hpp>
#include "../spi.hpp"

struct color_t {
  u8 b, g, r; };

struct brightness_t {
  unsigned value:5;
  const unsigned ones:3 = 0b111; };

struct package_t {
  brightness_t brightness;
  color_t color; };

struct APA102 {

  void begin() {
    mSPI.begin(); }

  void update(const color_t colors[]) {
    startFrame();
    for(iRange(length)) {
      sendFrame(colors[i]); }
    endFrame(); }

  void update(const color_t color) {
    startFrame();
    for(iRange(length)) {
      sendFrame(color); }
    endFrame(); }

  _inline_ void sendFrame(const color_t color) {
    mSPI << (package_t) {
      brightness, color }; }

  void startFrame() {
    mSPI.repeatTx(4, 0x00); }

  void endFrame() {
    mSPI.repeatTx((length + 14)/16, 0x00); }

  color_t HSV2RGB(u16 h, u8 s, u8 v) {
    u8 f = (h % 60) * 255 / 60;
    u8 p = (255 - s) * (u16) v / 255;
    u8 q = (255 - f * (u16) s / 255) * (u16) v / 255;
    u8 t = (255 - (255 - f) * (u16) s / 255) * (u16) v / 255;
    u8 r = 0, g = 0, b = 0;
    switch ((h / 60) % 6) {
    case 0: r = v; g = t; b = p; break;
    case 1: r = q; g = v; b = p; break;
    case 2: r = p; g = v; b = t; break;
    case 3: r = p; g = q; b = v; break;
    case 4: r = t; g = p; b = v; break;
    case 5: r = v; g = p; b = q; break; }
    return (color_t ) {
      r, g, b } ; }

  static constexpr SPI_c & mSPI= spi0;
  const u8 length;
  brightness_t brightness = {value: 0b11111 };

  APA102(u8 _length):length(_length) {}

  void operator <<(const color_t colors[]) {
    mSelf.update(colors); };
};
