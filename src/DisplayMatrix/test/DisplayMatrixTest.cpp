/*****************************************
 EMMA TECHNOLOGIES, L.L.C.
 Copyright (c) 2013.
 All Rights Reserved.
 *****************************************
 Purpose: To demonstrate sample unit test
   and test out the build environment. 
 ****************************************/
#include <gtest/gtest.h>
#include "../DisplayMatrix.h"
#include "testData.h"
#include "alphabet.h"
#include "colors.h"

class DisplayMatrixTest : public ::testing::Test {
 protected:
	// Called before the first test in this test case.
  	static void SetUpTestCase() {
		displayMatrix = new DisplayMatrix();
  	}

  	// Called after the last test in this test case.
  	static void TearDownTestCase() {
    	delete displayMatrix;
    	displayMatrix = NULL;
  	}

  	// Called prior to each individual test
  	virtual void SetUp() {
		//Make sure the instance variable isn't null
		EXPECT_NE(displayMatrix,(void*)NULL);
  	}
  
	// Called after each individual test
	virtual void TearDown() { 
		displayMatrix->clearDataStructures();
	}

  	// Some expensive resource shared by all tests.
  	static DisplayMatrix* displayMatrix;
};

DisplayMatrix* DisplayMatrixTest::displayMatrix = NULL;

/***************BEGIN TESTS***************/

TEST_F(DisplayMatrixTest, SettingNewDisplay) {
	bool retVal = false;
	retVal = displayMatrix->setCurrentDisplay(data1_matrix,sizeof(data1_matrix),
											data1_top,sizeof(data1_top),
											data1_right,sizeof(data1_right),
											data1_bottom,sizeof(data1_bottom),
											data1_left,sizeof(data1_left));
	EXPECT_EQ(true,retVal);
	
	//Now get the data from the displayMatrix and make sure it matches what we passed in.
	int retCmp = 0;
	uint8_t* currentData;
	
	//Current Matrix
	currentData = displayMatrix->getCurrentMatrix();
	retCmp = memcmp(data1_matrix,currentData,sizeof(data1_matrix));
	EXPECT_EQ(0,retCmp);
	
	//Top
	currentData = displayMatrix->getTopBuffer();
	retCmp = memcmp(data1_top,currentData,sizeof(data1_top));
	EXPECT_EQ(0,retCmp);
	
	//Right
	currentData = displayMatrix->getRightBuffer();
	retCmp = memcmp(data1_right,currentData,sizeof(data1_right));
	EXPECT_EQ(0,retCmp);
	
	//Bottom
	currentData = displayMatrix->getBottomBuffer();
	retCmp = memcmp(data1_bottom,currentData,sizeof(data1_bottom));
	EXPECT_EQ(0,retCmp);
	
	//Left
	currentData = displayMatrix->getLeftBuffer();
	retCmp = memcmp(data1_left,currentData,sizeof(data1_left));
	EXPECT_EQ(0,retCmp);
}

TEST_F(DisplayMatrixTest, Transform_UP_Offset1) {
	bool retVal = false;
	retVal = displayMatrix->setCurrentDisplay(data1_matrix,sizeof(data1_matrix),
											data1_top,sizeof(data1_top),
											data1_right,sizeof(data1_right),
											data1_bottom,sizeof(data1_bottom),
											data1_left,sizeof(data1_left));
	EXPECT_EQ(true,retVal);
	
	//Apply the Transform
	retVal = displayMatrix->transformMatrix(UP);
	EXPECT_EQ(true,retVal);
	
	//Now get the data from the displayMatrix and make sure it matches what we passed in.
	int retCmp = 0;
	uint8_t* currentData;
	
	//Current Matrix
	currentData = displayMatrix->getCurrentMatrix();
	retCmp = memcmp(data1_matrix_3,currentData,sizeof(data1_matrix_3));
	EXPECT_EQ(0,retCmp);
	
	//Top
	currentData = displayMatrix->getTopBuffer();
	retCmp = memcmp(data1_top_3,currentData,sizeof(data1_top_3));
	EXPECT_EQ(0,retCmp);
	
	//Right
	currentData = displayMatrix->getRightBuffer();
	retCmp = memcmp(data1_right_3,currentData,sizeof(data1_right_3));
	EXPECT_EQ(0,retCmp);
	
	//Bottom
	currentData = displayMatrix->getBottomBuffer();
	retCmp = memcmp(data1_bottom_3,currentData,sizeof(data1_bottom_3));
	EXPECT_EQ(0,retCmp);
	
	//Left
	currentData = displayMatrix->getLeftBuffer();
	retCmp = memcmp(data1_left_3,currentData,sizeof(data1_left_3));
	EXPECT_EQ(0,retCmp);
}
	
TEST_F(DisplayMatrixTest, Transform_RIGHT_Offset1) {
	bool retVal = false;
	retVal = displayMatrix->setCurrentDisplay(data1_matrix,sizeof(data1_matrix),
											data1_top,sizeof(data1_top),
											data1_right,sizeof(data1_right),
											data1_bottom,sizeof(data1_bottom),
											data1_left,sizeof(data1_left));
	EXPECT_EQ(true,retVal);
	
	//Apply the Transform
	retVal = displayMatrix->transformMatrix(RIGHT);
	EXPECT_EQ(true,retVal);
	
	//Now get the data from the displayMatrix and make sure it matches what we passed in.
	int retCmp = 0;
	uint8_t* currentData;
	
	//Current Matrix
	currentData = displayMatrix->getCurrentMatrix();
	retCmp = memcmp(data1_matrix_2,currentData,sizeof(data1_matrix_2));
	EXPECT_EQ(0,retCmp);
	
	//Top
	currentData = displayMatrix->getTopBuffer();
	retCmp = memcmp(data1_top_2,currentData,sizeof(data1_top_2));
	EXPECT_EQ(0,retCmp);
	
	//Right
	currentData = displayMatrix->getRightBuffer();
	retCmp = memcmp(data1_right_2,currentData,sizeof(data1_right_2));
	EXPECT_EQ(0,retCmp);
	
	//Bottom
	currentData = displayMatrix->getBottomBuffer();
	retCmp = memcmp(data1_bottom_2,currentData,sizeof(data1_bottom_2));
	EXPECT_EQ(0,retCmp);
	
	//Left
	currentData = displayMatrix->getLeftBuffer();
	retCmp = memcmp(data1_left_2,currentData,sizeof(data1_left_2));
	EXPECT_EQ(0,retCmp);
}

TEST_F(DisplayMatrixTest, Transform_LEFT_Offset1) {
	bool retVal = false;
	retVal = displayMatrix->setCurrentDisplay(data1_matrix,sizeof(data1_matrix),
											data1_top,sizeof(data1_top),
											data1_right,sizeof(data1_right),
											data1_bottom,sizeof(data1_bottom),
											data1_left,sizeof(data1_left));
	EXPECT_EQ(true,retVal);

	//Apply the Transform
	retVal = displayMatrix->transformMatrix(LEFT);
	EXPECT_EQ(true,retVal);
	
	//Now get the data from the displayMatrix and make sure it matches what we passed in.
	int retCmp = 0;
	uint8_t* currentData;
	
	//Current Matrix
	currentData = displayMatrix->getCurrentMatrix();
	retCmp = memcmp(data1_matrix_1,currentData,sizeof(data1_matrix_1));
	EXPECT_EQ(0,retCmp);
	
	//Top
	currentData = displayMatrix->getTopBuffer();
	retCmp = memcmp(data1_top_1,currentData,sizeof(data1_top_1));
	EXPECT_EQ(0,retCmp);
	
	//Right
	currentData = displayMatrix->getRightBuffer();
	retCmp = memcmp(data1_right_1,currentData,sizeof(data1_right_1));
	EXPECT_EQ(0,retCmp);
	
	//Bottom
	currentData = displayMatrix->getBottomBuffer();
	retCmp = memcmp(data1_bottom_1,currentData,sizeof(data1_bottom_1));
	EXPECT_EQ(0,retCmp);
	
	//Left
	currentData = displayMatrix->getLeftBuffer();
	retCmp = memcmp(data1_left_1,currentData,sizeof(data1_left_1));
	EXPECT_EQ(0,retCmp);
}

TEST_F(DisplayMatrixTest, Transform_DOWN_Offset1) {
	bool retVal = false;
	retVal = displayMatrix->setCurrentDisplay(data1_matrix,sizeof(data1_matrix),
											data1_top,sizeof(data1_top),
											data1_right,sizeof(data1_right),
											data1_bottom,sizeof(data1_bottom),
											data1_left,sizeof(data1_left));
	EXPECT_EQ(true,retVal);

	//Apply the Transform
	retVal = displayMatrix->transformMatrix(DOWN);
	EXPECT_EQ(true,retVal);

	//Now get the data from the displayMatrix and make sure it matches what we passed in.
	int retCmp = 0;
	uint8_t* currentData;
	
	//Current Matrix
	currentData = displayMatrix->getCurrentMatrix();
	retCmp = memcmp(data1_matrix_4,currentData,sizeof(data1_matrix_4));
	EXPECT_EQ(0,retCmp);
	
	//Top
	currentData = displayMatrix->getTopBuffer();
	retCmp = memcmp(data1_top_4,currentData,sizeof(data1_top_4));
	EXPECT_EQ(0,retCmp);
	
	//Right
	currentData = displayMatrix->getRightBuffer();
	retCmp = memcmp(data1_right_4,currentData,sizeof(data1_right_4));
	EXPECT_EQ(0,retCmp);
	
	//Bottom
	currentData = displayMatrix->getBottomBuffer();
	retCmp = memcmp(data1_bottom_4,currentData,sizeof(data1_bottom_4));
	EXPECT_EQ(0,retCmp);
	
	//Left
	currentData = displayMatrix->getLeftBuffer();
	retCmp = memcmp(data1_left_4,currentData,sizeof(data1_left_4));
	EXPECT_EQ(0,retCmp);
}

TEST_F(DisplayMatrixTest, CombineDisplays){
	bool retVal = false;
	retVal = displayMatrix->setCurrentMatrix(display1,sizeof(display1));
	EXPECT_EQ(true,retVal);
	
	retVal = displayMatrix->combineMatrix(display2,sizeof(display2));
	EXPECT_EQ(true,retVal);
	
	int retCmp = 0;
	uint8_t* currentData;
	
	currentData = displayMatrix->getCurrentMatrix();
	retCmp = memcmp(display1_2Combo,currentData,sizeof(display1_2Combo));
	EXPECT_EQ(0,retCmp);
}

TEST_F(DisplayMatrixTest, multipleTransformCombines){
	DisplayMatrix displayTrans;
	DisplayMatrix displayPerm;
	DisplayMatrix displayActual;
	uint8_t m1[8] = {0,0,0,3,0,0,0,0};
	uint8_t m2[8] = {0,0,0,0,48,0,0,0};
	uint8_t m3[8] = {0,0,0,0,3,0,0,0};
	
	//Make first move
	displayTrans.setTopBuffer(m1,8);
	//Do this 8 times
	for(int movesInRow=8;movesInRow>0;movesInRow--){
		displayTrans.transformMatrix(DOWN);
		
		displayActual.clearDataStructures();//Clear the displayActual
		displayActual.combineMatrix(displayTrans.getCurrentMatrix(),64);
		displayActual.combineMatrix(displayPerm.getCurrentMatrix(),64);
		
		//displayActual.toString();
	}
	//Set the perm to the actual, left over
	displayPerm.setCurrentMatrix(displayActual.getCurrentMatrix(),64);
	//Clear the displayTrans
	displayTrans.clearDataStructures();
	
	//Make second move
	displayTrans.setTopBuffer(m2,8);
	//Do this 8 times
	for(int movesInRow=8;movesInRow>0;movesInRow--){
		displayTrans.transformMatrix(DOWN);
		
		displayActual.clearDataStructures();//Clear the displayActual
		displayActual.combineMatrix(displayTrans.getCurrentMatrix(),64);
		displayActual.combineMatrix(displayPerm.getCurrentMatrix(),64);
		
		//displayActual.toString();
	}
	//Set the perm to the actual, left over
	displayPerm.setCurrentMatrix(displayActual.getCurrentMatrix(),64);
	//Clear the displayTrans
	displayTrans.clearDataStructures();
	
	
	//Make third move
	displayTrans.setTopBuffer(m3,8);
	//Do this 7 times
	for(int movesInRow=7;movesInRow>0;movesInRow--){
		displayTrans.transformMatrix(DOWN);
		
		displayActual.clearDataStructures();//Clear the displayActual
		displayActual.combineMatrix(displayTrans.getCurrentMatrix(),64);
		displayActual.combineMatrix(displayPerm.getCurrentMatrix(),64);
		
		//displayActual.toString();
	}
	//Set the perm to the actual, left over
	displayPerm.setCurrentMatrix(displayActual.getCurrentMatrix(),64);
	//Clear the displayTrans
	displayTrans.clearDataStructures();
	
	
	//Validate the final display
	//displayPerm.toString();
	int retCmp = 0;
	uint8_t* currentData;
	
	currentData = displayPerm.getCurrentMatrix();
	retCmp = memcmp(displayMultCombTrans,currentData,sizeof(displayMultCombTrans));
	EXPECT_EQ(0,retCmp);
}

TEST_F(DisplayMatrixTest, randomFillRow){
	//This will test that we can call the function without crashing
	//To see the randomness, you must enable the displaying of toString
	uint8_t randomRow[8];
	
	bool retVal = displayMatrix->randomFillRow(randomRow, sizeof(randomRow), GREEN);
	EXPECT_EQ(true,retVal);
	
	displayMatrix->setTopBuffer(randomRow, sizeof(randomRow));
	//displayMatrix->toString();
}

TEST_F(DisplayMatrixTest, randomFillRowRGB){
	//This will test that we can call the function without crashing
	//To see the randomness, you must enable the displaying of toString
	uint8_t randomRow[8];
	
	bool retVal = displayMatrix->randomFillRowRGB(randomRow, sizeof(randomRow));
	EXPECT_EQ(true,retVal);
	
	displayMatrix->setTopBuffer(randomRow, sizeof(randomRow));
	//displayMatrix->toString();
}

TEST_F(DisplayMatrixTest, transformColumnDown){
	//Initialize with known matrix
	bool retVal = false;
	retVal = displayMatrix->setCurrentMatrix(shiftColumnInit,sizeof(shiftColumnInit));
	EXPECT_EQ(true,retVal);
	
	//Transform a single column down
	displayMatrix->transformColumnDown(1);
	
	//Compare to the given
	int retCmp = 0;
	uint8_t* currentData;
	
	currentData = displayMatrix->getCurrentMatrix();
	retCmp = memcmp(shiftColumnExp,currentData,sizeof(shiftColumnExp));
	EXPECT_EQ(0,retCmp);
}
