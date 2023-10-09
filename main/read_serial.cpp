#include "main.h"

void read_serial(){
	uint16_t i=0;
	while(Serial.available()>0){
		char VAL=(char)Serial.read();
    uiState.IN_VAL[i]=VAL;
		Serial.println(VAL);
		if(VAL=='!'){
			Serial.println("rec");
			uiState.recived=true;
			break;
			}
		i++;
		}
	}