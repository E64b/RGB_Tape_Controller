#pragma once

#include "GyverHC595.h"

#define STCP 10 //pinCS 12
#define DS 11 //pinDT 14
#define SHCP 13 //pinCLK 11

#define SHIFTS 3 //Number of chips
#define HC595_DELAY 0
#define ONE_SHIFT_DATA 8
#define ALL_DATA (SHIFTS * ONE_SHIFT_DATA)

typedef struct{
	bool IN_VAL[ALL_DATA]{};
	bool CURRENT_VAL[ALL_DATA]{};
	bool send=false;
	bool recived=false;
	uint16_t i=0;
	} UIState;

extern GyverHC595<SHIFTS, HC_PINS> reg;
extern UIState uiState;

void check();
void read_serial();
void send_val();