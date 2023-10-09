#include "main.h"

void check(){
	if(uiState.recived){
		for(uint16_t a=0; a<ALL_DATA; a++){
			if(reg.read(a)!=uiState.IN_VAL[a]){
				reg.write(a, uiState.IN_VAL[a]);
				Serial.println("check ok");
				Serial.println(reg.read(a));
				uiState.send=true;
				}
			}
		uiState.recived=false;
		}
	}