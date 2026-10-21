#pragma once
#include "pinout.hpp"
#include <device/device.hpp>

struct SPI_c {
  _inline_ void repeatTx(u16 n, const u8 b= 0xFF) {
    while( n-- ) {
      TxRx(b); } }

  const u8 TxRx(cu8 b) {
    const u8 toggle = fsr::usiwm0 + fsr::usics1 + fsr::usiclk + fsr::usitc;
    USIDR = b;
    USISR = fsr::usioif;

    USICR= toggle;//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();
    USICR= toggle;//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();
    USICR= toggle;//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();
    USICR= toggle;//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();
    USICR= toggle;//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();
    USICR= toggle;//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();
    USICR= toggle;//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();
    USICR= toggle;//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();

    USICR= toggle;//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();
    USICR= toggle;//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();
    USICR= toggle;//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();
    USICR= toggle;//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();
    USICR= toggle;//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();
    USICR= toggle;//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();
    USICR= toggle;//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();
    USICR= toggle;//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();//Nop();

    return USIDR; }

  void begin() {
    spi_clk_pin.oupinLo();
    spi_mosi_pin.oupinLo();
    spi_miso_pin.inpin(); }

  _inline_ auto & operator<<(const auto & data) {
    Txs((u8*)(&data), sizeof(data));
    return mSelf; }

  _inline_ auto & operator>>(auto & data) {
    Rxs((u8*)(&data), sizeof(data));
    return mSelf; }

  _inline_ void Rxs(u8 * data, const size_t sz) {
    for( u8 i= 0; i < (sz); i++ ) {
      (data)[i] = Rx(); } }

  _inline_ void Txs(u8 * data, const size_t sz) {
    for( u8 i= 0; i < (sz); i++ ) {
      Tx(data[i]); }; }

protected:
  void Tx(const u8 b) {
    TxRx(b); }

  const u8 Rx() {
    return TxRx(0xFF); } };

static SPI_c spi0;

