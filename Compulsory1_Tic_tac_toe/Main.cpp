#include <iostream>
#include <cstdlib>

void gameLayout();
void TTTS();

int main() {

	gameLayout();
	TTTS();

	return 0;
}

void gameLayout() {
	int array[9] = { 1,2,3,4,5,6,7,8,9 };

	std::cout << "********  Welcome to Tic Tac Toe! ********" << std::endl;

	for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
		if (i % 3 == 0) {

			std::cout << "| " << i + 1 << " | " << i + 2 << " | " << i + 3 << " |" << std::endl;


		}
		

	}
	std::cout << "******************************************" << std::endl;
	system("PAUSE");
	system("cls");

}


void TTTS() {
	int turn = (1);
	int playerOne{};
	bool gameWon = false;


	

	 {
		int array[9] = { 1,2,3,4,5,6,7,8,9 };
		for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
			if (i % 3 == 0) {

				std::cout << "| " << i + 1 << " | " << i + 2 << " | " << i + 3 << " |" << std::endl;
			}
		}

		std::cout << "Player 1 -choose a number from 1 to 9 ";
		std::cin >> playerOne;


		
		}
	}
