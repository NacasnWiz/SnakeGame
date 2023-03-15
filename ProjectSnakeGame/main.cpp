#include <iostream>
#include "user_interface.h"
#include "Game.h"


int main()
{
	Game current_game{};

	printField(current_game.getField());
}