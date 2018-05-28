#pragma once
#ifndef BITVECTOR_H
#define BITVECTOR_H


#include <iostream>
#include <bitset>
#include <string>

template <size_t length>
class BitVector {
	std::bitset<length> _data;
public:

	BitVector(std::bitset<length> const & data) : _data(data) {}
	BitVector(BitVector const & data) : _data(data._data) {}
	
	constexpr bool operator[](size_t i) const {
		return _data[i];
	}

	inline auto operator[](size_t i) {
		return _data[i];
	}

	friend inline BitVector operator+ (const BitVector& first, const BitVector& second) {
		return { first._data ^ second._data };
	}

	friend inline BitVector operator* (BitVector const & first, BitVector const & second) {
		return { (first._data.to_ullong + second._data.to_ullong) % (1ull << 32) };
	}

	friend inline std::ostream& operator << (std::ostream & os, BitVector const & bv) {
		if (os.flags() & os.hex) {
			os << bv.to_hex();
		} else {
			os << bv._data;
		}
		return os;
	}

	std::string to_hex() const {
		auto str_len = 2 * (length / 8 + (length % 8 ? 8 : 0));
		char const hex_chars[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
		std::string ret(str_len, '\0');
		
		size_t cursor = 0;
		for (size_t i = str_len; i > 0; i-=2) {
			char buff = 0;
			for (int i = 0; i < 8 && (cursor + i < length); ++i) {
				buff |= (1ull << i) * _data[cursor + i];
			}
			cursor += 8;
			ret[i - 1] = hex_chars[buff & 0x0F];
			ret[i - 2] = hex_chars[(buff & 0xF0) >> 4];
		}
		ret[0] = ret[0]? ret[0] : '0';
		return ret;
	}

	template<size_t length, size_t out_length>
	friend class Sbox;

};

#endif /* BITVECTOR_H */
