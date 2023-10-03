#include "GyverHC595.h"
#include <Arduino.h>
#include <SPI.h>

/*
#define REG
#define VAL
#define R
#define G
#define B
*/
#define STCP 10 //pinCS 12
#define DS 11 //pinDT 14
#define SHCP 13 //pinCLK 11
#define SHIFTS 6
#define HC595_DELAY 0

GyverHC595<SHIFTS, HC_PINS> reg(STCP, DS, SHCP);

void read_seral();
void send_val();