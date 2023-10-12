#include "main.h"

GyverHC595<SHIFTS, HC_PINS> reg(STCP, DS, SHCP);
UIState uiState;

void setup(){
	Serial.begin(115200);
	while(!Serial);
	reg.setAll();
	reg.update();
	delay(5000);
	reg.clearAll();
	reg.update();

	for(uint16_t i=0; i<ALL_DATA; i++){
		uiState.CURRENT_VAL[i]=false;
		}

	Serial.println("Serial OK");
	}

void loop(){
	read_serial();
	check();
	send_val();
	}
