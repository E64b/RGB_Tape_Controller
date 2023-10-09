#include "main.h"

void send_val(){
	if(uiState.send){
		reg.update();
		uiState.send=false;
		Serial.println("send");
		}
	}
