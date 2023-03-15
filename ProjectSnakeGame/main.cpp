#include <iostream>
#include <string>
#include "user_interface.h"
#include "Game.h"

Direction receiveDirectionInput() {
	char input;
	std::cout << "please type one char ";
	std::cin >> input;

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
		std::cout << "Sorry, we only accept zqsd input.\n";
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
	Direction nextMove{ receiveDirectionInput() };
	while (!nextMove) {
		nextMove = receiveDirectionInput();
	}

	//move accordingly
	if (game.isMoveValid(nextMove)) {
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
	}
	
}

int main()
{
	Game current_game{};

	startGame(current_game);

	while (current_game.m_isOn) {
		playGame(current_game);
	}

	std::cout << "GameOver!";


}