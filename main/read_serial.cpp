#include "main.h"

void read_serial() {
  while (Serial.available() > 0) {
    char VAL = (char)Serial.read();
    if (uiState.i == ALL_DATA) {
      uiState.recived = true;
      uiState.i = 0;
      break;
    } else if (VAL == '1') {
      uiState.IN_VAL[uiState.i] = true;
      uiState.i++;
    } else if (VAL == '0') {
      uiState.IN_VAL[uiState.i] = false;
      uiState.i++;
    }
  }
}
