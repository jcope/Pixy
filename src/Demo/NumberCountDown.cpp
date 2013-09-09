/*****************************************
 EMMA TECHNOLOGIES, L.L.C.
 Copyright (c) 2013.
 All Rights Reserved.
 *****************************************/
#include "NumberCountDown.h"
#include <main.h> //So we can flush the displayManager to the actual display


//For now

//ONE [1]
uint8_t one[64] = {
0,0,0,48,0,0,0,0,\
0,0,48,48,0,0,0,0,\
0,48,0,48,0,0,0,0,\
0,0,0,48,0,0,0,0,\
0,0,0,48,0,0,0,0,\
0,0,0,48,0,0,0,0,\
0,0,0,48,0,0,0,0,\
0,48,48,48,48,48,0,0};
//TWO [2]
uint8_t two[64] = {
0,0,48,48,48,0,0,0,\
0,48,0,0,0,48,0,0,\
0,0,0,0,0,48,0,0,\
0,0,0,0,0,48,0,0,\
0,0,0,0,48,0,0,0,\
0,0,0,48,0,0,0,0,\
0,0,48,0,0,0,0,0,\
0,48,48,48,48,48,0,0};
//THREE [3]
uint8_t three[64] = {
0,0,12,12,12,0,0,0,\
0,12,0,0,0,12,0,0,\
0,0,0,0,0,12,0,0,\
0,0,0,12,12,0,0,0,\
0,0,0,12,12,0,0,0,\
0,0,0,0,0,12,0,0,\
0,12,0,0,0,12,0,0,\
0,0,12,12,12,0,0,0};
//Four [4]
uint8_t four[64] = {
0,0,0,3,3,3,0,0,\
0,0,3,3,3,3,0,0,\
0,3,3,0,3,3,0,0,\
3,3,0,0,3,3,0,0,\
3,3,3,3,3,3,3,3,\
0,0,0,0,3,3,0,0,\
0,0,0,0,3,3,0,0,\
0,0,0,0,3,3,0,0};
//Five [5]
uint8_t five[64] = {
0,3,3,3,3,3,3,0,\
0,3,0,0,0,0,0,0,\
0,3,0,0,0,0,0,0,\
0,3,0,0,0,0,0,0,\
0,3,3,3,3,3,0,0,\
0,0,0,0,0,0,3,0,\
0,3,0,0,0,0,3,0,\
0,0,3,3,3,3,0,0};

NumberCountDown::NumberCountDown(DisplayManager* globalDisplayManager){
	g_displayManager = globalDisplayManager;
}

NumberCountDown::~NumberCountDown(){
	
}

void NumberCountDown::initDemo(){
	uint8_t* display[] = {five,four,three,two,one};
	g_displayManager->populateDisplayBuffer(display,5,RIGHT_BUFFER); //11 is number of characters in display
}

#define MAX_BRIGHTNESS 255
void NumberCountDown::runDemoLoop(){
	//Display the current number
	flushDisplayMatrix(2,30);
	
	//Fade out the number
	uint8_t fadeSteps=10;
	uint8_t fadePerStep=MAX_BRIGHTNESS/fadeSteps;
	uint8_t fadeValue=MAX_BRIGHTNESS;
	
	for(uint8_t step=0; step<fadeSteps; step++){
		fadeValue = fadeValue - fadePerStep;		
		flushDisplayMatrixRGB(2,8,fadeValue,fadeValue,fadeValue);
	}
	
	//Delay before going to next number
	//delay(100);
	
	//Display next number
	g_displayManager->nextDisplayBuffer();
}