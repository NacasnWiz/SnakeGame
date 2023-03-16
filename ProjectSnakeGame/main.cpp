#include <iostream>
#include <string>
#include "user_interface.h"
#include "Game.h"

#include <conio.h>

const double NUM_SECONDS = 0.5;


Direction receiveDirectionInput() {
	//char input;
	//std::cin >> input;
	char input = (int)( _getch() );

	switch (input) {
	case 'z':
	case 'Z':
		return Up;
	case 'q':
	case 'Q':
		return Left;
	case 's':
	case 'S':
		return Down;
	case 'd':
	case 'D':
		return Right;
	default:
		return Invalid;
	}

}

void startGame(Game& game) {
	game.start();
	printGame(game);
}

bool isGameOver(Game& game) {
	for (unsigned long iBody{ 1 }; iBody < game.getSnake().length; ++iBody) {
		if (game.getSnake().body[0] == game.getSnake().body[iBody]) {
			return true;
		}
	}
	return false;
}

void playGame(Game& game) {
	//receive Input
	Direction nextMove{};
	bool isLastMoveValid{ true };

	if (_kbhit()) {
		nextMove = receiveDirectionInput();
	}
	else {
		nextMove = game.getSnake().headOrientation;
	}

	//move accordingly
	if (game.isMoveValid(nextMove)) {
		game.moveSnake(nextMove);
	}
	else {
		nextMove = game.getSnake().headOrientation;
		game.moveSnake(nextMove);
	}

	if (isGameOver(game)) {
		game.gameOver();
	}


	//snake eats apple?
	if (game.isAppleEaten()) {
		game.snakeEatsApple();

		clearScreen();
		printGame(game);
		std::cout << "Gnap!\n";
	}//print the game state anyways
	else {
		clearScreen();
		printGame(game);
		std::cout << "please type one char ";
		if (!isLastMoveValid) {
			std::cout << " Sorry, we only accept zqsd input.\n";
		}
	}
	
}

int main()
{
	Game current_game{};

	startGame(current_game);

	double time_counter = 0;

	clock_t this_time = clock();
	clock_t last_time = this_time;

	printf("Gran = %ld\n", (int) NUM_SECONDS * CLOCKS_PER_SEC);

	while (current_game.m_isOn)
	{
		this_time = clock();

		time_counter += (double)(this_time - last_time);

		last_time = this_time;

		if (time_counter > (double)(NUM_SECONDS * CLOCKS_PER_SEC))
		{
			time_counter -= (double)(NUM_SECONDS * CLOCKS_PER_SEC);
			playGame(current_game);
		}

	}


	std::cout << "GameOver!";

}