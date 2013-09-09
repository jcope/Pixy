/*
CShiftPWM.cpp - ShiftPWM.h - Library for Arduino to PWM many outputs using shift registers
Copyright (c) 2011-2012 Elco Jacobs, www.elcojacobs.com
All right reserved.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "CShiftPWM.h"
#include <Arduino.h>
//Emma Tech
#include <include/RGBPins.h>
#include <DisplayManager/DisplayManager.h>
#include <DisplayMatrix/DisplayMatrix.h>

CShiftPWM::CShiftPWM(int timerInUse, bool noSPI, int latchPin, int dataPin, int clockPin) :  // Constants are set in initializer list
					m_timer(timerInUse), m_noSPI(noSPI), m_latchPin(latchPin), m_dataPin(dataPin), m_clockPin(clockPin){
	m_ledFrequency = 0;
	m_maxBrightness = 0;
	m_amountOfRegisters = NUM_REGISTERS;    
	m_amountOfOutputs = NUM_OUTPUT_PINS;
	m_pinGrouping = 1; // Default = RGBRGBRGB... PinGrouping = 3 means: RRRGGGBBBRRRGGGBBB...
	m_counter = 0;
	//Emma Tech
	m_displayManager = new DisplayManager();
	initDataRows();
}

CShiftPWM::~CShiftPWM() {

}

bool CShiftPWM::IsValidPin(int pin){
	if(pin<m_amountOfOutputs){
		return 1;
	}
	return 0;
}

void CShiftPWM::initDataRows(void){	
	memset(&m_displayMatrix,0,192);
}

//This will pull data from the DisplayMatrix, so make sure it is populated/transformed correctly
void CShiftPWM::populateDisplayData(){
	populateDisplayData(255,255,255);
}

void CShiftPWM::populateDisplayData(uint8_t redValue, uint8_t greenValue, uint8_t blueValue){
	uint8_t* currentMatrix = m_displayManager->getCurrentDisplayMatrix()->getCurrentMatrix();
	
	//int r,g,b;
	int rowIndex=0;
	int letterIndex=0;
	for(rowIndex=0,letterIndex=0;rowIndex<8;rowIndex++){
		int ledIndex=0;
		for(int pinGroup = 0; pinGroup<8; pinGroup++){
			//Convert the current matrix into a RGB matrix where 1index=3index
			//Utilities Method
			m_displayMatrix[(ledIndex++) + (rowIndex*24)] = (currentMatrix[letterIndex]==3) ? blueValue : 0;
			m_displayMatrix[(ledIndex++) + (rowIndex*24)] = (currentMatrix[letterIndex]==12) ? greenValue : 0;
			m_displayMatrix[(ledIndex++) + (rowIndex*24)] = (currentMatrix[letterIndex++]==48) ? redValue : 0;
		}
	}
}

void CShiftPWM::Start(int ledFrequency, unsigned char maxBrightness){
	// Configure and enable timer1 or timer 2 for a compare and match A interrupt.    
	m_ledFrequency = ledFrequency;
	m_maxBrightness = maxBrightness;
	
	pinMode(m_dataPin, OUTPUT);
	pinMode(m_clockPin, OUTPUT);
	pinMode(m_latchPin, OUTPUT);
	
	digitalWrite(m_clockPin, LOW);
	digitalWrite(m_dataPin, LOW);
  	
	if(!m_noSPI){ // initialize SPI when used
		// The least significant bit shoult be sent out by the SPI port first.
		// equals SPI.setBitOrder(LSBFIRST);
		SPCR |= _BV(DORD);
		
		// Here you can set the clock speed of the SPI port. Default is DIV4, which is 4MHz with a 16Mhz system clock.
		// If you encounter problems due to long wires or capacitive loads, try lowering the SPI clock.
		// equals SPI.setClockDivider(SPI_CLOCK_DIV4); 
		
		SPCR = (SPCR & 0b11111000);
		SPSR = (SPSR & 0b11111110);
		
		// Set clock polarity and phase for shift registers (Mode 3)
		SPCR |= _BV(CPOL);
		SPCR |= _BV(CPHA);
		
		// When the SS pin is set as OUTPUT, it can be used as
		// a general purpose output port (it doesn't influence
		// SPI operations).
		pinMode(SS, OUTPUT);
		digitalWrite(SS, HIGH);

		// Warning: if the SS pin ever becomes a LOW INPUT then SPI 
		// automatically switches to Slave, so the data direction of 
		// the SS pin MUST be kept as OUTPUT.
		SPCR |= _BV(MSTR);
		SPCR |= _BV(SPE);
	}
	
	if(LoadNotTooHigh() ){
		InitTimer1();
	}
	else{
		cli(); //Disable interrupts
	}
}

bool CShiftPWM::LoadNotTooHigh(void){
	// This function calculates if the interrupt load would become higher than 0.9 and prints an error if it would.
	// This is with inverted outputs, which is worst case. Without inverting, it would be 42 per register.
	float interruptDuration;
	if(m_noSPI){
		interruptDuration = 96+108*(float) m_amountOfRegisters;
	}
	else{
		interruptDuration = 97+43* (float) m_amountOfRegisters;
	}
	float interruptFrequency = (float) m_ledFrequency* ((float) m_maxBrightness + 1);
	float load = interruptDuration*interruptFrequency/F_CPU;

	if(load > 0.9){
		return 0;
	}
	else{
		return 1;
	}

}

void CShiftPWM::InitTimer1(void){
	/* Configure timer1 in CTC mode: clear the timer on compare match 
	* See the Atmega328 Datasheet 15.9.2 for an explanation on CTC mode.
	* See table 15-4 in the datasheet. */

	bitSet(TCCR1B,WGM12);
	bitClear(TCCR1B,WGM13);
	bitClear(TCCR1A,WGM11);
	bitClear(TCCR1A,WGM10);


	/*  Select clock source: internal I/O clock, without a prescaler
	*  This is the fastest possible clock source for the highest accuracy.
	*  See table 15-5 in the datasheet. */

	bitSet(TCCR1B,CS10);
	bitClear(TCCR1B,CS11);
	bitClear(TCCR1B,CS12);

	/* The timer will generate an interrupt when the value we load in OCR1A matches the timer value.
	* One period of the timer, from 0 to OCR1A will therefore be (OCR1A+1)/(timer clock frequency).
	* We want the frequency of the timer to be (LED frequency)*(number of brightness levels)
	* So the value we want for OCR1A is: timer clock frequency/(LED frequency * number of bightness levels)-1 */
	m_prescaler = 1;
	OCR1A = round((float) F_CPU/((float) m_ledFrequency*((float) m_maxBrightness+1)))-1;
	/* Finally enable the timer interrupt */
	/* See datasheet  15.11.8) */
	bitSet(TIMSK1,OCIE1A);
}
