/*****************************************
 EMMA TECHNOLOGIES, L.L.C.
 Copyright (c) 2013.
 All Rights Reserved.
 *****************************************
 Purpose: This class will manage transforms
	between multiple display Matrix
 ****************************************/
#ifndef DISPLAYMANAGER_H
#define DISPLAYMANAGER_H

//OSX
//#include <cstring> //memset, size_t

//ARDUINO
#include <string.h>//memset
#include <stddef.h> //size_t

//Dual Target
#include <stdint.h> //uint8_t
#include "transform.h"

enum e_buffer{
	LEFT_BUFFER=0,
	CENTER_DISPLAY=1,
	RIGHT_BUFFER=2,
	TOP_BUFFER=3,
	BOTTOM_BUFFER=4
};

class DisplayMatrix;

class DisplayManager {
  public:
    DisplayManager();
    ~DisplayManager();

	
	void createNewDisplay();  //Initializes the display Matrix to empty
	bool transformDisplay(e_direction dir); //Transforms the main display matrix pulling in from the buffers
		
	void populateDisplayBuffer(uint8_t* newBuffer[], size_t numOfCharacters, e_buffer bufferFillDir);
	void nextDisplayBuffer();
	
	DisplayMatrix* getCurrentDisplayMatrix();
	
	void combineDisplayMatrix(uint8_t* addMatrix, size_t matrixSize);
	void setDisplayMatrix(uint8_t* newMatrix, size_t matrixSize);
	
	//Debuggin'
	void toString();
  
  private:
	DisplayMatrix* m_displayArray[5]; 	//Create a display with displayMatrix buffers on each side
	uint8_t* m_displayBuffer[16]; 		//Store pointers to symbols in an buffer to be displayed
	
	uint8_t m_rightTrans;
	uint8_t m_leftTrans;
	uint8_t m_topTrans;
	uint8_t m_bottomTrans;
	
	
	int m_displayBufferIndex;
	int m_displayBufferSize;
	
	void initDataStructures();
	bool transformUp();
	bool transformDown();
	bool transformLeft();
	bool transformRight();
};


#endif
