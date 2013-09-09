/*****************************************
 EMMA TECHNOLOGIES, L.L.C.
 Copyright (c) 2013.
 All Rights Reserved.
 *****************************************
 Purpose: To demonstrate sample unit test
   and test out the build environment. 
 ****************************************/
#include <gtest/gtest.h>
#include "../DisplayManager.h"
#include <src/DisplayMatrix/DisplayMatrix.h>
#include "testData.h"
#include "alphabet.h"

class DisplayManagerTest : public ::testing::Test {
 protected:
	// Called before the first test in this test case.
  	static void SetUpTestCase() {
		displayManager = new DisplayManager();
  	}

  	// Called after the last test in this test case.
  	static void TearDownTestCase() {
    	delete displayManager;
    	displayManager = NULL;
  	}

  	// Called prior to each individual test
  	virtual void SetUp() {
		//Make sure the instance variable isn't null
		EXPECT_NE(displayManager,(void*)NULL);
  	}
  
	// Called after each individual test
	virtual void TearDown() { 
  	
	}

  	// Some expensive resource shared by all tests.
  	static DisplayManager* displayManager;
};

DisplayManager* DisplayManagerTest::displayManager = NULL;

/*************
We test all the shifts with 32 transforms,
This sets the final display to be the first character in
the display buffer, becuase the transforms wrap around
We will test the final display to be the first character in the
display buffer
**************/
/***************BEGIN TESTS***************/
TEST_F(DisplayManagerTest, TestToString) {
	displayManager->createNewDisplay();
	//displayManager->toString();
}

TEST_F(DisplayManagerTest, TestShiftLeft) {
	displayManager->createNewDisplay();

	uint8_t* display[] = {E,m,a};
	displayManager->populateDisplayBuffer(display,3,RIGHT_BUFFER);
	//displayManager->toString();
	
	for(int transform = 0; transform < 32; transform++){
		displayManager->transformDisplay(LEFT);
		//displayManager->toString();	
	}
	//We will only validate the final display..
	int retCmp = 0;
	DisplayMatrix* currentMatrix;
		
	currentMatrix = displayManager->getCurrentDisplayMatrix();
	retCmp = memcmp(E,currentMatrix->getCurrentMatrix(),sizeof(E));
	EXPECT_EQ(0,retCmp);
}

TEST_F(DisplayManagerTest, TestShiftRight) {
	displayManager->createNewDisplay();
	
	uint8_t* display[] = {m,a,E};
	displayManager->populateDisplayBuffer(display,3,LEFT_BUFFER);
	//displayManager->toString();
	
	for(int transform = 0; transform < 32; transform++){
		displayManager->transformDisplay(RIGHT);
		//displayManager->toString();	
	}
	//We will only validate the final display..
	int retCmp = 0;
	DisplayMatrix* currentMatrix;
	
	currentMatrix = displayManager->getCurrentDisplayMatrix();
	retCmp = memcmp(m,currentMatrix->getCurrentMatrix(),sizeof(m));
	EXPECT_EQ(0,retCmp);
}

TEST_F(DisplayManagerTest, TestShiftUp) {
	displayManager->createNewDisplay();

	uint8_t* display[] = {a,E,m};
	displayManager->populateDisplayBuffer(display,3,BOTTOM_BUFFER);
	//displayManager->toString();
	
	for(int transform = 0; transform < 32; transform++){
		displayManager->transformDisplay(UP);
		//displayManager->toString();	
	}
	//We will only validate the final display..
	int retCmp = 0;
	DisplayMatrix* currentMatrix;
	
	currentMatrix = displayManager->getCurrentDisplayMatrix();
	retCmp = memcmp(a,currentMatrix->getCurrentMatrix(),sizeof(a));
	EXPECT_EQ(0,retCmp);
}

TEST_F(DisplayManagerTest, TestShiftDown) {
	displayManager->createNewDisplay();

	uint8_t* display[] = {E,m,a};
	displayManager->populateDisplayBuffer(display,3,TOP_BUFFER);
	//displayManager->toString();
	
	for(int transform = 0; transform < 32; transform++){
		displayManager->transformDisplay(DOWN);
		//displayManager->toString();	
	}
	//We will only validate the final display..
	int retCmp = 0;
	DisplayMatrix* currentMatrix;
	
	currentMatrix = displayManager->getCurrentDisplayMatrix();
	retCmp = memcmp(E,currentMatrix->getCurrentMatrix(),sizeof(E));
	EXPECT_EQ(0,retCmp);
}

TEST_F(DisplayManagerTest, TestSetDisplayThenTransform){
	displayManager->createNewDisplay();
	displayManager->setDisplayMatrix(E,sizeof(E));

	displayManager->transformDisplay(DOWN);
	displayManager->transformDisplay(DOWN);
	displayManager->transformDisplay(DOWN);
	
	//Validate that the display is now transformed, using the test data
	int retCmp = 0;
	DisplayMatrix* currentMatrix;
	
	currentMatrix = displayManager->getCurrentDisplayMatrix();
	retCmp = memcmp(E_transform3,currentMatrix->getCurrentMatrix(),sizeof(E_transform3));
	EXPECT_EQ(0,retCmp);
}

