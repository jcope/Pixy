/*****************************************
 EMMA TECHNOLOGIES, L.L.C.
 Copyright (c) 2013.
 All Rights Reserved.
 *****************************************/
#include "FallingMatrix.h"
#include <Utilities/Utilities.h>
#include <include/colors.h>
#include <main.h> //So we can flush the displayManager to the actual display

uint8_t columnSpeed[8] = {3,5,8,4,5,3,2,6};

FallingMatrix::FallingMatrix(DisplayManager* globalDisplayManager){
	g_displayManager = globalDisplayManager;
	loopCnt=0;
}

FallingMatrix::~FallingMatrix(){}

void FallingMatrix::initDemo(){}

void FallingMatrix::runDemoLoop(){
	//Create random row of green
	uint8_t randomRow[8];
	DisplayMatrix::randomFillRow(randomRow, sizeof(randomRow), GREEN);
	
	//Capture the current display
	display.setCurrentMatrix(g_displayManager->getCurrentDisplayMatrix()->getCurrentMatrix(),64);
	
	//Place in top buffer
	display.setTopBuffer(randomRow,sizeof(randomRow));
	
	//Apply transform down, different speeds
	for(uint8_t columnIndex=0;columnIndex<8;columnIndex++){
		if(loopCnt % columnSpeed[columnIndex] == 0){
			display.transformColumnDown(columnIndex);
		}
	}
	//display.transformMatrix(DOWN);
	
	//Set back to the display
	g_displayManager->setDisplayMatrix(display.getCurrentMatrix(),64);
	
	//Present display
	flushDisplayMatrix(2,5);
	
	//Count the loops, for column speed control
	loopCnt++;
}