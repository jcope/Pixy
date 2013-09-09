/*****************************************
 EMMA TECHNOLOGIES, L.L.C.
 Copyright (c) 2013.
 All Rights Reserved.
 ****************************************/
#include "DisplayManager.h"
#include <DisplayMatrix/DisplayMatrix.h>

//OSX
//#include <cstdio> //printf

//ARDUINO
#include <stdio.h> //printf

DisplayManager::DisplayManager(){
	//Represents a '3x3' cross, 5 matrix total
	for(int index=0;index<5;index++){
		m_displayArray[index]=new DisplayMatrix();
	}
	createNewDisplay();
}

DisplayManager::~DisplayManager(){
	for(int index=0;index<5;index++){
		delete m_displayArray[index];
	}
}

void DisplayManager::createNewDisplay(){
	m_rightTrans = 8; //Count down
	m_leftTrans = 8;
	m_topTrans = 8;
	m_bottomTrans = 8;
	m_displayBufferIndex=0;
	m_displayBufferSize=0;
	initDataStructures();
}

//See diagram of display manager buffer and representation
//Manipulate the display Matrix 
DisplayMatrix* DisplayManager::getCurrentDisplayMatrix(){
	return m_displayArray[CENTER_DISPLAY];
}

void DisplayManager::combineDisplayMatrix(uint8_t* addMatrix, size_t matrixSize){
	m_displayArray[CENTER_DISPLAY]->combineMatrix(addMatrix,matrixSize);	
}

void DisplayManager::setDisplayMatrix(uint8_t* newMatrix, size_t matrixSize){
	m_displayArray[CENTER_DISPLAY]->setCurrentMatrix(newMatrix,matrixSize);
}

//This will set the current display to the next character in the diplay buffer
void DisplayManager::nextDisplayBuffer(){
	//TODO: transCounters
	//Check if we need to reset to begining
	if(++m_displayBufferIndex >= m_displayBufferSize){
		//Circle buffer around
		m_displayBufferIndex=0;
	}
		
	//Populate display buffer with new character
	m_displayArray[CENTER_DISPLAY]->setCurrentMatrix(m_displayBuffer[m_displayBufferIndex],64);
}

bool DisplayManager::transformDisplay(e_direction dir){
	bool retVal = false; //If the transform was valid
	switch(dir){
		case UP:
			retVal = transformUp();
		break;
		case RIGHT:
			retVal = transformRight();
		break;
		case DOWN:
			retVal = transformDown();
		break;
		case LEFT:
			retVal = transformLeft();
		break;
		default:
			//Error, Invalid Transform Direction
		break;
	}
	return retVal;
}

//For Debugging..
#define SPACER "                "
void DisplayManager::toString(){
	//Print out the top buffer first, row by row
	uint8_t printBuffer[8];
	uint8_t matrixRow;
	
	//Top row buffer
	for(matrixRow=0;matrixRow<8;matrixRow++){
		//Print out the spacer
		printf(SPACER);
		m_displayArray[TOP_BUFFER]->getCurrentMatrixRow(matrixRow,printBuffer);
		//Print out the actual data from the buffer
		for(int index=0;index<8;index++){
			printf("%d ",printBuffer[index]);
		}
		//Newline
		printf("\n");	
	}
	//Left,center,right
	for(matrixRow=0;matrixRow<8;matrixRow++){
		m_displayArray[TOP_BUFFER]->getCurrentMatrixRow(matrixRow,printBuffer);
		//Print out the actual data from the buffer
		for(int index=0;index<8;index++){
			printf("%d ",printBuffer[index]);
		}
		m_displayArray[CENTER_DISPLAY]->getCurrentMatrixRow(matrixRow,printBuffer);
		//Print out the actual data from the buffer
		for(int index=0;index<8;index++){
			printf("%d ",printBuffer[index]);
		}
		m_displayArray[RIGHT_BUFFER]->getCurrentMatrixRow(matrixRow,printBuffer);
		//Print out the actual data from the buffer
		for(int index=0;index<8;index++){
			printf("%d ",printBuffer[index]);
		}
		//Newline
		printf("\n");	
	}
	//Top row buffer
	for(matrixRow=0;matrixRow<8;matrixRow++){
		//Print out the spacer
		printf(SPACER);
		m_displayArray[BOTTOM_BUFFER]->getCurrentMatrixRow(matrixRow,printBuffer);
		//Print out the actual data from the buffer
		for(int index=0;index<8;index++){
			printf("%d ",printBuffer[index]);
		}
		//Newline
		printf("\n");	
	}
}

void DisplayManager::populateDisplayBuffer(uint8_t* newBuffer[], size_t numOfCharacters, e_buffer bufferFillDir){
	for(uint8_t charIndex=0; charIndex<numOfCharacters; charIndex++){
		m_displayBuffer[charIndex]=newBuffer[charIndex];
	}
	m_displayBufferIndex=0;
	m_displayBufferSize=numOfCharacters;
	m_rightTrans = 8; //Count down
	m_leftTrans = 8;
	m_topTrans = 8;
	m_bottomTrans = 8;
	
	//The param will determine which display buffer to place the initial characters
	m_displayArray[bufferFillDir]->setCurrentMatrix(m_displayBuffer[m_displayBufferIndex],64);
}

/******PRIVATE*******/
void DisplayManager::initDataStructures(){
	//Hardcoded 5 displayMatrix in the array, reference diagram
	for(uint8_t index=0;index<5;index++){
		m_displayArray[index]->clearDataStructures();
	}
	memset(m_displayBuffer,0,sizeof(m_displayBuffer));
}

//*We will pull from buffer 2, right*//
bool DisplayManager::transformLeft(){
	
	uint8_t* leftBuffer; //Used to pass info from one transfrom to the next display
		
	//Transform the 'row' first
	m_displayArray[RIGHT_BUFFER]->transformMatrix(LEFT);
	//Then use the left buffer to populate the right buffer in the next display to the left
	leftBuffer = m_displayArray[RIGHT_BUFFER]->getLeftBuffer();
	m_displayArray[CENTER_DISPLAY]->setRightBuffer(leftBuffer, 8);
	
	m_displayArray[CENTER_DISPLAY]->transformMatrix(LEFT);
	//Then use the left buffer to populate the right buffer in the next display to the left
	leftBuffer = m_displayArray[CENTER_DISPLAY]->getLeftBuffer();
	m_displayArray[LEFT_BUFFER]->setRightBuffer(leftBuffer, 8);
	
	//Let the buffer fall off
	m_displayArray[LEFT_BUFFER]->transformMatrix(LEFT);
	
	//Transform the tops
	//TODO: Good enough on the periferal buffers?
	m_displayArray[TOP_BUFFER]->transformMatrix(LEFT);
	m_displayArray[BOTTOM_BUFFER]->transformMatrix(LEFT);
	
	
	
	//Now determine if we have completed the current buffer
	
	//Decrement the total amount of transforms
	m_rightTrans--;
	
	//If we have transformed all the data out of the buffers
	if(m_rightTrans == 0){
		m_rightTrans = 8;
		
		//Increment the character index to the display buffer
		//Check if we need to reset to begining
		if(++m_displayBufferIndex >= m_displayBufferSize){
			//Circle buffer around
			m_displayBufferIndex=0;
		}
		
		//Populate display buffer with new character
		m_displayArray[RIGHT_BUFFER]->setCurrentMatrix(m_displayBuffer[m_displayBufferIndex],64);
	}
	return true;
}

//*We will pull from buffer 0, left*//
bool DisplayManager::transformRight(){
	
	uint8_t* rightBuffer; //Used to pass info from one transfrom to the next display
	
	//Transform the 'row' first
	m_displayArray[LEFT_BUFFER]->transformMatrix(RIGHT);
	//Then use the right buffer to populate the left buffer in the center
	rightBuffer = m_displayArray[LEFT_BUFFER]->getRightBuffer();
	m_displayArray[CENTER_DISPLAY]->setLeftBuffer(rightBuffer, 8);
	
	m_displayArray[CENTER_DISPLAY]->transformMatrix(RIGHT);
	//Then use the right buffer to populate the left buffer in right
	rightBuffer = m_displayArray[CENTER_DISPLAY]->getRightBuffer();
	m_displayArray[RIGHT_BUFFER]->setLeftBuffer(rightBuffer, 8);
	
	//Let the buffer fall off
	m_displayArray[RIGHT_BUFFER]->transformMatrix(RIGHT);
	
	//Transform the tops
	//TODO: Good enough on the periferal buffers?
	m_displayArray[TOP_BUFFER]->transformMatrix(RIGHT);
	m_displayArray[BOTTOM_BUFFER]->transformMatrix(RIGHT);
	
	//Now determine if we have completed the current buffer
	
	//Decrement the total amount of transforms
	m_leftTrans--;
	
	//If we have transformed all the data out of the buffers
	if(m_leftTrans == 0){
		m_leftTrans = 8;
		
		//Increment the character index to the display buffer
		//Check if we need to reset to begining
		if(++m_displayBufferIndex >= m_displayBufferSize){
			//Circle buffer around
			m_displayBufferIndex=0;
		}
		
		//Populate display buffer with new character
		m_displayArray[LEFT_BUFFER]->setCurrentMatrix(m_displayBuffer[m_displayBufferIndex],64);
	}
	return true;
}

//*We will pull from buffer 4, bottom*//
bool DisplayManager::transformUp(){
		
	uint8_t* topBuffer; //Used to pass info from one transfrom to the next display
	
	//Transform the 'column' first
	m_displayArray[BOTTOM_BUFFER]->transformMatrix(UP);
	//Then use the top buffer to populate the bottom buffer in the center
	topBuffer = m_displayArray[BOTTOM_BUFFER]->getTopBuffer();
	m_displayArray[CENTER_DISPLAY]->setBottomBuffer(topBuffer, 8);
	
	m_displayArray[CENTER_DISPLAY]->transformMatrix(UP);
	//Then use the right buffer to populate the left buffer in right
	topBuffer = m_displayArray[CENTER_DISPLAY]->getTopBuffer();
	m_displayArray[TOP_BUFFER]->setBottomBuffer(topBuffer, 8);
	
	//Let the buffer fall off
	m_displayArray[TOP_BUFFER]->transformMatrix(UP);
	
	//Transform the tops
	//TODO: Good enough on the periferal buffers?
	m_displayArray[LEFT_BUFFER]->transformMatrix(UP);
	m_displayArray[RIGHT_BUFFER]->transformMatrix(UP);
	
	//Now determine if we have completed the current buffer
	
	//Decrement the total amount of transforms
	m_bottomTrans--;
	
	//If we have transformed all the data out of the buffers
	if(m_bottomTrans == 0){
		m_bottomTrans = 8;
		
		//Increment the character index to the display buffer
		//Check if we need to reset to begining
		if(++m_displayBufferIndex >= m_displayBufferSize){
			//Circle buffer around
			m_displayBufferIndex=0;
		}
		
		//Populate display buffer with new character
		m_displayArray[BOTTOM_BUFFER]->setCurrentMatrix(m_displayBuffer[m_displayBufferIndex],64);
	}
	return true;
}

//*We will pull from buffer 3, top*//
bool DisplayManager::transformDown(){
	
	uint8_t* bottomBuffer; //Used to pass info from one transfrom to the next display
	
	//Transform the 'column' first
	m_displayArray[TOP_BUFFER]->transformMatrix(DOWN);
	//Then use the bottom buffer to populate the top buffer in the center
	bottomBuffer = m_displayArray[TOP_BUFFER]->getBottomBuffer();
	m_displayArray[CENTER_DISPLAY]->setTopBuffer(bottomBuffer, 8);
	
	m_displayArray[CENTER_DISPLAY]->transformMatrix(DOWN);
	//Then use the bottom buffer to populate the top buffer in right
	bottomBuffer = m_displayArray[CENTER_DISPLAY]->getBottomBuffer();
	m_displayArray[BOTTOM_BUFFER]->setTopBuffer(bottomBuffer, 8);
	
	//Let the buffer fall off
	m_displayArray[BOTTOM_BUFFER]->transformMatrix(DOWN);
	
	//Transform the tops
	//TODO: Good enough on the periferal buffers?
	m_displayArray[LEFT_BUFFER]->transformMatrix(DOWN);
	m_displayArray[RIGHT_BUFFER]->transformMatrix(DOWN);
	
	//Now determine if we have completed the current buffer
	
	//Decrement the total amount of transforms
	m_topTrans--;
	
	//If we have transformed all the data out of the buffers
	if(m_topTrans == 0){
		m_topTrans = 8;
		
		//Increment the character index to the display buffer
		//Check if we need to reset to begining
		if(++m_displayBufferIndex >= m_displayBufferSize){
			//Circle buffer around
			m_displayBufferIndex=0;
		}
		
		//Populate display buffer with new character
		m_displayArray[TOP_BUFFER]->setCurrentMatrix(m_displayBuffer[m_displayBufferIndex],64);
	}
	return true;
}
