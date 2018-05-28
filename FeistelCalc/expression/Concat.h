#pragma once
#ifndef CONCAT_H
#define CONCAT_H

namespace {
	template <typename T>
	constexpr auto _sum(T head) {
		return head;
	}


	template <typename T, typename ...Args>
	constexpr auto _sum(T head, Args&&... tail) {
		return head + _sum(tail...);
	}


	template <template<size_t> class T, size_t src_len, size_t trg_len>
	void copyBitset(T<src_len> const & source, size_t src_start, T<trg_len>& target, size_t trg_start) {
		for (size_t i = src_start; i < src_len; ++i) {
			target[trg_start + i] = source[i];
		}
	}

	template <template<size_t> class T, size_t len>
	constexpr auto getSize(T<len> const &) {
		return len;
	}
}

template <template<size_t> class T, size_t...lengths>
auto Concat(T<lengths>... bitsets) {
	T<_sum(lengths...)> res{0};
	size_t trg_counter = getSize(res);
	int dummy[sizeof...(lengths)] = { (copyBitset(bitsets, 0, res, trg_counter -= getSize(bitsets)), 0)... };
	return res;
}

#endif /* CONCAT_H */
