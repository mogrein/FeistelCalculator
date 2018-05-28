#pragma once
#ifndef SBOX_H
#define SBOX_H

#include <array>
#include <bitset>
#include "BitVector.h"

template <size_t length, size_t out_length>
class Sbox {
	std::array<size_t, length> _data;

public:
	Sbox(std::array<size_t, length> const & data) : _data(data) {}

	template<int in_length>
	BitVector<out_length> operator()(BitVector<in_length> const& in, size_t from, size_t to) const {		
		auto i = ((in._data << from) >> (in_length - (to - from + 1))).to_ulong();
		auto tmp = _data[i];
		return { std::bitset<out_length>(tmp) };
	}
};

#endif /* SBOX_H */
