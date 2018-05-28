#pragma once
#ifndef SUBSTITUTION_H
#define SUBSTITUTION_H

#include <array>
#include "BitVector.h"

template<size_t length>
class Substitution {
	const std::array<size_t, length> _data;

public:
	Substitution(std::array<size_t, length> const & data) : _data(data) {}

	template<int in_length>
	BitVector<length> operator()(BitVector<in_length> const& in) const {
		std::bitset<length> result;
		for (size_t i = 0; i < length; ++i) {
			result[length - i - 1] = in[in_length - (_data[i] - 1) - 1];
		}
		return { result };
	}
};

#endif /* SUBSTITUTION_H */
