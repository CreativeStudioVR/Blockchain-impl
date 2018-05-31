#include <Block.h>
#include <Blockchain.h>
#include <Common.h>

#include <openssl/sha.h>

std::array<byte, 2 * SHA256_DIGEST_LENGTH + 2 * 4> BlockHeader::Serialize () {
	std::array<byte, 2 * SHA256_DIGEST_LENGTH + 2 * 4> ret;
	// TODO: implement this! 
	return ret;
}

std::array<byte, 8> Data::Serialize () {
	return address;
}

bool Block::IsValid () {
	// validate prev_hash and timestamp ordering
	if (Blockchain::blocks.find(prev_hash) == Blockchain::blocks.end()) {
		return false;
	}
	Block prev_block = Blockchain::blocks[prev_hash];
	if (prev_block.block_header.timestamp >= timestamp) {
		return false;
	}

	// validate data_hash
	auto data_s = data.Serialize();
	Hash data_h = ComputeHash(data_s);
	if (data_h != block_header.data_hash) {
		return false;
	}

	// validate nonce
	auto block_header_s = block_header.Serialize();
	if (ComputeLeadingZeros(block_header_s) < target) {
		return false;
	}

	return true;
}
