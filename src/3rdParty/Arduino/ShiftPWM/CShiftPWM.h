/*
CShiftPWM.h - Library for Arduino to PWM many outputs using shift registers
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

#ifndef CShiftPWM_h
#define CShiftPWM_h

#include <stdint.h> //uint8_t

class DisplayManager;

class CShiftPWM{
public:
	CShiftPWM(int timerInUse, bool noSPI, int latchPin, int dataPin, int clockPin);
	~CShiftPWM();

	void Start(int ledFrequency, unsigned char max_Brightness);
	void populateDisplayData(); //Will use 255 (max brightness) for all rgb values
	void populateDisplayData(uint8_t redValue, uint8_t greenValue, uint8_t blueValue);

private:
	bool IsValidPin(int pin);
	void InitTimer1(void);
	bool LoadNotTooHigh(void);
	
	void initDataRows(void);
	
	const int m_timer;
	const bool m_noSPI;
	const int m_latchPin;
	const int m_dataPin;
	const int m_clockPin;	
	int m_prescaler;
	

public:
	int m_ledFrequency;  
	unsigned char m_maxBrightness;
	unsigned char m_amountOfRegisters;
	int m_amountOfOutputs;
	int m_pinGrouping;
	int m_counter;
	
	unsigned char* m_ledPtr;
	unsigned char m_displayMatrix[192];
	
	DisplayManager* m_displayManager;

};

#endif
