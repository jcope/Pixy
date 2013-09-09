/*****************************************
 EMMA TECHNOLOGIES, L.L.C.
 Copyright (c) 2013.
 All Rights Reserved.
 *****************************************/
#include "RandomRGB.h"
#include <Utilities/Utilities.h>
#include <main.h> //So we can flush the displayManager to the actual display

RandomRGB::RandomRGB(DisplayManager* globalDisplayManager){
	g_displayManager = globalDisplayManager;
}

RandomRGB::~RandomRGB(){
	
}

void RandomRGB::initDemo(){
	uint8_t randomRow[8];
	//Create 8 random rows and populate the initial display
	for(uint8_t rowIndex=0; rowIndex<8; rowIndex++){
		DisplayMatrix::randomFillRowRGB(randomRow, sizeof(randomRow));
		display.setTopBuffer(randomRow,sizeof(randomRow));
		display.transformMatrix(DOWN);
	}
	g_displayManager->setDisplayMatrix(display.getCurrentMatrix(),64);
	//ShiftPWM.populateDisplayData();
}

void RandomRGB::runDemoLoop(){
	//Create random row of rgb
	uint8_t randomRow[8];
	DisplayMatrix::randomFillRowRGB(randomRow, sizeof(randomRow));
	
	//Capture the current display
	display.setCurrentMatrix(g_displayManager->getCurrentDisplayMatrix()->getCurrentMatrix(),64);
	
	//Calculate a random direction
	uint8_t direction = Utilities::randomNumber(3);
	direction++; //1-4
	//Populate the correct buffer
	switch (direction){
		case UP:
			display.setBottomBuffer(randomRow,sizeof(randomRow));
			break;
		case RIGHT:
			display.setLeftBuffer(randomRow,sizeof(randomRow));
			break;
		case DOWN:
			display.setTopBuffer(randomRow,sizeof(randomRow));
			break;
		case LEFT:
			display.setRightBuffer(randomRow,sizeof(randomRow));
			break;
		default:
			//Error, Invalid Transform Direction
		break;
	}
	
	//Now transform in the random direction
	display.transformMatrix(e_direction(direction));
	
	//Set back to the display
	g_displayManager->setDisplayMatrix(display.getCurrentMatrix(),64);
	
	//Present display
	flushDisplayMatrix(2,15);
}