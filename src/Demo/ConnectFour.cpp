/*****************************************
 EMMA TECHNOLOGIES, L.L.C.
 Copyright (c) 2013.
 All Rights Reserved.
 *****************************************/
#include "ConnectFour.h"
#include <Utilities/Utilities.h>
#include <include/colors.h>
#include <main.h> //So we can flush the displayManager to the actual display

ConnectFour::ConnectFour(DisplayManager* globalDisplayManager){
	g_displayManager = globalDisplayManager;
}

ConnectFour::~ConnectFour(){}

void ConnectFour::initDemo(){
	clearC4rows(false); //No need to shift away the pieces becuase this is the begining
}

void ConnectFour::runDemoLoop(){
	playC4();
	//3Sec delay before playing again
	//delay(3000);
}

void ConnectFour::playC4(){

	placeC4piece(4,BLUE);
	placeC4piece(5,RED);
	placeC4piece(3,BLUE);
	placeC4piece(2,RED);
	placeC4piece(4,BLUE);
	placeC4piece(4,RED);
	placeC4piece(5,BLUE);
	placeC4piece(5,RED);

	placeC4piece(3,BLUE);
	placeC4piece(2,RED);
	placeC4piece(3,BLUE);
	placeC4piece(3,RED);
	placeC4piece(6,BLUE);
	placeC4piece(6,RED);
	placeC4piece(6,BLUE);
	placeC4piece(7,RED);
		
	placeC4piece(4,BLUE);
	placeC4piece(8,RED);
	placeC4piece(8,BLUE);
	placeC4piece(5,RED);
	placeC4piece(5,BLUE);
	placeC4piece(6,RED);
	placeC4piece(7,BLUE);
	placeC4piece(8,RED);
		
	placeC4piece(8,BLUE);
	placeC4piece(2,RED);
	placeC4piece(2,BLUE);
	placeC4piece(6,RED);
	placeC4piece(1,BLUE);
	placeC4piece(2,RED);
	placeC4piece(1,BLUE);
	placeC4piece(1,RED);

	placeC4piece(3,BLUE);
	placeC4piece(6,RED);
	placeC4piece(6,BLUE);
	placeC4piece(4,RED);
	placeC4piece(5,BLUE);
	placeC4piece(4,RED);
	placeC4piece(3,BLUE);
	placeC4piece(7,RED);
	
	
	placeC4piece(7,BLUE); //Winner!	
	
		
	//Flash the winning move // 59,52,45,38

	//Capture the current display
	//Now returns an actual matrix object
	displayActual.setCurrentMatrix(g_displayManager->getCurrentDisplayMatrix()->getCurrentMatrix(),64);
	
	//Set up display with alternating moves
	uint8_t* flashDisplay;
	flashDisplay = g_displayManager->getCurrentDisplayMatrix()->getCurrentMatrix();
	
	//Alternate between the two displays
	for(uint8_t flash=0;flash<4;flash++){
		
		flashDisplay[38]=0;
		flashDisplay[45]=0;
		flashDisplay[52]=0;
		flashDisplay[59]=0;
		flushDisplayMatrix(2,30);
		
		flashDisplay[38]=3;
		flashDisplay[45]=3;
		flashDisplay[52]=3;
		flashDisplay[59]=3;
		flushDisplayMatrix(2,30);
	}
	
	//Now let the pieces drop to the bottom
	clearC4rows(true);
}

void ConnectFour::placeC4piece(int row, e_color color){
	
	//Place the move in the buffer
	uint8_t newMove[8];
	memset(newMove,0,sizeof(newMove));
	newMove[row-1]=color;
	
	displayTrans.setTopBuffer(newMove,8);
	
	//Calculate the moves in a row to make and then decrment
	int moves = movesInRow[row-1]; 
	movesInRow[row-1] = movesInRow[row-1]-1;
	
	//moves = 8;
	//The row index will determine how far down the piece falls..
	for(;moves>0;moves--){
		displayTrans.transformMatrix(DOWN);
		
		displayActual.clearDataStructures();//Clear the displayActual
		displayActual.combineMatrix(displayTrans.getCurrentMatrix(),64);
		displayActual.combineMatrix(displayPerm.getCurrentMatrix(),64);
		
		//Set and present the data
		g_displayManager->setDisplayMatrix(displayActual.getCurrentMatrix(),64);
		flushDisplayMatrix(2,20);
	}
	//Set the perm to the actual, left over
	displayPerm.setCurrentMatrix(displayActual.getCurrentMatrix(),64);
	//Clear the displayTrans
	displayTrans.clearDataStructures();
}

void ConnectFour::clearC4rows(bool shiftAway){
	if(shiftAway){
		//Shift the displayMatrix down 8 times
		//to make the pieces apear to fall away
		for(int rowShift=8;rowShift>0;rowShift--){
			g_displayManager->transformDisplay(DOWN); //Down 1
			
		flushDisplayMatrix(2,rowShift*4); //This will have the effect of speeding up as it clears
		}
	}
	//Clear the data structures
	displayTrans.clearDataStructures();
	displayPerm.clearDataStructures();
	displayActual.clearDataStructures();
	//Reset the row counts
	memset(movesInRow,8,sizeof(movesInRow));
}