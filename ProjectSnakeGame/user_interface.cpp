#include "user_interface.h"
#include <iostream>
#include <algorithm>

bool isSnakeHeadHere(int horizontalCoord, int verticalCoord, Game& game) {
	return ((horizontalCoord == game.getSnake().body[0].first) && (verticalCoord == game.getSnake().body[0].second));
}

bool isAppleHere(int horizontalCoord, int verticalCoord, Game& game) {
	return ((horizontalCoord == game.getField().applePos.first) && (verticalCoord == game.getField().applePos.second));
}

bool isSnakeBodyHere(int horizontalCoord, int verticalCoord, Game& game) {
	Position positionToCheck{ std::make_pair(horizontalCoord, verticalCoord) };
	for (unsigned long iBody{ 1 }; iBody < game.getSnake().body.size(); ++iBody) {
		if (game.getSnake().body[iBody] == positionToCheck) {
			return true;
		}
	}
	return false;
}

void clearScreen(void)
{
	system("cls");
}

void printSnakeHead(Snake snake) {
	switch (snake.headOrientation) {
	case Up:
		std::cout << "^^";
		return;
	case Right:
		std::cout << "o>";
		return;
	case Down:
		std::cout << "vv";
		return;
	case Left:
		std::cout << "<o";
		return;
	}
}

void printSnakeBody() {
	std::cout << "[]";
}

void printApple() {
	std::cout << char(0xFE) << char(0xFE);
}

void printEmptyTile() {
	std::cout << char(0x20) << char(0x20);
}


void printGame(Game& game) {
	std::cout << '+';
	for (int iColumn{ 0 }; iColumn < game.getField().width; ++iColumn) {
		std::cout << "--";
	}
	std::cout << '+';
	for (int iLine{ 0 }; iLine < game.getField().length ; ++iLine)
	{
		std::cout << "\n|";
		for (int iColumn{ 0 }; iColumn < game.getField().width; ++iColumn)
		{
			if (isSnakeHeadHere(iLine, iColumn, game))
			{
				printSnakeHead(game.getSnake());
			}
			else if (isSnakeBodyHere(iLine, iColumn, game))
			{
				printSnakeBody();
			}
			else if (isAppleHere(iLine, iColumn, game))
			{
				printApple();
			}
			else
			{
				printEmptyTile();
			}
		}
		std::cout << '|';
	}
	std::cout << "\n+";
	for (int iColumn{ 0 }; iColumn < game.getField().width; ++iColumn) {
		std::cout << "--";
	}
	std::cout << "+\n";
}