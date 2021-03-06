#include "FeistelCalc.h"

// Так делать нельзя, по хорошему надо в h-файле переменные подтянуть через extern.
// Но мне лень этим заниматься, в данном случае и так сойдёт
#include "configs/DES.h"

namespace Feistel {
	//using namespace DES;

	auto Encrypt(BitVector<64> const & PT, BitVector<64> const & key) {
		auto tmp = PT; // IP(PT) 
		auto L = Rotate<0, n / 2 - 1>(tmp, 0);
		auto R = Rotate<n / 2, n - 1>(tmp, 0);

		for (size_t i = 0; i < r; ++i) {
			auto sk = K(key, i);
			auto gamma = F(R, sk);
			auto L_new = R;
			auto R_new = L + gamma;
			L = L_new;
			R = R_new;
		}
		auto CT = Concat(L, R); // IP_inv(Concat(L, R))
		return CT;
	}

	auto Decrypt(BitVector<64> const & CT, BitVector<64> const & key) {
		auto tmp = CT; // IP(CT)
		auto L = Rotate<0, n / 2 - 1>(tmp, 0);
		auto R = Rotate<n / 2, n - 1>(tmp, 0);

		for (size_t i = 0; i < r; ++i) {
			auto sk = K(key, r - i - 1);
			auto gamma = F(L, sk);
			auto R_new = L;
			auto L_new = R + gamma;
			L = L_new;
			R = R_new;
		}
		auto PT = Concat(L, R); // IP_inv(Concat(L, R))
		return PT;
	}
}

int main(int argc, const char * argv[]) {
	BitVector<64> PT({ 0x000000000000001ull });
	BitVector<64> key({ 0x000000000000000ull });

	auto CT = Feistel::Encrypt(PT, key);
	auto PT_ = Feistel::Decrypt(CT, key);
	
	std::cout << "Plaintext:\t" << std::hex << PT << std::endl;
	std::cout << "Ciphertext:\t" << std::hex << CT << std::endl;
	std::cout << "Decrypted:\t" << std::hex << PT_ << std::endl;

	//BitVector<6> bv(std::bitset<6>("100000"));
	//auto P = Substitution<6>({ 1, 1, 3, 4, 5, 6 });
	//std::cout << P(bv) << std::endl;
	
	// getchar();
	return 0;
}
