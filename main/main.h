#include "GyverHC595.h"
#include <Arduino.h>
#include <SPI.h>

#define STCP 10 //pinCS 12
#define DS 11 //pinDT 14
#define SHCP 13 //pinCLK 11

#define SHIFTS 1
#define HC595_DELAY 0
#define ONE_SHIFT_DATA 8
#define ALL_DATA (SHIFTS * ONE_SHIFT_DATA)

#define R CURRENT_PIN
#define G (CURRENT_PIN + 1)
#define B (CURRENT_PIN + 2)

GyverHC595<SHIFTS, HC_PINS> reg(STCP, DS, SHCP);
bool IN_VAL[ALL_DATA] {};
bool OLD_VAL[ALL_DATA]{};
uint16_t CURRENT_PIN=0;

extern CURRENT_PIN;