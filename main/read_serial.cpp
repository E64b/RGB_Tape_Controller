#include "main.h"

void read_serial(){
  uint8_t IN_VAL[ALL_DATA]{};
	uint16_t i=0;
	while(Serial.available()>0){
		uint8_t VAL=(uint8_t)Serial.read();
		if(VAL==1 or VAL==0){
			IN_VAL[i]=VAL;
			}
		if(VAL=='!'){
			uiState.recived=true;
			break;
			}
		i++;
		}
	}