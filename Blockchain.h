#pragma once

#include <Block.h>
#include <Common.h>

#include <map>

struct Blockchain {
	static std::map<Hash, Block> blocks;  // mapping from block header hash to block
	static std::map<Hash, uint32_t> heights;  // mapping from block header hash to height; 0 for genesis block
	static std::map<Address, uint32_t> balance;  // balance of each address
	static Hash tail_block_hash;  // hash of block with largest height
};
