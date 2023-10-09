#include "main.h"

void check(){
  	if(uiState.recived){
		for(uint16_t a; a<ALL_DATA; a++){
			if(reg.buffer[a]!=uiState.IN_VAL[a]){
				reg.write(a, uiState.IN_VAL[a]);
				uiState.send=true;
				}
			}
		uiState.recived=false;
		}
	}