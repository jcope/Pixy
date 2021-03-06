/*****************************************
 EMMA TECHNOLOGIES, L.L.C.
 Copyright (c) 2013.
 All Rights Reserved.
 *****************************************
 Purpose: We define all constant symbol matrixes.
 ****************************************/
#ifndef SYMBOLS_H
#define SYMBOLS_H

/***************SYMBOLS******************/
//Space [ ]
uint8_t space[64] = {
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0};
//Excite [!]
uint8_t excite[64] = {
0,0,0,0,1,0,0,0,\
0,0,0,1,1,1,0,0,\
0,0,0,1,1,1,0,0,\
0,0,0,1,1,1,0,0,\
0,0,0,0,1,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,1,0,0,0,\
0,0,0,1,1,1,0,0};
//Double Quotes ["]
uint8_t quote2_left[64] = {
0,0,1,1,0,1,1,0,\
0,0,1,1,0,1,1,0,\
0,0,0,1,0,0,1,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0};
//Double Quotes ["]
uint8_t quote2_right[64] = {
0,0,1,1,0,1,1,0,\
0,0,1,1,0,1,1,0,\
0,0,1,0,0,1,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0};
//Pound [#]
uint8_t pound[64] = {
0,0,1,1,0,1,1,0,\
0,0,1,1,0,1,1,0,\
1,1,1,1,1,1,1,1,\
0,0,1,1,0,1,1,0,\
0,0,1,1,0,1,1,0,\
1,1,1,1,1,1,1,1,\
0,0,1,1,0,1,1,0,\
0,0,1,1,0,1,1,0};
//Dollar [$]
uint8_t dollar[64] = {
0,0,0,1,0,0,0,0,\
0,0,1,1,1,1,0,0,\
0,1,0,1,0,0,1,0,\
1,1,0,1,0,0,0,0,\
0,1,1,1,1,0,0,0,\
0,0,0,1,0,1,0,0,\
0,1,0,1,0,1,1,0,\
0,0,1,1,1,1,0,0};
//Percent [%]
uint8_t percent[64] = {
0,0,1,0,0,0,0,0,\
0,1,0,1,0,0,1,0,\
0,0,1,0,0,1,0,0,\
0,0,0,0,1,0,0,0,\
0,0,0,1,0,0,0,0,\
0,0,1,0,0,1,0,0,\
0,1,0,0,1,0,1,0,\
0,0,0,0,0,1,0,0}
//Amper [&]
uint8_t amper[64] = {
0,0,0,1,0,0,0,0,\
0,0,1,0,1,0,0,0,\
0,0,1,0,1,0,0,0,\
0,0,0,1,0,0,0,1,\
0,0,1,0,1,0,0,1,\
0,1,0,0,0,1,1,0,\
0,1,0,0,0,1,1,0,\
0,0,1,1,1,0,0,1};
//quote [']
uint8_t quote_left[64] = {
0,0,0,1,0,0,0,0,\
0,0,0,1,0,0,0,0,\
0,0,0,1,0,0,0,0,\
0,0,0,0,1,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0};
//quote [']
uint8_t quote_right[64] = {
0,0,0,0,1,0,0,0,\
0,0,0,0,1,0,0,0,\
0,0,0,0,1,0,0,0,\
0,0,0,1,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0
//Elipse [(]
uint8_t elipse_left[64] = {
0,0,0,0,1,1,0,0,\
0,0,0,1,0,0,0,0,\
0,0,1,0,0,0,0,0,\
0,1,0,0,0,0,0,0,\
0,1,0,0,0,0,0,0,\
0,0,1,0,0,0,0,0,\
0,0,0,1,0,0,0,0,\
0,0,0,0,1,1,0,0};
//Elipse [)]
uint8_t elipse_right[64] = {
0,0,1,1,0,0,0,0,\
0,0,0,0,1,0,0,0,\
0,0,0,0,0,1,0,0,\
0,0,0,0,0,0,1,0,\
0,0,0,0,0,0,1,0,\
0,0,0,0,0,1,0,0,\
0,0,0,0,1,0,0,0,\
0,0,1,1,0,0,0,0};
//Star [*]
uint8_t star[64] = {
0,0,0,0,1,0,0,0,\
0,0,0,0,1,0,0,0,\
0,0,0,0,1,0,0,0,\
0,1,1,1,1,1,1,0,\
0,0,0,0,1,0,0,0,\
0,0,0,1,0,1,0,0,\
0,0,1,0,0,0,1,0,\
0,0,0,0,0,0,0,0};
//Plus [+]
uint8_t plus[64] = {
0,0,0,0,0,0,0,0,\
0,0,0,0,1,0,0,0,\
0,0,0,0,1,0,0,0,\
0,0,0,0,1,0,0,0,\
0,0,1,1,1,1,1,0,\
0,0,0,0,1,0,0,0,\
0,0,0,0,1,0,0,0,\
0,0,0,0,1,0,0,0};
//Minus [-]
uint8_t minus[64] = {
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,1,1,1,1,1,1,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0};
//Comma [,]
uint8_t comma[64] = {
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,1,1,0,0,0,0,\
0,0,1,1,0,0,0,0,\
0,1,1,0,0,0,0,0};
//Period [.]
uint8_t period[64] = {
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,1,0,0,0,0,\
0,0,0,1,1,0,0,0};
//Slash [/]
uint8_t space[64] = {
0,0,0,0,0,0,0,1,\
0,0,0,0,0,0,1,0,\
0,0,0,0,0,1,0,0,\
0,0,0,0,1,0,0,0,\
0,0,0,1,0,0,0,0,\
0,0,1,0,0,0,0,0,\
0,1,0,0,0,0,0,0,\
1,0,0,0,0,0,0,0};
//Colon [:]
uint8_t colon[64] = {
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,1,1,0,0,0,0,\
0,0,1,1,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,1,1,0,0,0,0,\
0,0,1,1,0,0,0,0,\
0,0,0,0,0,0,0,0};
//Semi Colon[;]
uint8_t semi_colon[64] = {
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,1,1,0,0,0,0,\
0,0,1,1,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,1,1,0,0,0,0,\
0,0,1,1,0,0,0,0,\
0,1,1,0,0,0,0,0};
//Less Than[<]
uint8_t lessthan[64] = {
0,0,0,0,0,0,0,0,\
0,0,0,0,1,1,0,0,\
0,0,0,1,1,0,0,0,\
0,0,1,1,0,0,0,0,\
0,1,1,0,0,0,0,0,\
0,0,1,1,0,0,0,0,\
0,0,0,1,1,0,0,0,\
0,0,0,0,1,1,0,0};
//Greater Than[<]
uint8_t greaterthan[64] = {
0,0,0,0,0,0,0,0,\
0,0,1,1,0,0,0,0,\
0,0,0,1,1,0,0,0,\
0,0,0,0,1,1,0,0,\
0,0,0,0,0,1,1,0,\
0,0,0,0,1,1,0,0,\
0,0,0,1,1,0,0,0,\
0,0,1,1,0,0,0,0};
//Equals [=]
uint8_t equals[64] = {
0,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,\
0,1,1,1,1,1,1,0,\
0,1,1,1,1,1,1,0,\
0,0,0,0,0,0,0,0,\
0,1,1,1,1,1,1,0,\
0,1,1,1,1,1,1,0,\
0,0,0,0,0,0,0,0};
//Question Mark [?]
uint8_t question[64] = {
0,0,1,1,1,1,0,0,\
0,1,1,0,0,1,1,0,\
0,0,0,0,0,1,1,0,\
0,0,0,0,1,1,0,0,\
0,0,0,1,1,0,0,0,\
0,0,0,1,1,0,0,0,\
0,0,0,0,0,0,0,0,\
0,0,0,1,1,0,0,0};
//At [@]
uint8_t at[64] = {
0,0,0,1,1,1,0,0,\
0,0,1,0,0,0,1,0,\
0,1,0,1,1,0,0,1,\
0,1,0,1,0,1,0,1,\
0,1,0,1,0,1,0,1,\
0,1,0,1,1,1,1,0,\
0,0,1,0,0,0,0,0,\
0,0,0,1,1,1,1,0};
#endif
