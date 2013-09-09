/*****************************************
 EMMA TECHNOLOGIES, L.L.C.
 Copyright (c) 2013.
 All Rights Reserved.
 *****************************************
 Purpose: This class implements a demo that
	mimics the green falling 0/1 as depicted
	in the movie 'Matrix'.
	Random green led's fall in the colunms
	at different speeds
 ****************************************/
#ifndef FALLINGMATRIX_H
#define FALLINGMATRIX_H

#include "DemoIf.h"
#include <DisplayMatrix/DisplayMatrix.h>

class FallingMatrix : public DemoIf{
  public:
    FallingMatrix(DisplayManager* globalDisplayManager);
    ~FallingMatrix();
	
	void initDemo();
	void runDemoLoop();
	
	DisplayMatrix display;
	uint8_t loopCnt;
};


#endif
