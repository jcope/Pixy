/*****************************************
 EMMA TECHNOLOGIES, L.L.C.
 Copyright (c) 2013.
 All Rights Reserved.
 *****************************************
 Purpose: This class implements a demo that
	scrolls through a full red, green, and blue display
 ****************************************/
#ifndef RGBTEST_H
#define RGBTEST_H

#include "DemoIf.h"

class RGBTest : public DemoIf{
  public:
    RGBTest(DisplayManager* globalDisplayManager);
    ~RGBTest();
	
	void initDemo();
	void runDemoLoop();
};


#endif
