#pragma once
#include <utility>

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
public:
	Field m_field;
	Snake m_snake;

	Game() :
		m_field{ Field({10, 11, std::make_pair(2,8)}) },
		m_snake{ Snake({std::make_pair(7,8)}) }
	{
	}


	Field getField() { return m_field; }
};

