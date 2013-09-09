/*****************************************
 EMMA TECHNOLOGIES, L.L.C.
 Copyright (c) 2013.
 All Rights Reserved.
 *****************************************
 Purpose: This interface forces certain methods
	to be implemented so that they can be run as
	demo's via the main.
 ****************************************/
#ifndef DEMOIF_H
#define DEMOIF_H

#include <DisplayManager/DisplayManager.h>

class DemoIf {
  public:
    DemoIf(){};
    virtual ~DemoIf(){};
	
	virtual void initDemo() = 0;
	virtual void runDemoLoop() = 0;
	
	DisplayManager* g_displayManager;
};


#endif
