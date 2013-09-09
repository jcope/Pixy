/*****************************************
 EMMA TECHNOLOGIES, L.L.C.
 Copyright (c) 2013.
 All Rights Reserved.
 ****************************************/
#include "DisplayMatrix.h"

//OSX
//#include <cstdio> //printf
#include <stdlib.h>

//ARDUINO
#include <stdio.h> //printf

//Common
#include <colors.h>
#include <Utilities/Utilities.h>

DisplayMatrix::DisplayMatrix(){
	initDataStructures();
}

DisplayMatrix::~DisplayMatrix(){

}

uint8_t* DisplayMatrix::getCurrentMatrix(){
	return currentMatrix;
}

uint8_t* DisplayMatrix::getTopBuffer(){
	return top;
}

uint8_t* DisplayMatrix::getRightBuffer(){
	return right;
}

uint8_t* DisplayMatrix::getBottomBuffer(){
	return bottom;
}

uint8_t* DisplayMatrix::getLeftBuffer(){
	return left;
}

bool DisplayMatrix::getCurrentMatrixRow(int row, uint8_t* rowBuffer){
	bool retVal = false;
	if(row>=0 && row<8){
		retVal = true;
		memcpy(rowBuffer,&currentMatrix[(row)*8],8);
	}
	else{ //Invalid parameter, return blank row
		memset(rowBuffer,-1,8);
	}
	return retVal;
}


bool DisplayMatrix::setCurrentDisplay(uint8_t* newMatrix, size_t matrixSize,
						uint8_t* newTop, size_t topSize,
						uint8_t* newRight, size_t rightSize,
						uint8_t* newBottom, size_t bottomSize,
						uint8_t* newLeft, size_t leftSize){
	bool retVal = false; //Need to make sure all input data is valid sizes
	retVal = setCurrentMatrix(newMatrix, matrixSize);
	if(retVal == true){
		if(topSize == 8 && rightSize == 8 && bottomSize == 8 && leftSize == 8){
			memcpy(top,newTop,sizeof(top));
			memcpy(right,newRight,sizeof(right));
			memcpy(bottom,newBottom,sizeof(bottom));
			memcpy(left,newLeft,sizeof(left));
		}
		else{
			retVal = false;
		}
	}
	return retVal;
}

bool DisplayMatrix::setTopBuffer(uint8_t* newTop, size_t topSize){
	bool retVal = false; //Need to make sure all input data is valid sizes
	if(topSize == 8) {
		memcpy(top,newTop,sizeof(top));
	}
	else{
		retVal = false;
	}
	return retVal;
}

bool DisplayMatrix::setLeftBuffer(uint8_t* newLeft, size_t leftSize){
	bool retVal = false; //Need to make sure all input data is valid sizes
	if(leftSize == 8) {
		memcpy(left,newLeft,sizeof(left));
	}
	else{
		retVal = false;
	}
	return retVal;
}

bool DisplayMatrix::setRightBuffer(uint8_t* newRight, size_t rightSize){
	bool retVal = false; //Need to make sure all input data is valid sizes
	if(rightSize == 8) {
		memcpy(right,newRight,sizeof(right));
	}
	else{
		retVal = false;
	}
	return retVal;
}

bool DisplayMatrix::setBottomBuffer(uint8_t* newBottom, size_t bottomSize){
	bool retVal = false; //Need to make sure all input data is valid sizes
	if(bottomSize == 8) {
		memcpy(bottom,newBottom,sizeof(bottom));
	}
	else{
		retVal = false;
	}
	return retVal;
}
	
bool DisplayMatrix::setCurrentMatrix(uint8_t* newMatrix,size_t matrixSize){
	bool retVal = false; //If the copy was valid, ie input data valid
	if(matrixSize==64){ //Only proceede if 64 data points were provided
		memcpy(currentMatrix,newMatrix,sizeof(currentMatrix));
		retVal = true;
	}
	return retVal;
}

//This will use an OR operation to combine the two matrix
bool DisplayMatrix::combineMatrix(uint8_t* addMatrix, size_t matrixSize){
	bool retVal = false; //If the addition was valid, ie input data valid
	if(matrixSize==64){ //Only proceede if 64 data points were provided
		for(int ledIndex=0;ledIndex<64;ledIndex++){
			currentMatrix[ledIndex]= currentMatrix[ledIndex] | addMatrix[ledIndex];
		}
		retVal = true;
	}
	return retVal;
}

//Column 0->7
bool DisplayMatrix::transformColumnDown(uint8_t column){
	//Transform the column
	for(uint8_t rowIndex=7;rowIndex>0;rowIndex--){
		currentMatrix[(8*rowIndex)+column]=currentMatrix[(8*(rowIndex-1))+column];
	}
	//Pull the top row from the buffer
	currentMatrix[column] = top[column];
	//TODO: Better value
	return true;
}

bool DisplayMatrix::transformMatrix(e_direction dir){
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
	
	
//blue=3
//green=12
//red=48
uint8_t DisplayMatrix::randomRGB(){
	uint8_t retRGB = 0;
	uint8_t randomValue = Utilities::randomNumber(3);
	
	switch(randomValue){
		case 0:
			retRGB = BLUE;
			break;
		case 1:
			retRGB = GREEN;
			break;
		case 2:
			retRGB = RED;
			break;
		default:
			retRGB = _CLEAR;
			break;	
	}
	return retRGB;
}
bool DisplayMatrix::randomFillRow(uint8_t* rowToFill, size_t rowSize, uint8_t rgbValue){
	bool retVal = false;
	if(rowSize == 8){
		uint8_t randomValue = Utilities::randomNumber(255);
		
		rowToFill[0] = (1 & randomValue) ? rgbValue : 0;
		rowToFill[1] = (2 & randomValue) ? rgbValue : 0;
		rowToFill[2] = (4 & randomValue) ? rgbValue : 0;
		rowToFill[3] = (8 & randomValue) ? rgbValue : 0;
		
		rowToFill[4] = (16 & randomValue) ? rgbValue : 0;
		rowToFill[5] = (32 & randomValue) ? rgbValue : 0;
		rowToFill[6] = (64 & randomValue) ? rgbValue : 0;
		rowToFill[7] = (128 & randomValue) ? rgbValue : 0;
		retVal = true;
	}
	return retVal;
}
bool DisplayMatrix::randomFillRowRGB(uint8_t* rowToFill, size_t rowSize){
	bool retVal = false;
	if(rowSize == 8){
		rowToFill[0] = randomRGB();
		rowToFill[1] = randomRGB();
		rowToFill[2] = randomRGB();
		rowToFill[3] = randomRGB();

		rowToFill[4] = randomRGB();
		rowToFill[5] = randomRGB();
		rowToFill[6] = randomRGB();
		rowToFill[7] = randomRGB();
		retVal = true;
	}
	return retVal;
}


//For Debugging..
void DisplayMatrix::toString(){
	//Print out the Matrix
	printf("Full Matrix:\n");
	int row=0;
	int column=0;
	//Top
	printf("  ");
	for(row=0;row<8;row++){
		printf("%d,",top[row]);
	}
	printf("\n");
	
	//Matrix with side buffers
	for(column=0;column<8;column++){
		printf("%d ",left[column]);
		for(row=0;row<8;row++){
			printf("%d,",currentMatrix[column*8+row]);
		}
		printf(" %d\n",right[column]);
	}
	
	//Bottom
	printf("  ");
	for(row=0;row<8;row++){
		printf("%d,",bottom[row]);
	}
	printf("\n");
}

void DisplayMatrix::clearDataStructures(){
	initDataStructures();
}
/******PRIVATE*******/
void DisplayMatrix::initDataStructures(){
	memset(top,0,sizeof(top));
	memset(right,0,sizeof(right));
	memset(bottom,0,sizeof(bottom));
	memset(left,0,sizeof(left));
	memset(currentMatrix,0,sizeof(currentMatrix));
}

bool DisplayMatrix::transformUp(){
	int index = 0; //Index used for transfroming buffers
	
	//Transform the top buffer first, pulling from the currentMatrix
	for(index=0;index<8;index++){
		top[index]=currentMatrix[index];
	}

	//Transform currentMatrix
	for(index=0;index+8<64;index++){
		currentMatrix[index]=currentMatrix[index+8];
	}
	//Pull the last row from the bottom buffer
	//Bottom row of current matrix gets pulled form bottom buffer
	for(int index_b=0;index_b<8;index++,index_b++){
		currentMatrix[index]=bottom[index_b];
	}
	//Zero out the excess if the offset went over
	for(index=0;index<8;index++){
		currentMatrix[index+56]=bottom[index];
	}
	
	//Now transform the left,right,bottom buffers
	//Left
	for(index=0;index<7;index++){
		left[index]=left[index+1];
	}
	//TODO: May lead to invalid data by assuming '0'
	left[7]=0;
	
	//Right
	for(index=0;index<7;index++){
		right[index]=right[index+1];
	}
	//TODO: May lead to invalid data by assuming '0'
	right[7]=0;
	
	//Bottom
	for(index=0;index<8;index++){
		bottom[index]=0;
	}
	
	return true; //Until better criteria is established
}

bool DisplayMatrix::transformRight(){
	int index = 0; //Index used for transfroming buffers
	
	//Transform right buffer first, pull from the currentMatrix
	for(index=0;index<8;index++){
		right[index]=currentMatrix[((index+1)*8)-1];
	}

	//Transform the current Matrix
	for(index=63;index>0;index--){
		//This will lazily copy in the left column incorrectly
		currentMatrix[index]=currentMatrix[index-1];
	}
	//Fill the left column with the left buffer
	for(index=0;index<8;index++){
		currentMatrix[index*8]=left[index];
	}
	
	//Now transform the top,bottom,left buffers
	//Top
	for(index=7;index>0;index--){
		top[index]=top[index-1];
	}
	//TODO: May lead to invalid data by assuming '0'
	top[0]=0;
	
	//Bottom
	for(index=7;index>0;index--){
		bottom[index]=bottom[index-1];
	}
	//TODO: May lead to invalid data by assuming '0'
	bottom[0]=0;
	
	//Left
	for(index=0;index<8;index++){
		left[index]=0;
	}

	return true; //Until better criteria is established
}

bool DisplayMatrix::transformDown(){
	int index = 0; //Index used for transfroming buffers
	
	//Transform bottom buffer first, pull from the current Matrix
	for(index=0;index<8;index++){
		bottom[index]=currentMatrix[56+index];
	}

	//Transform currentMatrix
	for(index=63;index>0;index--){
		currentMatrix[index]=currentMatrix[index-8];
	}
	//First row of current Matrix gets pulled in from top buffer
	for(index=0;index<8;index++){
		currentMatrix[index]=top[index];
	}
	
	//Now transform the top,left,right buffers
	//Top
	for(index=0;index<8;index++){
		top[index]=0;
	}
	
	//Left
	for(index=7;index>0;index--){
		left[index]=left[index-1];
	}
	//TODO: May lead to invalid data by assuming '0'
	left[0]=0;

	
	//Right
	for(index=7;index>0;index--){
		right[index]=right[index-1];
	}
	//TODO: May lead to invalid data by assuming '0'
	right[0]=0;
	
	return true; //Until better criteria is established
}

bool DisplayMatrix::transformLeft(){
	int index = 0; //Index used for transfroming buffers
	
	//Transform left buffer first, pull from the current Matrix
	for(index=0;index<8;index++){
		left[index]=currentMatrix[index*8];
	}

	//Transform currentMatrix
	for(index=0;index<63;index++){
		//This will lazily copy incorrect data for the right column
		currentMatrix[index]=currentMatrix[index+1];
	}
	//Correct right column by copying from the right buffer
	for(index=0;index<8;index++){
		currentMatrix[8*(index+1)-1]=right[index];
	}
	
	//Now transform the top,bottom,right buffers
	//Top
	for(index=0;index<7;index++){
		top[index]=top[index+1];
	}
	//TODO: May lead to invalid data by assuming '0'
	top[7]=0;

	//Bottom
	for(index=0;index<7;index++){
		bottom[index]=bottom[index+1];
	}
	//TODO: May lead to invalid data by assuming '0'
	bottom[7]=0;
	
	//Right
	for(index=0;index<8;index++){
		right[index]=0;
	}
	
	return true; //Until better criteria is established
}

