/*****************************************
 EMMA TECHNOLOGIES, L.L.C.
 Copyright (c) 2013.
 All Rights Reserved.
 *****************************************
 Purpose: This class implements a demo that
	counts down numbers, fading them out to the next
 ****************************************/
#ifndef NUMBERCOUNTDOWN_H
#define NUMBERCOUNTDOWN_H

#include "DemoIf.h"

class NumberCountDown : public DemoIf{
  public:
    NumberCountDown(DisplayManager* globalDisplayManager);
    ~NumberCountDown();
	
	void initDemo();
	void runDemoLoop();
};


#endif
