#pragma once
#ifndef CONFIGS_SIMPLE_H
#define CONFIGS_SIMPLE_H

namespace {
	constexpr auto r = 16;
	constexpr auto n = 64;
	constexpr auto k = 64;

	BitVector<32> K(BitVector<k> const & key, size_t i) {
		return Rotate<0, 31>(key + key, 0);
	}

	BitVector<n / 2> F(BitVector<n / 2> r, BitVector<32> k) {
		return k;
	}
}

#endif /* CONFIGS_SIMPLE_H */
