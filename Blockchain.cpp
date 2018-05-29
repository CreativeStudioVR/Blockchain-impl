#include <Blockchain.h>
#include <Block.h>
#include <common.h>

#include <map>
#include <openssl/sha.h>

class Blockchain {
public:
	Blockchain () {
		// create genesis block
	}

private:
	std::map<Hash, Block> blocks;  // mapping from block header hash to block
	std::map<Address, uint32_t> balance;  // balance of each address
	Hash tail_block;  // hash of block with largest height
};