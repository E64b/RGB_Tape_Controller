#include "main.h"

GyverHC595<SHIFTS, HC_PINS> reg(STCP, DS, SHCP);
UIState uiState;

void setup(){
	Serial.begin(9600);
	while(!Serial);
	Serial.print("Serial OK");

	reg.setAll();
	reg.update();
	delay(5000);
	reg.clearAll();
	reg.update();
	}

void loop(){	
	read_serial();
	check();
	send_val();
}