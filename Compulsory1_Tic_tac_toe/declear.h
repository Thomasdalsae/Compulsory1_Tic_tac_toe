#pragma once

#include <iostream>
#include <cstdlib>
#include <conio.h>


void updateBoard(char gameboard[][3]);

//this checks if the location inn the array is taken or not.
bool takenMarker(int, char gameboard[][3]);
//this checks if there is a winning condition on the board.
bool winChecker(char gameBoard[][3]);
//this is the function where the game is.
bool TTT();

//template for the gameboard
char templateBoard[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };


char retry{};


//This is to decide which type of marker should be placed where (O/X)
char currentmarker;

//This takes the input from the player to let the code know where he want to place a mark, this is sent to (currentmarker)
int input{};




