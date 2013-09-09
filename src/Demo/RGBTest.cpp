/*****************************************
 EMMA TECHNOLOGIES, L.L.C.
 Copyright (c) 2013.
 All Rights Reserved.
 *****************************************/
#include "RGBTest.h"
#include <main.h> //So we can flush the displayManager to the actual display


//For now
uint8_t red[64] = {
3,3,3,3,3,3,3,3,\
3,3,3,3,3,3,3,3,\
3,3,3,3,3,3,3,3,\
3,3,3,3,3,3,3,3,\
3,3,3,3,3,3,3,3,\
3,3,3,3,3,3,3,3,\
3,3,3,3,3,3,3,3,\
3,3,3,3,3,3,3,3};

uint8_t blue[64] = {
12,12,12,12,12,12,12,12,\
12,12,12,12,12,12,12,12,\
12,12,12,12,12,12,12,12,\
12,12,12,12,12,12,12,12,\
12,12,12,12,12,12,12,12,\
12,12,12,12,12,12,12,12,\
12,12,12,12,12,12,12,12,\
12,12,12,12,12,12,12,12};

uint8_t green[64] = {
48,48,48,48,48,48,48,48,\
48,48,48,48,48,48,48,48,\
48,48,48,48,48,48,48,48,\
48,48,48,48,48,48,48,48,\
48,48,48,48,48,48,48,48,\
48,48,48,48,48,48,48,48,\
48,48,48,48,48,48,48,48,\
48,48,48,48,48,48,48,48};


RGBTest::RGBTest(DisplayManager* globalDisplayManager){
	g_displayManager = globalDisplayManager;
}

RGBTest::~RGBTest(){
	
}

void RGBTest::initDemo(){
		
	uint8_t* display[] = {red,blue,green};
	
	g_displayManager->populateDisplayBuffer(display,3,RIGHT_BUFFER); //3 is number of characters in display
}

void RGBTest::runDemoLoop(){
	flushDisplayMatrix(2,30);
	g_displayManager->transformDisplay(LEFT);
}