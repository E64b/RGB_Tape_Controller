#include "main.h"

void read_serial(){
	while(Serial.available()>0){
		char VAL=(char)Serial.read();
		if(VAL=='1'){
			uiState.IN_VAL[uiState.i]=true;
			uiState.i++;
			}
		if(VAL=='0'){
			uiState.IN_VAL[uiState.i]=false;
			uiState.i++;
			}
		if(uiState.i==ALL_DATA-1){
			uiState.i=0;
			uiState.recived=true;
			break;
			}

		}
	}
