/*****************************************
 EMMA TECHNOLOGIES, L.L.C.
 Copyright (c) 2013.
 All Rights Reserved.
 *****************************************
 Purpose: This class will contain the data for
	the 8x8 led display as well as provide data
	manipulation utilities.
 ****************************************/
#ifndef DISPLAYMATRIX_H
#define DISPLAYMATRIX_H

//OSX
//#include <cstring> //memset, size_t

//ARDUINO
#include <string.h>//memset
#include <stddef.h> //size_t

//Dual Target
#include <stdint.h> //uint8_t
#include "transform.h"

class DisplayMatrix {
  public:
    DisplayMatrix();
    ~DisplayMatrix();

	//Getters/Setters
	bool setCurrentMatrix(uint8_t* newMatrix, size_t matrixSize);
	
	bool setCurrentDisplay(uint8_t* newMatrix, size_t matrixSize,
							uint8_t* top, size_t topSize,
							uint8_t* right, size_t rightSize,
							uint8_t* bottom, size_t bottomSize,
							uint8_t* left, size_t leftSize);
	
	uint8_t* getCurrentMatrix();
	uint8_t* getTopBuffer();
	uint8_t* getRightBuffer();
	uint8_t* getBottomBuffer();
	uint8_t* getLeftBuffer();
	
	bool setTopBuffer(uint8_t* newTop, size_t topSize);
	bool setLeftBuffer(uint8_t* newLeft, size_t leftSize);
	bool setRightBuffer(uint8_t* newRight, size_t rightSize);
	bool setBottomBuffer(uint8_t* newBottom, size_t bottomSize);
	
	
	bool getCurrentMatrixRow(int row, uint8_t* rowBuffer);
	//uint8_t* getCurrentMatrixColumn(int column);
	
	//Utility Functions
	//0-8 will return true
	void clearDataStructures();
	bool transformMatrix(e_direction dir);
	
	bool transformColumnDown(uint8_t column);
	
	bool combineMatrix(uint8_t* addMatrix, size_t matrixSize);
	
	//Class Functions
	static bool randomFillRow(uint8_t* rowToFill, size_t rowSize,uint8_t rgbValue);
	static bool randomFillRowRGB(uint8_t* rowToFill, size_t rowSize);
	static uint8_t randomRGB();
	
	//Debuggin'
	void toString();
  
  private:
	
	uint8_t top[8];
	uint8_t right[8];
	uint8_t bottom[8];
	uint8_t left[8];
	uint8_t currentMatrix[64];
	
	void initDataStructures();
	bool transformUp();
	bool transformLeft();
	bool transformRight();
	bool transformDown();
};


#endif
