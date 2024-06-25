# STM32 MAC Address Generator
This library generate mac address from STM32 UUID. using FNV-1 algorithm.

## usage
1. copy ```fnv-1.h``` and ```mac_gen.h``` to ```Project/Src/Inc/```.
2. add bellow 3 lines to ```Project/LWIP/Target/ethernet.c``` : line 211~
``` c
  /* USER CODE BEGIN MACADDRESS */
#include "mac_gen.h"
  mac_gen(MACAddr);
  heth.Init.MACAddr = &MACAddr[0];
  /* USER CODE END MACADDRESS */
```