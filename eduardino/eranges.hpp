#pragma once
#include <eduardino_int_types.hpp>
#include <ranges>
#include <concepts>
#include <math.h>
#include <type_traits>
#include <algorithm>

// template<u64 value> struct _smaller_int{
//     static constexpr size_t n_bytes = (log(value)/log(2)/8);
//   using type = std::tuple_element_t<(log(value)/log(2)/8), std::tuple<u8, u16, u24, u32, u64>>;
//     };

template<u64 value> using smaller_int_t = std::tuple_element_t<(size_t)(logf(value)/logf(2)/8), std::tuple<u8, u16, u24, u32, u64, u64, u64>>;

inline auto constexpr pyRange(cu16 & _from, cu16 & _to, cu16 & step) {
  struct Iter {
    u16 count;
    cu16 step;
    bool operator!=(const u16 &rhs) const {
      return count<=rhs; } // oh!!!
    void operator++() {
      count+=step; }
    auto operator*() const {
      return count; } };

  struct _range {
    cu16 from_count;
    cu16 to_count;
    cu16 step;
    auto begin() const {
      return Iter{from_count, step }; }
    auto end() const {
      return to_count; } };

  return _range{std::min(_from, _to),
                std::max(_from, _to),
                step }; }

inline constexpr auto pyRange(cu16 & _from, cu16 & _to) {
  return pyRange(_from, _to, (cu16)1); }

inline constexpr auto pyRange(cu16 & _to) {
  return pyRange((cu16)0, _to, (cu16)1); }


//#define define_range(x, letter, int_type) int_type letter = 0; letter < (x); letter++
#define define_range(to, letter, int_type) int_type letter : pyRange(to)

#define iRange16(x) define_range(x, i, u16)
#define iRange32(x) define_range(x, i, u32)
#define iRange(x) define_range(x, i, u8)//auto i : pyRange(x)
#define jRange(x) define_range(x, j, u8)
#define kRange(x) define_range(x, k, u8)
#define xRange(_x) define_range(_x, x, u8)
#define yRange(x) define_range(x, y, u8)
#define zRange(x) define_range(x, z, u8)

#define iRangeLen(x) define_range(countof(x), i, u8)
#define jRangeLen(x) define_range(countof(x), j, u8)
#define kRangeLen(x) define_range(countof(x), k, u8)

#define iRangeLen16(x) define_range(countof(x), i, u16)
#define jRangeLen16(x) define_range(countof(x), j, u16)
#define kRangeLen16(x) define_range(countof(x), k, u16)






