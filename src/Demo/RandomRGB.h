/*****************************************
 EMMA TECHNOLOGIES, L.L.C.
 Copyright (c) 2013.
 All Rights Reserved.
 *****************************************
 Purpose: This class implements a demo that
	starts off with a random matrix of R/G/B
	and randomly shifts up/down/left/right,
	populateing the edges with more random values
 ****************************************/
#ifndef RANDOMRGB_H
#define RANDOMRGB_H

#include "DemoIf.h"
#include <DisplayMatrix/DisplayMatrix.h>

class RandomRGB : public DemoIf{
  public:
    RandomRGB(DisplayManager* globalDisplayManager);
    ~RandomRGB();
	
	void initDemo();
	void runDemoLoop();
	
	DisplayMatrix display;
};


#endif
