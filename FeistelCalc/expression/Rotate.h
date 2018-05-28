#pragma once
#ifndef ROTATE_H
#define ROTATE_H

#include "BitVector.h"

template <size_t n0, size_t n1, size_t length>
BitVector<n1 - n0 + 1> Rotate(BitVector<length> const & in, size_t shift) {
	static_assert(n0 <= n1, "Can't extract negative sized bitvector");
	static_assert(n1 <= length, "Index can't be greater than length");

	constexpr auto size = n1 - n0 + 1;
	BitVector<size> ret{0};

	size_t from = length - n1 - 1;
	for (size_t i = 0; i < size; ++i) {
		ret[i] = in[from + (i + shift) % size];
	}
	return ret;
}

#endif /* ROTATE_H */
