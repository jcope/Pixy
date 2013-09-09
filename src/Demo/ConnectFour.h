/*****************************************
 EMMA TECHNOLOGIES, L.L.C.
 Copyright (c) 2013.
 All Rights Reserved.
 *****************************************
 Purpose: This class implements a demo that
	plays the game connect4.
	We place red and blue pieces and let
	them fall down in the columns. When
	a winning move is made, the play flashes
	and then the pieces fall out the bottom
 ****************************************/
#ifndef CONNECTFOUR_H
#define CONNECTFOUR_H

#include "DemoIf.h"
#include <DisplayMatrix/DisplayMatrix.h>
#include <include/colors.h>

class ConnectFour : public DemoIf{
  public:
    ConnectFour(DisplayManager* globalDisplayManager);
    ~ConnectFour();
	
	void initDemo();
	void runDemoLoop();
	
	uint8_t movesInRow[8];
	DisplayMatrix displayTrans;
	DisplayMatrix displayPerm;
	DisplayMatrix displayActual;
	
	void playC4();
	void placeC4piece(int row, e_color color);
	void clearC4rows(bool shiftAway);
};


#endif
