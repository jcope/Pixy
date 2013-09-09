/*
ShiftPWM.h - Library for Arduino to PWM many outputs using shift registers
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


#ifndef ShiftPWM_H
#define ShiftPWM_H

#include "pins_arduino_compile_time.h" // My own version of pins arduino, which does not define the arrays in program memory
#include <Arduino.h>
#include <stdint.h> //uint8_t

#include "CShiftPWM.h"
#include "RGBPins.h"

//Program Specific	
const int ShiftPWM_latchPin=10;
const bool ShiftPWM_invertOutputs = false; //LED's turn on when pin is high
const bool ShiftPWM_balanceLoad = false; //true will prevent all signals from being high at same time

// The ShiftPWM object is created in the header file, instead of defining it as extern here and creating it in the cpp file.
// If the ShiftPWM object is created in the cpp file, it is separately compiled with the library.
// The compiler cannot treat it as constant and cannot optimize well: it will generate many memory accesses in the interrupt function.

CShiftPWM ShiftPWM(1,false,ShiftPWM_latchPin,MOSI,SCK);

// The macro below uses 3 instructions per pin to generate the byte to transfer with SPI
// Retreive duty cycle setting from memory (ldd, 2 clockcycles)
// Compare with the counter (cp, 1 clockcycle) --> result is stored in carry
// Use the rotate over carry right to shift the compare result into the byte. (1 clockcycle).
#define add_one_pin_to_byte(sendbyte, counter, ledPtr) \
{ \
	unsigned char pwmval=*ledPtr; \
	asm volatile ("cp %0, %1" : /* No outputs */ : "r" (counter), "r" (pwmval): ); \
	asm volatile ("ror %0" : "+r" (sendbyte) : "r" (sendbyte) : ); 			\
}

static inline void ShiftPWM_handleInterrupt(void){	
	sei(); //enable interrupt nesting to prevent disturbing other interrupt functions (servo's for example).
	
	// Look up which bit of which output register corresponds to the pin.
	// This should be constant, so the compiler can optimize this code away and use sbi and cbi instructions
	// The compiler only knows this if this function is compiled in the same file as the pin setting.
	// That is the reason the full funcion is in the header file, instead of only the prototype.
	// If this function is defined in cpp files of the library, it is compiled seperately from the main file.
	// The compiler does not recognize the pins/ports as constant and sbi and cbi instructions cannot be used.


	volatile uint8_t * const latchPort = port_to_output_PGM_ct[digital_pin_to_port_PGM_ct[ShiftPWM_latchPin]];
	const uint8_t latchBit =  digital_pin_to_bit_PGM_ct[ShiftPWM_latchPin];

	// Define a pointer that will be used to access the values for each output. 
	// Let it point one past the last value, because it is decreased before it is used.
	
	//unsigned char * ledPtr=&ShiftPWM.m_ledPtr[NUM_OUTPUT_PINS];
	unsigned char * ledPtr=&ShiftPWM.m_ledPtr[0];
	
	// Write shift register latch clock low 
	bitClear(*latchPort, latchBit);
	unsigned char counter = ShiftPWM.m_counter;
	
	//Use SPI to send out all bits
	SPDR = 0; // write bogus bit to the SPI, because in the loop there is a receive before send.
	for(unsigned char i = ShiftPWM.m_amountOfRegisters; i>0;--i){   // do a whole shift register at once. This unrolls the loop for extra speed
		unsigned char sendbyte = 0;  // no need to initialize, all bits are replaced
		if(ShiftPWM_balanceLoad){
			counter +=8; // distribute the load by using a shifted counter per shift register
		}
		add_one_pin_to_byte(sendbyte, counter,  ledPtr++);
		add_one_pin_to_byte(sendbyte, counter,  ledPtr++);
		add_one_pin_to_byte(sendbyte, counter,  ledPtr++);
		add_one_pin_to_byte(sendbyte, counter,  ledPtr++);

		add_one_pin_to_byte(sendbyte, counter,  ledPtr++);
		add_one_pin_to_byte(sendbyte, counter,  ledPtr++);
		add_one_pin_to_byte(sendbyte, counter,  ledPtr++);
		add_one_pin_to_byte(sendbyte, counter,  ledPtr++);

		while (!(SPSR & _BV(SPIF)));    // wait for last send to finish and retreive answer. Retreive must be done, otherwise the SPI will not work.
		if(ShiftPWM_invertOutputs){	
			sendbyte = ~sendbyte; // Invert the byte if needed.
		}
		SPDR = sendbyte; // Send the byte to the SPI
	}
	while (!(SPSR & _BV(SPIF))); // wait for last send to complete.
	
	// Write shift register latch clock high 
	bitSet(*latchPort, latchBit);
	
	if(ShiftPWM.m_counter<ShiftPWM.m_maxBrightness){
		ShiftPWM.m_counter++; // Increase the counter
	}
	else{
		ShiftPWM.m_counter=0; // Reset counter if it maximum brightness has been reached
	} 	
} 

// See table  11-1 for the interrupt vectors */

//Install the Interrupt Service Routine (ISR) for Timer1 compare and match A.
ISR(TIMER1_COMPA_vect) {
	ShiftPWM_handleInterrupt();
}


// #endif for include once.
#endif
