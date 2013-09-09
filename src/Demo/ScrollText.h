/*****************************************
 EMMA TECHNOLOGIES, L.L.C.
 Copyright (c) 2013.
 All Rights Reserved.
 *****************************************
 Purpose: This class implements a demo that
	scrolls text horizontally across the display
 ****************************************/
#ifndef SCROLLTEXT_H
#define SCROLLTEXT_H

#include "DemoIf.h"

class ScrollText : public DemoIf{
  public:
    ScrollText(DisplayManager* globalDisplayManager);
    ~ScrollText();
	
	void initDemo();
	void runDemoLoop();
};


#endif
