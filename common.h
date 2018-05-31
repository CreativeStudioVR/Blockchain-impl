#pragma once

#include <array>
#include <openssl/sha.h>

typedef byte unsigned char;

const uint32_t ADDR_LEN = 8;  // length of address in bytes
typedef Address std::array<byte, ADDR_LEN>;

const uint32_t target = 4;  // number of zeros needed in the prefix of hash
typedef Hash std::array<byte, SHA256_DIGEST_LENGTH>;

template <uint32_t size>
uint32_t ComputeLeadingZeros (std::array<byte, size> &data) {
	uint32_t ret = 0;
	for (byte b : data) {
		for (int i = sizeof(byte)-1; i >= 0; i--) {
			if (b & (1 << i) == 0) ret++;
		}
		if (b) break;
	}
	return ret;
}

template <uint32_t size>
Hash ComputeHash (std::array<byte, size> &data) {
	byte *raw_data = new byte[size];
	std::copy(data.begin(), data.end(), std::begin(raw_data));

	byte raw_hash[SHA256_DIGEST_LENGTH];
	SHA256_CTX sha256;
	SHA256_Init(&sha256);
	SHA256_Update(&sha256, raw_data, size);
	SHA256_Final(raw_hash, &sha256);

	Hash hash;
	std::copy(std::begin(raw_hash), std::end(raw_hash), hash.begin());

	return hash;
}
