
//#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <vector>
#include "Input.h"
#include "GameObject.h"
#include "ObjectManager.h"
#include "Game.h"

int main()
{
	Game game;
	game.init();
	game.start();
	return 0;
}