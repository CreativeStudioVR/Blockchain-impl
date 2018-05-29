#include <Block.h>
#include <common.h>

#include <openssl/sha.h>

class BlockHeader {
public:


private:
	Hash prev_hash;  // hash of prev block header
	Hash data_hash;  // hash of this block data
	uint32_t height;  // height of block; 0 for genesis block
	uint32_t timestamp;  // seconds since 1970/01/01 00:00 UTC
	uint32_t nonce;
};

class Data {
public:


private:
	Address address;  // address of data uploader
	
};

class Block {
public:
	bool IsValid () {

	}

private:
	BlockHeader block_header;
	Data data;
};