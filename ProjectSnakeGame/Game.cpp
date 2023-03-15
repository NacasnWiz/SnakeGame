#include "Game.h"


void Game::moveSnake(Direction direction) {
	std::pair<int, int> nextHeadPos{ m_snake.body[0]};
	
	m_snake.headOrientation = direction;
	switch (direction) {
	case Up:
		nextHeadPos.first -= 1;
		break;
	case Right:
		nextHeadPos.second += 1;
		break;
	case Down:
		nextHeadPos.first += 1;
		break;
	case Left:
		nextHeadPos.second -= 1;
		break;
	}

	m_snake.body.insert(m_snake.body.begin(), nextHeadPos);
	m_snake.body.resize(m_snake.length);

}

void Game::start() {
	m_isOn = true;
}

void Game::gameOver() {
	m_isOn = false;
}

bool Game::isAppleEaten() {
	return (m_snake.body[0] == m_field.applePos);
}

void Game::renewApple() {
	m_field.applePos = std::make_pair<int, int>(5, 5);
}

void Game::snakeEatsApple() {
	renewApple();
	m_snake.body.push_back(m_snake.body[m_snake.length - 1]);
	m_snake.length += 1;
}

bool Game::isMoveValid(Direction nextMove) {
	return (nextMove + m_snake.headOrientation != 0);
}

