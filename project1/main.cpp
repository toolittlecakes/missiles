
//#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <vector>
#include "Input.h"
#include "GameObject.h"
#include "ObjectManager.h"


int main()
{
	sf::Window window(sf::VideoMode(900, 600), "My window", sf::Style::Fullscreen);
	window.setVerticalSyncEnabled(true);
	Input::init(&window);
	ObjectManager manager;
	manager.create<Player>();
	while (window.isOpen()) {
		
		Input::refresh();
		(manager.getObjects().front()->getComponent<Script>())->update();

		std::cout << manager.getObjects().front()->getComponent<Transform>()->x << std::endl;
	}
	return 0;
}