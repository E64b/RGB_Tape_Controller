#include "main.h"

void read_serial(){
 	uint16_t i=0;
	while(Serial.available()>0){
		bool VAL=(bool)Serial.read();
		if(VAL==1 or VAL==0){
			uiState.IN_VAL[i]=VAL;
			}
		if(VAL=='!'){
			uiState.recived=true;
			break;
			}
		i++;
		}
	}