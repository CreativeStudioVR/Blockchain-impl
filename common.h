#include <bitset>
#include <openssl/sha.h>

typedef byte unsigned char;

const uint32_t ADDR_LEN = 0;  // length of address in bytes
typedef Address std::bitset<8 * ADDR_LEN>;

const uint32_t target = 0;  // number of zeros needed in the prefix of hash
typedef Hash std::bitset<8 * SHA256_DIGEST_LENGTH>;
