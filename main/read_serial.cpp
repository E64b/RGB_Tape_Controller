#include "main.h"

void read_serial(){
  char IN_VAL[ALL_DATA]{};
	uint16_t i=0;
	while(Serial.available()>0){
		char VAL=(char)Serial.read();
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