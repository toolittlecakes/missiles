#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "ObjectManager.h"

class OutputManager {
	sf::RenderWindow* window;
	ObjectManager& objectManager = ObjectManager::Instance();

public:
	void init(sf::RenderWindow* _window) { window = _window; };
	void update();
};