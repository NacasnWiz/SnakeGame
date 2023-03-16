#include "Game.h"
#include <ctime>


void Game::moveSnake(Direction direction) {
	Position nextHeadPos{ m_snake.body[0]};
	
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

	nextHeadPos.first = (nextHeadPos.first + m_field.length) % m_field.length;
	nextHeadPos.second = (nextHeadPos.second + m_field.width) % m_field.width;

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

bool Game::isNewAppleValid(Position newApplePositionCandidate) {
	for (unsigned long iBody{ 0 }; iBody < m_snake.length; ++iBody) {
		if (newApplePositionCandidate == m_snake.body[iBody]) {
			return false;
		}
	}
	return true;
}

Position Game::generateNewApplePos() {
	int nextApplePosHorizontal{ int(std::time(NULL)) % m_field.length };
	int nextApplePosVertical{ int(std::time(NULL)) % m_field.width };
	return std::make_pair(nextApplePosHorizontal, nextApplePosVertical);
}

void Game::renewApple() {
	Position newApplePos{ generateNewApplePos() };
	while (!isNewAppleValid(newApplePos)) {
		newApplePos = generateNewApplePos();
	}

	m_field.applePos = newApplePos;
}

void Game::snakeEatsApple() {
	renewApple();
	m_snake.body.push_back(m_snake.body[m_snake.length - 1]);
	m_snake.length += 1;
}

bool Game::isMoveValid(Direction nextMove) {
	return nextMove && (nextMove + m_snake.headOrientation != 0);
}

