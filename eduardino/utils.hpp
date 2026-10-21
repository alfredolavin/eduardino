#pragma once
#include <eduardino_int_types.hpp>
#include <eduardino_defines.hpp>

template<const u64 data, int test_byte = 8>
struct _smallest_int{
	using type = std::conditional_t< (bool)(data & (u64)0xFFL << (test_byte*8)),
		std::tuple_element_t<test_byte, std::tuple<u8, u16, u24, u32, u64, u64, u64, u64>>,
		typename _smallest_int<data, test_byte - 1>::type>;};

template<u64 data>
struct _smallest_int<data, -1>{
	using type = u64;/* Value is 0 */};

template<const u64 data> using smallest_int = typename _smallest_int<data>::type;

const smallest_int<512> test = 15; 