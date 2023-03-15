#include "Game.h"


void Game::moveSnake(Direction direction) {
	switch (direction) {
	case Up:
		m_snake.headPos.first -= 1;
		break;
	case Right:
		m_snake.headPos.second += 1;
		break;
	case Down:
		m_snake.headPos.first += 1;
		break;
	case Left:
		m_snake.headPos.second -= 1;
		break;
	}
}

void Game::start() {
	m_isOn = true;
}

bool Game::isAppleEaten() {
	return ((m_snake.headPos.first == m_field.applePos.first) && (m_snake.headPos.second == m_field.applePos.second));
}

void Game::renewApple() {
	m_field.applePos = std::make_pair<int, int>(5, 5);
}