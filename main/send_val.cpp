#include "GyverCore_uart.h"
#include "main.h"
#include <stdint.h>

void send_val() {
  if (uiState.send) {
    reg.update();
    uiState.i = 0;
    uiState.send = false;
    Serial.println("Send");
  }
}
