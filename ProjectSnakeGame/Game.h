#pragma once
#include <utility>

enum Direction {
	Invalid = 0,
	Up,
	Right,
	Down,
	Left
};

struct Field {
	int width;
	int length;
	std::pair<int, int> applePos;
};

struct Snake {
	std::pair<int, int> headPos;
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
		m_snake{ Snake({std::make_pair(6,10)}) }
	{
	}

	void moveSnake(Direction direction);
	void start();
	bool isAppleEaten();
	void renewApple();


	Field getField() { return m_field; }
	Snake getSnake() { return m_snake; }
};

