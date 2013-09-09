/*****************************************
 EMMA TECHNOLOGIES, L.L.C.
 Copyright (c) 2013.
 All Rights Reserved.
 *****************************************/
#include "ScrollText.h"
#include <main.h> //So we can flush the displayManager to the actual display


//For now
uint8_t pixy[64] = {
0,3,0,48,48,0,3,0,\
0,3,0,48,48,0,3,0,\
0,0,3,0,0,3,0,0,\
0,0,0,3,3,0,0,0,\
0,0,0,3,3,0,0,0,\
0,0,3,3,3,3,0,0,\
0,0,3,0,0,3,0,0,\
0,3,3,0,0,3,3,0};

uint8_t space[64] = {
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0};

//[E]
uint8_t E[64] = {
0,0,3,3,3,3,0,0,\
0,3,0,0,0,0,0,0,\
0,3,0,0,0,0,0,0,\
0,3,0,0,0,0,0,0,\
0,3,3,3,0,0,0,0,\
0,3,0,0,0,0,0,0,\
0,3,0,0,0,0,0,0,\
0,0,3,3,3,3,0,0};

//[m]
uint8_t m[64] = {
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,3,3,3,0,3,3,0,\
0,3,0,0,3,0,0,3,\
0,3,0,0,3,0,0,3,\
0,3,0,0,3,0,0,3,\
0,3,0,0,3,0,0,3};

//[a]
uint8_t a[64] = {
0,0,0,3,3,0,0,0,\
0,0,3,0,0,3,0,0,\
0,0,3,0,0,0,3,0,\
0,0,0,0,0,0,3,0,\
0,0,0,3,3,3,3,0,\
0,0,3,0,0,0,3,0,\
0,3,0,0,0,3,3,0,\
0,3,3,3,3,0,3,0};

ScrollText::ScrollText(DisplayManager* globalDisplayManager){
	g_displayManager = globalDisplayManager;
}

ScrollText::~ScrollText(){
	
}

void ScrollText::initDemo(){
		
	uint8_t* display1[] = {pixy,space,E,m,m,a,space};
	//uint8_t* display2[] = {space,T,e,c,h};
	
	g_displayManager->populateDisplayBuffer(display1,7,RIGHT_BUFFER); //11 is number of characters in display
}

void ScrollText::runDemoLoop(){
	flushDisplayMatrix(2,30);
	g_displayManager->transformDisplay(LEFT);
}