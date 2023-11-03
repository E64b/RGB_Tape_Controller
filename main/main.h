#pragma once

#include "GyverHC595.h"
#include <Arduino.h>
#include <SPI.h>

#define STCP 10 // pinCS 12
#define DS 11   // pinDT 14
#define SHCP 13 // pinCLK 11
#define DEBUG 1 // debug mode, 1 or 0

#define SHIFTS 1 // Number of chips
#define HC595_DELAY 0
#define ONE_SHIFT_DATA 8
#define ALL_DATA (SHIFTS * ONE_SHIFT_DATA)

typedef struct {
  bool IN_VAL[ALL_DATA]{};
  bool CURRENT_VAL[ALL_DATA]{};
  bool send = false;
  bool recived = false;
  bool wait = true;
  uint16_t i = 0;
} UIState;

extern GyverHC595<SHIFTS, HC_PINS> reg;
extern UIState uiState;

void read_serial();
void check();
void send_val();