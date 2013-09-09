/*****************************************
 EMMA TECHNOLOGIES, L.L.C.
 Copyright (c) 2013.
 All Rights Reserved.
 *****************************************
 Purpose: This class defines and supplies
	Utilities functions that are generic to 
	the program.
 ****************************************/
#ifndef UTILITIES_H
#define UTILITIES_H

#include <stdint.h> //uint8_t

class Utilities {
  public:
    Utilities();
    ~Utilities();
	static int randomNumber(int max);
	static int randomNumber(int min, int max);
	
	static void extractRGBvalues(uint8_t baseValue, uint8_t& r, uint8_t& g, uint8_t& b);
	
	static void initClass();
	static bool init;
	
};


#endif
