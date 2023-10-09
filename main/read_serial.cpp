#include "main.h"
void read_seral(){
	int i=0;
	while(Serial.available()>0){
		bool c=(char)Serial.read();
		if(c=='!'){
			sendData=true;
			break;
			}
		arr[i]=c;
		i++;
		}
	}