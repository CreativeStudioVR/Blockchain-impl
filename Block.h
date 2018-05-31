#pragma once

#include <Common.h>

struct BlockHeader {
	Hash prev_hash;  // hash of prev block header
	Hash data_hash;  // hash of this block data
	uint32_t timestamp;  // seconds since 1970/01/01 00:00 UTC
	uint32_t nonce;
};

struct Data {
	Address address;  // address of data uploader
};

struct Block {
	BlockHeader block_header;
	Data data;
};
