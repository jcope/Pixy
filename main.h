/*****************************************
 EMMA TECHNOLOGIES, L.L.C.
 Copyright (c) 2013.
 All Rights Reserved.
 *****************************************
 Purpose: Define functions that will be executed in the main,
	allowing them to be called from other 'demo' code.
 ****************************************/
#ifndef MAIN_H
#define MAIN_H

#include <stdint.h> //uint8_t

void flushDisplayMatrix(int rowDelay,int loopMax);

//Transition away from providing RGB values, these should be set in the displayMatrix itself
//Will be applied to all 'on' leds in the matrix
void flushDisplayMatrixRGB(int rowDelay,int loopMax, uint8_t redValue, uint8_t greenValue, uint8_t blueValue);

#endif