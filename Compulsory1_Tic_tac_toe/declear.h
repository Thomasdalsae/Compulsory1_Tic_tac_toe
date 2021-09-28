#pragma once

#include <iostream>
#include <cstdlib>
#include <conio.h>
void updateBoard(char gameboard[][3]);

//this checks if the location inn the array is taken or not.
bool takenMarker(int, char gameboard[][3]);
bool winChecker(char gameBoard[][3]);
bool TTT();


char templateBoard[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };



//This is to decide which type of marker should be placed where (O/X)
char currentmarker;

//This is the input from thep player that decide which number on the gameboard he picked
int input{};




