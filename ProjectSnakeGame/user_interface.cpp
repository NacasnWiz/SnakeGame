#include "user_interface.h"
#include <iostream>

bool isSnakeHeadHere(int horizontalCoord, int verticalCoord, Game& game) {
	return ((horizontalCoord == game.getSnake().headPos.first) && (verticalCoord == game.getSnake().headPos.second));
}

bool isAppleHere(int horizontalCoord, int verticalCoord, Game& game) {
	return ((horizontalCoord == game.getField().applePos.first) && (verticalCoord == game.getField().applePos.second));
}

void clearScreen(void)
{
	system("cls");
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
				std::cout << "^^";
			}
			else if (isAppleHere(iLine, iColumn, game))
			{
				std::cout << char(0xFE) << char(0xFE);
			}
			else
			{
				std::cout << char(0x20) << char(0x20);
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