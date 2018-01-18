#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "ObjectManager.h"

class OutputManager {
	sf::RenderWindow* window;
	ObjectManager& objectManager = ObjectManager::Instance();

public:
	void init(sf::RenderWindow* _window) { window = _window;
	sf::View view = window->getView();
	view.zoom(2);
	window->setView(view);
	};
	void update();
};