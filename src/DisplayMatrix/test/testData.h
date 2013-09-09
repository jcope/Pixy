/*****************************************
 EMMA TECHNOLOGIES, L.L.C.
 Copyright (c) 2013.
 All Rights Reserved.
 *****************************************
 Purpose: We define test matrixes to use for
	validation
 ****************************************/
#ifndef TESTDATA_H
#define TESTDATA_H

/****Refer to notebook for diagrams****/

//Empty Set
uint8_t empty_top[8] = 		{0,0,0,0,0,0,0,0};
uint8_t empty_right[8] =	{0,0,0,0,0,0,0,0};
uint8_t empty_bottom[8] =	{0,0,0,0,0,0,0,0};
uint8_t empty_left[8] = 	{0,0,0,0,0,0,0,0};
uint8_t empty_matrix[64] = {
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0};

/******Sample Test Data 1********/
//Initial
uint8_t data1_top[8] = 		{0,1,0,1,1,0,1,0};
uint8_t data1_right[8] =	{1,1,1,0,0,1,0,1};
uint8_t data1_bottom[8] =	{0,0,1,0,1,0,1,1};
uint8_t data1_left[8] = 	{0,1,1,0,0,1,0,1};
uint8_t data1_matrix[64] = {
1,0,0,0,0,1,0,0,\
1,0,1,0,1,1,1,0,\
0,1,1,1,0,1,0,1,\
1,0,1,1,1,0,0,0,\
0,1,0,1,0,0,1,0,\
1,0,1,0,1,0,0,0,\
1,0,1,1,0,1,0,1,\
0,1,0,0,1,0,1,1};
//_1 Shift left, offset 1
uint8_t data1_top_1[8] = 	{1,0,1,1,0,1,0,0};
uint8_t data1_right_1[8] =	{0,0,0,0,0,0,0,0};
uint8_t data1_bottom_1[8] =	{0,1,0,1,0,1,1,0};
uint8_t data1_left_1[8] = 	{1,1,0,1,0,1,1,0};
uint8_t data1_matrix_1[64] = {
0,0,0,0,1,0,0,1,\
0,1,0,1,1,1,0,1,\
1,1,1,0,1,0,1,1,\
0,1,1,1,0,0,0,0,\
1,0,1,0,0,1,0,0,\
0,1,0,1,0,0,0,1,\
0,1,1,0,1,0,1,0,\
1,0,0,1,0,1,1,1};
//_2 Shift right, offset 1
uint8_t data1_top_2[8] = 	{0,0,1,0,1,1,0,1};
uint8_t data1_right_2[8] =	{0,0,1,0,0,0,1,1};
uint8_t data1_bottom_2[8] =	{0,0,0,1,0,1,0,1};
uint8_t data1_left_2[8] = 	{0,0,0,0,0,0,0,0};
uint8_t data1_matrix_2[64] = {
0,1,0,0,0,0,1,0,\
1,1,0,1,0,1,1,1,\
1,0,1,1,1,0,1,0,\
0,1,0,1,1,1,0,0,\
0,0,1,0,1,0,0,1,\
1,1,0,1,0,1,0,0,\
0,1,0,1,1,0,1,0,\
1,0,1,0,0,1,0,1};
//_3 Shift up, offset 1
uint8_t data1_top_3[8] = 	{1,0,0,0,0,1,0,0};
uint8_t data1_right_3[8] =	{1,1,0,0,1,0,1,0};
uint8_t data1_bottom_3[8] =	{0,0,0,0,0,0,0,0};
uint8_t data1_left_3[8] = 	{1,1,0,0,1,0,1,0};
uint8_t data1_matrix_3[64] = {
1,0,1,0,1,1,1,0,\
0,1,1,1,0,1,0,1,\
1,0,1,1,1,0,0,0,\
0,1,0,1,0,0,1,0,\
1,0,1,0,1,0,0,0,\
1,0,1,1,0,1,0,1,\
0,1,0,0,1,0,1,1,
0,0,1,0,1,0,1,1};
//_4 Shift down, offset 1
uint8_t data1_top_4[8] = 	{0,0,0,0,0,0,0,0};
uint8_t data1_right_4[8] =	{0,1,1,1,0,0,1,0};
uint8_t data1_bottom_4[8] =	{0,1,0,0,1,0,1,1};
uint8_t data1_left_4[8] = 	{0,0,1,1,0,0,1,0};
uint8_t data1_matrix_4[64] = {
0,1,0,1,1,0,1,0,\
1,0,0,0,0,1,0,0,\
1,0,1,0,1,1,1,0,\
0,1,1,1,0,1,0,1,\
1,0,1,1,1,0,0,0,\
0,1,0,1,0,0,1,0,\
1,0,1,0,1,0,0,0,\
1,0,1,1,0,1,0,1};
//Offset Data Points
//_5 Shift Down, offset 3
uint8_t data1_top_5[8] = 	{0,0,0,0,0,0,0,0};
uint8_t data1_right_5[8] =	{0,0,0,1,1,1,0,0};
uint8_t data1_bottom_5[8] =	{1,0,1,0,1,0,0,0};
uint8_t data1_left_5[8] = 	{0,0,0,0,1,1,0,0};
uint8_t data1_matrix_5[64] = {
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,1,0,1,1,0,1,0,\
1,0,0,0,0,1,0,0,\
1,0,1,0,1,1,1,0,\
0,1,1,1,0,1,0,1,\
1,0,1,1,1,0,0,0,\
0,1,0,1,0,0,1,0};
//_6 Shift Right, offset 4
uint8_t data1_top_6[8] = 	{0,0,0,0,0,1,0,1};
uint8_t data1_right_6[8] =	{0,1,0,1,0,1,0,1};
uint8_t data1_bottom_6[8] =	{0,0,0,0,0,0,1,0};
uint8_t data1_left_6[8] = 	{0,0,0,0,0,0,0,0};
uint8_t data1_matrix_6[64] = {
0,0,0,0,1,0,0,0,\
0,0,0,1,1,0,1,0,\
0,0,0,1,0,1,1,1,\
0,0,0,0,1,0,1,1,\
0,0,0,0,0,1,0,1,\
0,0,0,1,1,0,1,0,\
0,0,0,0,1,0,1,1,\
0,0,0,1,0,1,0,0};
//_7 Shift Up, offset 6
uint8_t data1_top_7[8] = 	{1,0,1,0,1,0,0,0};
uint8_t data1_right_7[8] =	{0,1,0,0,0,0,0,0};
uint8_t data1_bottom_7[8] =	{0,0,0,0,0,0,0,0};
uint8_t data1_left_7[8] = 	{0,1,0,0,0,0,0,0};
uint8_t data1_matrix_7[64] = {
1,0,1,1,0,1,0,1,\
0,1,0,0,1,0,1,1,\
0,0,1,0,1,0,1,1,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0};
//_8 Shift Left, offset 7
uint8_t data1_top_8[8] = 	{0,0,0,0,0,0,0,0};
uint8_t data1_right_8[8] =	{0,0,0,0,0,0,0,0};
uint8_t data1_bottom_8[8] =	{1,0,0,0,0,0,0,0};
uint8_t data1_left_8[8] = 	{0,1,0,0,1,0,0,1};
uint8_t data1_matrix_8[64] = {
0,1,0,0,0,0,0,0,\
0,1,0,0,0,0,0,0,\
1,1,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,1,0,0,0,0,0,0,\
1,0,0,0,0,0,0,0,\
1,1,0,0,0,0,0,0};
//_9 Shift Right, offset 8
uint8_t data1_top_9[8] = 	{0,0,0,0,0,0,0,0};
uint8_t data1_right_9[8] =	{1,1,0,1,0,1,1,0};
uint8_t data1_bottom_9[8] =	{0,0,0,0,0,0,0,0};
uint8_t data1_left_9[8] = 	{0,0,0,0,0,0,0,0};
uint8_t data1_matrix_9[64] = {
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,1,\
0,0,0,0,0,0,0,1,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,1,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,1};
//_10 Shift Up, offset 9
uint8_t data1_top_10[8] = 		{0,0,1,0,1,0,1,1};
uint8_t data1_right_10[8] =		{0,0,0,0,0,0,0,0};
uint8_t data1_bottom_10[8] =	{0,0,0,0,0,0,0,0};
uint8_t data1_left_10[8] = 		{0,0,0,0,0,0,0,0};
uint8_t data1_matrix_10[64] = {
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0};

//Combine Tests
uint8_t display1[64] = {
0,0,3,0,0,0,0,0,\
0,0,3,0,0,0,0,0,\
0,0,3,0,0,0,0,0,\
0,0,3,0,0,0,0,0,\
0,0,3,0,0,0,0,0,\
0,0,3,0,0,0,0,0,\
0,0,3,0,0,0,0,0,\
0,0,3,0,0,0,0,0};

uint8_t display2[64] = {
0,0,0,0,0,48,0,0,\
0,0,0,0,0,48,0,0,\
0,0,0,0,0,48,0,0,\
0,0,0,0,0,48,0,0,\
0,0,0,0,0,48,0,0,\
0,0,0,0,0,48,0,0,\
0,0,0,0,0,48,0,0,\
0,0,0,0,0,48,0,0};

uint8_t display1_2Combo[64] = {
0,0,3,0,0,48,0,0,\
0,0,3,0,0,48,0,0,\
0,0,3,0,0,48,0,0,\
0,0,3,0,0,48,0,0,\
0,0,3,0,0,48,0,0,\
0,0,3,0,0,48,0,0,\
0,0,3,0,0,48,0,0,\
0,0,3,0,0,48,0,0};

//Multiple Combines/Transforms Tests
uint8_t displayMultCombTrans[64] = {
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,3,0,0,0,\
0,0,0,3,48,0,0,0};

uint8_t shiftColumnInit[64] = {
0,0,1,1,1,1,0,0,\
0,1,0,0,0,0,0,0,\
0,1,0,0,0,0,0,0,\
0,1,0,0,0,0,0,0,\
0,1,1,1,0,0,0,0,\
0,1,0,0,0,0,0,0,\
0,1,0,0,0,0,0,0,\
0,0,1,1,1,1,0,0};

uint8_t shiftColumnExp[64] = {
0,0,1,1,1,1,0,0,\
0,0,0,0,0,0,0,0,\
0,1,0,0,0,0,0,0,\
0,1,0,0,0,0,0,0,\
0,1,1,1,0,0,0,0,\
0,1,0,0,0,0,0,0,\
0,1,0,0,0,0,0,0,\
0,1,1,1,1,1,0,0};


#endif
