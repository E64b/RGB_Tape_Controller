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
	reg.update ();
	reg.setAll ();
	reg.update ();
	delay (1000);
	reg.clearAll ();
	reg.update ();
	}

void loop (){
	/*Turn on all the red */
	CURRENT_PIN = 0;
	for (R; R <= ALL_DATA; R + 3){
		reg.set (R);
		reg.update ();
		delay (500);
		}
	reg.clearAll ();
	reg.update ();

	/*Turn on all the green */
	CURRENT_PIN = 0;
	for (G; G <= ALL_DATA; G + 3){
		reg.set (G);
		reg.update ();
		delay (500);
		}
	reg.clearAll ();
	reg.update ();

	/*Turn on all the blue */
	CURRENT_PIN = 0;
	for (B; B <= ALL_DATA; B + 3){
		reg.set (B);
		reg.update ();
		delay (500);
		}
	reg.clearAll ();
	reg.update ();

	/*Turn on all the white */
	for (CURRENT_PIN = 0; CURRENT_PIN <= ALL_DATA; CURRENT_PIN + 3){
		reg.set (R);
		reg.set (G);
		reg.set (B);
		reg.update ();
		delay (500);
		}
	reg.clearAll ();
	reg.update ();
	}