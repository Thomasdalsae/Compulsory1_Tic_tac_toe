#include <iostream>
#include <cstdlib>
#include <conio.h>
void gameLayout(char gameboard[][3]);
bool TTT();

bool takenMarker(int, char gameboard[][3]);
bool checker(char gameBoard[][3]);
char templateBoard[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };




char gameBoard[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
char currentmarker;

int input{};



int main() {
	while (true)
	{
		if (TTT() == false)
		{
			break;
		}

	}



	return 0;
}


bool TTT() {

	//std::cout << "********  welcome to tic tac toe! ********" << std::endl;

	char gameboard[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) {

			gameboard[i][j] = templateBoard[i][j];
		}


	}
	gameLayout(gameboard);






	int turn = (1);
	bool gameWon = false;
	int calculateWinner();
	char retry{};


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
		++turn; // Adds one turn to the game


		while (true) {

			std::cin >> input;
			if (std::cin.fail() or (input < 1 || input > 9))
			{
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				std::cout << "Try another input";


			}
			else
			{
				break;
			}


		}

		if (!takenMarker(input, gameboard)) {
			(std::cout << "This position on the board is already taken.. please try again!" << std::endl);
			turn--;
		}

		if ( checker(gameboard) )
		{
			gameLayout(gameboard);
			std::cout << "Win!" << std::endl;
			return false;
		}


		if (turn == 9) {

			std::cout << "It's a draw! do you want to try again ?" << std::endl;

			std::cin >> retry;



			switch (toupper(retry))
			{
			case 'Y':
				system("cls");

				return true;

				break;
			case 'N':
				return false;

				break;
			default:
				return false;
				break;
			}

		}
		system("cls");
		gameLayout(gameboard);


	}


}

bool checker(char gameBoard[][3])
{

	for (size_t i = 0; i < sizeof(gameBoard[0]) / sizeof(gameBoard[0][0]); i++)
	{
		if (gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][0] == gameBoard[i][2])
		{
			return true;
		}
	}
	for (size_t j = 0; j < sizeof(gameBoard[0]) / sizeof(gameBoard[0][0]); j++)
	{
		if (gameBoard[0][j] == gameBoard[1][j] && gameBoard[0][j] == gameBoard[2][j])
		{
			return true;
		}
	}
	if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[0][0] == gameBoard[2][2])
	{
		return true;
	}
	if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[0][2] == gameBoard[2][0])
	{
		return true;
	}
	

	

	return false;
}
//CALLING INN PARAMETERS,makes it easier for the program to understand what going to happen, (headsup).
//calling gameboard since it�s local to ttt
void gameLayout(char gameboard[][3]) {

	std::cout << "           " << gameboard[0][0] << "  |  " << gameboard[0][1] << "  |  " << gameboard[0][2] << std::endl;
	std::cout << "          -----------------" << std::endl;
	std::cout << "           " << gameboard[1][0] << "  |  " << gameboard[1][1] << "  |  " << gameboard[1][2] << std::endl;
	std::cout << "          -----------------" << std::endl;
	std::cout << "           " << gameboard[2][0] << "  |  " << gameboard[2][1] << "  |  " << gameboard[2][2] << std::endl;

	std::cout << std::endl;
}



bool takenMarker(int place, char gameboard[][3]) {

	int row = place / 3; {}
	int col;

	if (place % 3 == 0)
	{
		row = row - 1;
		col = 2;
	}
	else col = (place % 3) - 1;

	if (gameboard[row][col] != 'X' && gameboard[row][col] != 'O')
	{
		gameboard[row][col] = currentmarker;
		return true;
	}
	else return false;
}

