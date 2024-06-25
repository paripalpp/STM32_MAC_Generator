#pragma once
#include <main.h>
#include "fnv-1.h"
void mac_gen(uint8_t* mac){
	uint8_t uid[12];
	uint32_t _uid;
	_uid = HAL_GetUIDw0();
	memcpy(uid, &_uid, 4);
	_uid = HAL_GetUIDw1();
	memcpy(uid + 4, &_uid, 4);
	_uid = HAL_GetUIDw2();
	memcpy(uid + 8, &_uid, 4);
	uint32_t hashed_uid = fnv_1_hash_32(uid, 12);

	mac[0] = 0x02;
	mac[1] = 0x01;
	mac[2] = 0x00;
	memcpy(mac + 3, &hashed_uid, 3);
}
