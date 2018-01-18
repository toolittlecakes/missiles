#pragma once
#include <SFML\Window.hpp>
#include "ObjectManager.h"
#include "OutputManager.h"
#include "InputManager.h"
#include "ScriptManager.h"

class Game {
	sf::RenderWindow window;
	ObjectManager& ObjManager = ObjectManager::Instance();
	InputManager& InManager = InputManager::Instance();
	OutputManager OutManager;
	ScriptManager ScrManager;
	void update() {
		InManager.update();
		ScrManager.update();
		OutManager.update();
		ObjManager.update();
	}
public:
	void init() {
		window.create(sf::VideoMode(800, 800), "Missilies"/*, sf::Style::Fullscreen*/);
		
		ObjManager.init();
		InManager.init(&window);
		
		ScrManager.init();
		OutManager.init(&window);

	}
	void start() {
		sf::Clock clock;
		while (window.isOpen()) {
			sf::Time elapsed;
			do {
				 elapsed = clock.getElapsedTime();
			} while (elapsed.asMilliseconds() < 25); //40 fps
			clock.restart();
			update();
		}
	}
};