/*****************************************
 EMMA TECHNOLOGIES, L.L.C.
 Copyright (c) 2013.
 All Rights Reserved.
 *****************************************
 Purpose: Main entry point into the Pixy program.
 ****************************************/
#include "main.h"
//3rd Party
#include <ShiftPWM/ShiftPWM.h>   // include ShiftPWM.h after setting the pins!
//Emma Tech
#include <DisplayMatrix/DisplayMatrix.h>
#include <Utilities/Utilities.h>
#include <include/RGBPins.h>
//Demo Includes
#include <Demo/RGBTest.h>
#include <Demo/NumberCountDown.h>
#include <Demo/ScrollText.h>
#include <Demo/RandomRGB.h>
#include <Demo/FallingMatrix.h>
#include <Demo/ConnectFour.h>


DemoIf* demoProgram;
//This 'flashes' all the rows in succession to display an active matrix
void presentDataMatrix(int rowDelay,int loopMax);

int main(void){
	init();
	ShiftPWM.m_displayManager->createNewDisplay();
	
	//Determine Which Demo to run
	demoProgram = new RGBTest(ShiftPWM.m_displayManager);
	//demoProgram = new ScrollText(ShiftPWM.m_displayManager);
	//demoProgram = new NumberCountDown(ShiftPWM.m_displayManager);
	//demoProgram = new RandomRGB(ShiftPWM.m_displayManager);
	//demoProgram = new FallingMatrix(ShiftPWM.m_displayManager);
	//demoProgram = new ConnectFour(ShiftPWM.m_displayManager);
	
	setup();
	for (;;){
		loop();
	}
	return 0;
}

void setup(){
	DDRD = 255; 	//Enable output on all pins on PortD
	PORTD = 0;		// Turn all controls LED's off.
  	ShiftPWM.Start(PWM_FREQUENCY,MAX_BRIGHTNESS); 	//Initialize the ShiftPWM 

	demoProgram->initDemo();	
}
void loop() {
	demoProgram->runDemoLoop();
}

void flushDisplayMatrix(int rowDelay,int loopMax){
	ShiftPWM.populateDisplayData();
	presentDataMatrix(rowDelay,loopMax);	
}

//Transition away from providing RGB values, these should be set in the displayMatrix itself
//Will be applied to all 'on' leds in the matrix
void flushDisplayMatrixRGB(int rowDelay,int loopMax, uint8_t redValue, uint8_t greenValue, uint8_t blueValue){
	ShiftPWM.populateDisplayData(redValue,greenValue,blueValue);	
	presentDataMatrix(rowDelay,loopMax);
}

//Present each row for rowDelay microseconds
//Loop through all the rows for loopMax
void presentDataMatrix(int rowDelay,int loopMax){

	//Display the same image for x amount of loops
	for(int loop=0;loop<loopMax;loop++){
		
		int portControl = 1;
		int rowIndex=0;
		//Present all rows of the image
		for(;rowIndex<8;rowIndex++){
  			delay(rowDelay);
			//Practice shifting these two around
			ShiftPWM.m_ledPtr=&ShiftPWM.m_displayMatrix[rowIndex*24];
			PORTD= portControl;

			//Set up portControl for next iteration
			portControl = portControl*2;
		}
	}
}
