#include "main.h"

void check(){
  	if(uiState.recived){
		for(uint16_t a = 0; a<ALL_DATA; a++){
      bool var = uiState.IN_VAL[a]; 
      Serial.println(var);
			if(reg.buffer[a]!=var){
				reg.write(a, var);
				uiState.send=true;
				}
			}
		uiState.recived=false;
		}
	}