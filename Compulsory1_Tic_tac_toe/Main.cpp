#include <iostream>
#include <cstdlib>
#include <conio.h>
void gameLayout();
bool takenMarker(int);

char gameBoard[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
char currentmarker;
bool playerOne = true;
int input{};



int main() {
	//std::cout << "********  welcome to tic tac toe! ********" << std::endl;
	gameLayout();
	std::cout << std::endl;




	int turn = (1);
	bool gameWon = false;
	int calculateWinner();


	while (gameWon == false)
	{
		std::cout << "Turn:" << turn << std::endl;
		if (turn % 2 != 0) //every even is O)
		{
			std::cout << "Player 1 -choose a number from 1 to 9 ";

			currentmarker = 'O';

		}
		else
		{
			std::cout << "Player 2 -choose a number from 1 to 9 ";
			currentmarker = 'X';
		}
		std::cin >> input;
		++turn; // Adds one turn to the game
		
		gameLayout();

		if (!takenMarker(input)) {

			(std::cout << "This position on the board is already taken.. please try again!"<<std::endl);
			turn--;


		}
		
		
		
			
	
		}
	
		
		return 0;
}





void gameLayout() {

	std::cout << "           " << gameBoard[0][0] << "  |  " << gameBoard[0][1] << "  |  " << gameBoard[0][2] << std::endl;
	std::cout << "          -----------------" << std::endl;
	std::cout << "           " << gameBoard[1][0] << "  |  " << gameBoard[1][1] << "  |  " << gameBoard[1][2] << std::endl;
	std::cout << "          -----------------" << std::endl;
	std::cout << "           " << gameBoard[2][0] << "  |  " << gameBoard[2][1] << "  |  " << gameBoard[2][2] << std::endl;


}



bool takenMarker(int place) {

	int row = place / 3; {}
	int col;

	if (place % 3 == 0)
	{
		row = row - 1;
		col = 2;
	}
	else col = (place % 3) - 1;

	if (gameBoard[row][col] != 'X' && gameBoard[row][col] != 'O')
	{
		gameBoard[row][col] = currentmarker;
		return true;
	}
	else return false;
}

