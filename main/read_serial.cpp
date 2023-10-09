#include "main.h"

void read_serial(){
	uint16_t i=0;
	while(Serial.available()>0){
		bool VAL=(bool)Serial.read();
		uiState.IN_VAL[i]=VAL;
		Serial.println(VAL);
		if(i==ALL_DATA){
			Serial.println("rec");
			uiState.recived=true;
			break;
			}
		i++;
		}
	}