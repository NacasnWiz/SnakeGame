#pragma once
#include "Game.h"

void printField(Field field);
void printGame(Game& game);
bool isSnakeHeadHere(int firstCoord, int secondCoord, Game& game);
bool isSnakeBodyHere(int horizontalCoord, int verticalCoord, Game& game);
bool isAppleHere(int horizontalCoord, int verticalCoord, Game& game);
void clearScreen(void);
void printSnakeHead(Snake snake);
void printSnakeBody();
void printApple();
void printEmptyTile();