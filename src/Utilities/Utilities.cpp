/*****************************************
 EMMA TECHNOLOGIES, L.L.C.
 Copyright (c) 2013.
 All Rights Reserved.
 ****************************************/
#include "Utilities.h"

#if TARGET == OSX
//OSX
#include <stdlib.h> //rand
#include <ctime> //time
#include <sys/time.h> //ms time

#elif TARGET == ARDUINO
//Arduino
#include <Arduino.h>
#endif

//Dual
#include <stdint.h> //uint8_t

bool Utilities::init = false;

Utilities::Utilities(){
	initClass();
}

Utilities::~Utilities(){
	
}
void Utilities::initClass(){
	//Seed the random num generator
	#if TARGET == OSX
		//OSX
		srand(time(0));
	#elif TARGET == ARDUINO
		//Arduino
		randomSeed(analogRead(0));
	#endif
	
	init = true;
}

int Utilities::randomNumber(int max){
	
	return randomNumber(0,max);
}

//TODO: Verify the minimum
int Utilities::randomNumber(int min, int max){
	if(!init) initClass();

	uint8_t randomValue;
	
	//How we get a random number depends on the target
	#if TARGET == OSX
		//OSX
		randomValue = rand() % max;
	#elif TARGET == ARDUINO
		//Arduino
		randomValue = random(max);
	#endif
	
	return randomValue;
}

void Utilities::extractRGBvalues(uint8_t baseValue, uint8_t& r, uint8_t& g, uint8_t& b){
	if(!init) initClass();
	
	//Parse the baseValue to determine the rgb values, see notebook for logic
	
	//Ex.
	if(baseValue == 214){
		r = 191;
		g = 223;
		b = 0;
	}
}