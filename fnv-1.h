#pragma once
#include <stdint.h>

uint32_t fnv_1_hash_32(uint8_t *bytes, size_t length)
{
	const uint32_t FNV_OFFSET_BASIS_32 = 0x811c9dc5U;
	const uint32_t FNV_PRIME_32 = 0x01000193U;

    uint32_t hash = FNV_OFFSET_BASIS_32;
    for(size_t i = 0 ; i < length ; i++) {
        hash = (FNV_PRIME_32 * hash) ^ (bytes[i]);
    }

    return hash;
}
uint64_t fnv_1_hash_64(uint8_t *bytes, size_t length)
{
	const uint64_t FNV_OFFSET_BASIS_64 = 0xcbf29ce484222325LLU;
	const uint64_t FNV_PRIME_64 = 0x00000100000001B3LLU;

    uint64_t hash = FNV_OFFSET_BASIS_64;
    for(size_t i = 0 ; i < length ; i++) {
        hash = (FNV_PRIME_64 * hash) ^ (bytes[i]);
    }

    return hash;
}
