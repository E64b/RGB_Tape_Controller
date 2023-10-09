#include "main.h"

void send_val(){
	if(uiState.send){
		reg.update();
		uiState.i=0;
		uiState.send=false;
		Serial.println("Send");
		}
	}
