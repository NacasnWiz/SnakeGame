#pragma once
#include <utility>
#include <vector>

enum Direction {
	Invalid = 0,
	Up = -1,
	Right = 2,
	Down = 1,
	Left = -2
};

struct Field {
	int width;
	int length;
	std::pair<int, int> applePos;
};

struct Snake {
	Direction headOrientation{ Up };
	int length{2};
	std::vector<std::pair<int, int>> body{ {6,10}, {7,10} };//body[0] is always the head!
};

class Game
{
private:
	Field m_field;
	Snake m_snake;


public:
	bool m_isOn{ false };

	Game() :
		m_field{ Field({16, 10, std::make_pair(2,5)}) },
		m_snake{ Snake() }
	{
	}

	bool isMoveValid(Direction nextMove);
	void moveSnake(Direction direction);
	void start();
	bool isAppleEaten();
	void snakeEatsApple();
	void renewApple();
	void gameOver();

	Field getField() { return m_field; }
	Snake getSnake() { return m_snake; }
};

