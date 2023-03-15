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

void playGame(Game& game) {
	//receive Input
	Direction nextMove{ receiveDirectionInput() };
	while (!nextMove) {
		nextMove = receiveDirectionInput();
	}

	//move accordingly
	game.moveSnake(nextMove);

	//snake eats apple?
	if (game.isAppleEaten()) {
		game.renewApple();
		clearScreen();
		printGame(game);
		std::cout << "Gnap!\n";
		//print the game state
	}
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


}