#include "main.h"

void check() {
  if (uiState.recived) {
    for (uint16_t i = 0; i < ALL_DATA; i++) {
      if (uiState.CURRENT_VAL[i] != uiState.IN_VAL[i]) {
        uiState.CURRENT_VAL[i] = uiState.IN_VAL[i];
        reg.write(i, uiState.CURRENT_VAL[i]);
        uiState.send = true;
      }
    }
    uiState.recived = false;
    if (DEBUG == true) {
      for (uint16_t i = 0; i < ALL_DATA; i++) {
        Serial.print(uiState.CURRENT_VAL[i]);
      }
      Serial.println();
    }
    while (Serial.available()) {
      Serial.read();
      delay(5);
    }
    for (uint16_t i = 0; i < ALL_DATA; i++) {
      uiState.IN_VAL[i] = false;
    }
  }
}