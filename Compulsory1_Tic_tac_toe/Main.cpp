#include "declear.h"



int main() {
	
	//This loop is to keep the game running.
	while (true)
	{
		TTT();
		
			std::cout << "Do you want to play again? y/n";
			std::cin >> retry;
			//switch case inputs to keep playing or exit.
			switch (toupper(retry))
			{
			case 'Y':
				
				system("cls");

				break;
			case 'N':
				system("cls");
				exit(0);

				break;
			default:
				return false;
				break;
			}
	}

	return 0;
}

//TickTackToe.
bool TTT() {
	std::cout << "******  welcome to tic tac toe! ******" << std::endl << std::endl;
	//declare my array and makes the gameboard.
	char gameboard[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) {
			//makes the array slots ready.
			gameboard[i][j] = templateBoard[i][j];
		}
	}
	updateBoard(gameboard);

	int turn{1};
	bool gameWon{false};
	//Players input after the game ends, it's for the switch case activation.
	
	//When the game is not won, keep running.
	while (!gameWon)
	{
		std::cout << "Turn:" << turn << std::endl;
		if (turn % 2 != 0) //every even is O)
		{
			std::cout << "Player 1" << std::endl << "choose a number from 1 to 9  :";

			currentmarker = 'O';
		}
		else
		{   //every odd is X
			std::cout << "Player 2" << std::endl << "choose a number from 1 to 9  :";
			currentmarker = 'X';
		}
		++turn; // Adds one turn to the game

		while (true) {

			std::cin >> input;

			//This function returns true when an input failure occurs, my input is a int. if the input is less than one or bigger than 9 retry.
			if (std::cin.fail() || (input < 1 || input > 9))
			{
				//cin.clear removes the error flag on my (cin >> input line)
				std::cin.clear();
				//cin.ingore ignores a whole line or to a new line start.(32767 is the size in bytes for a whole line)
				std::cin.ignore(32767, '\n');
				std::cout << "Try another input";
			}
			else
			{
				break;
			}
		}
		//this takes the input from the player, tries to place it on the baord. if the location already have a X/O it will ask to try again.
		if (!takenMarker(input, gameboard)) {
			(std::cout << "This position on the board is already taken.. please try again!" << std::endl);
			turn--;
		}
		//it checks if someone has won on the current gameboard.if the winchecker finds a winning condition 
		//it will print the gameboard and the current winner based on currentmarker.
		if ( winChecker(gameboard) )
		{
			updateBoard(gameboard);
			if (currentmarker == 'O')
			{
				std::cout << "Player one won!!" << std::endl;
				return false;
			}
			else 
			std::cout << "Player two won!!" << std::endl;
			return false;
		}
		//since its TickTackToe it will ALWAYS be draw on turn 9. It will ask the player if it want to try again.
		if (turn == 9) {

			std::cout << "It's a draw!" << std::endl;

			return false;

		}
		system("cls");
		updateBoard(gameboard);
	}
}
bool winChecker(char gameBoardChecker[][3])
{
	//Using sizeof as a parameter, check if [0][0] has the same marker as [0][1] and if [0][0] has the same marker as[0][2]. repeat for each row
	//Using sizeof as a parameter, check if [0][0] has the same marker as [1][0] and if [0][0] has the same marker as[2][0]. repeat for each column
	for (size_t i = 0; i < sizeof(gameBoardChecker[0]) / sizeof(gameBoardChecker[0][0]); i++)
	{
		if (gameBoardChecker[i][0] == gameBoardChecker[i][1] && gameBoardChecker[i][0] == gameBoardChecker[i][2])
		{
			return true;

		}
		if (gameBoardChecker[0][i] == gameBoardChecker[1][i] && gameBoardChecker[0][i] == gameBoardChecker[2][i])
		{
			return true;
		}
	}
	//This is to check the cross section of the gameboard, this is not inn a for loop since its different row and column each time.
	if (gameBoardChecker[0][0] == gameBoardChecker[1][1] && gameBoardChecker[0][0] == gameBoardChecker[2][2])
	{
		return true;
	}
	if (gameBoardChecker[0][2] == gameBoardChecker[1][1] && gameBoardChecker[0][2] == gameBoardChecker[2][0])
	{
		return true;
	}

	return false;
}
//During the game this will take the information based from the gameboard and update it, this is where the code saves the (O/X)
void updateBoard(char gameboard[][3]) {

	std::cout << "           " << gameboard[0][0] << "  |  " << gameboard[0][1] << "  |  " << gameboard[0][2] << std::endl;
	std::cout << "          -----------------" << std::endl;
	std::cout << "           " << gameboard[1][0] << "  |  " << gameboard[1][1] << "  |  " << gameboard[1][2] << std::endl;
	std::cout << "          -----------------" << std::endl;
	std::cout << "           " << gameboard[2][0] << "  |  " << gameboard[2][1] << "  |  " << gameboard[2][2] << std::endl;

	std::cout << std::endl;
}
//this a more mathematic way of going trough [0][0] all the way to [2][2]
bool takenMarker(int place, char gameboard[][3]) {
	//row will be same as place, then Divide with 3.
	int row = place / 3; {}
	int col;
	//checks if the remainder is equals to 0(checks if the selected position is divisible by 3)
	if (place % 3 == 0)
	{
		//sets rows and colmuns
		row = row - 1;
		col = 2;
	}
	//sets column to correct value if place is NOT divisible by 3.
	else col = (place % 3) - 1;
	//if the spot is not taken by (X/O) it will return true which means the spot is open.
	if (gameboard[row][col] != 'X' && gameboard[row][col] != 'O')
	{
		//after input by the player, it will place a marker based on turn(Which type of marker that should be placed)
		gameboard[row][col] = currentmarker;
		return true;
	}
	else return false;
}

