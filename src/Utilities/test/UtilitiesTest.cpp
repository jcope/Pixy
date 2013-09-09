/*****************************************
 EMMA TECHNOLOGIES, L.L.C.
 Copyright (c) 2013.
 All Rights Reserved.
 *****************************************
 Purpose: To demonstrate sample unit test
   and test out the build environment. 
 ****************************************/
#include <gtest/gtest.h>
#include "../Utilities.h"

using namespace std;

class UtilitiesTest : public ::testing::Test {
 protected:
	// Called before the first test in this test case.
  	static void SetUpTestCase() {
		utils = new Utilities();
  	}

  	// Called after the last test in this test case.
  	static void TearDownTestCase() {
    	delete utils;
    	utils = NULL;
  	}

  	// Called prior to each individual test
  	virtual void SetUp() {
		//Make sure the instance variable isn't null
		EXPECT_NE(utils,(void*)NULL);
  	}
  
	// Called after each individual test
	virtual void TearDown() { 
	}

  	// Some expensive resource shared by all tests.
  	static Utilities* utils;
};

Utilities* UtilitiesTest::utils = NULL;

/***************BEGIN TESTS***************/
TEST_F(UtilitiesTest, Setup) {
	int retRandom = 0;
	retRandom = Utilities::randomNumber(125);
	EXPECT_EQ(retRandom,retRandom);
}
TEST_F(UtilitiesTest, ExtractRGBValues) {
	//Example
	uint8_t baseValue = 214;
	uint8_t r,g,b;
	Utilities::extractRGBvalues(baseValue,r,g,b);
	EXPECT_EQ(r,191);
	EXPECT_EQ(g,223);
	EXPECT_EQ(b,0);
}