#include "GyverHC595.h"
#include <Arduino.h>
#include <SPI.h>

#define STCP 10 //pinCS 12
#define DS 11 //pinDT 14
#define SHCP 13 //pinCLK 11

#define SHIFTS 6
#define HC595_DELAY 0
#define ONE_SHIFT_DATA 8
#define ALL_DATA (SHIFTS * ONE_SHIFT_DATA)

#define R CURRENT_PIN
#define G (CURRENT_PIN + 1)
#define B (CURRENT_PIN + 2)

GyverHC595<SHIFTS, HC_PINS> reg (STCP, DS, SHCP);

uint16_t CURRENT_PIN = 0;

void setup (){
	Serial.begin (9600);
	while (!Serial);
	Serial.print ("Serial OK");

	reg.clearAll ();
	reg.setAll ();
	delay (1000);
	reg.clearAll ();
	}

void loop (){
	CURRENT_PIN = 0;

	/*Turn on all the red */
	for (R; R <= ALL_DATA; R + 3){
		reg.set (R);
		delay (500);
		}
	reg.clearAll ();

	/*Turn on all the green */
	for (G; G <= ALL_DATA; G + 3){
		reg.set (G);
		delay (500);
		}
	reg.clearAll ();

	/*Turn on all the blue */
	for (B; B <= ALL_DATA; B + 3){
		reg.set (B);
		delay (500);
		}
	reg.clearAll ();

	/*Turn on all the white */
	for (CURRENT_PIN; CURRENT_PIN <= ALL_DATA; CURRENT_PIN + 3){
		reg.set (R);
		reg.set (G);
		reg.set (B);
		delay (500);
		}
	reg.clearAll ();

	}