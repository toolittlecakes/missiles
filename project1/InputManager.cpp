
#include "InputManager.h"

void InputManager::update()
{
	sf::Event event;

	while (window->pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			window->close();
			break;

		case sf::Event::KeyPressed:
			keys[event.key.code] = true;
			break;
		case sf::Event::KeyReleased:
			keys[event.key.code] = false;
			break;
		default:
			break;
		}
	}
}

int InputManager::getAxisY()
{
	return (keys[sf::Keyboard::Key::S] || keys[sf::Keyboard::Key::Down]) - (keys[sf::Keyboard::Key::W] || keys[sf::Keyboard::Key::Up]);
}

int InputManager::getAxisX()
{
	return (keys[sf::Keyboard::Key::D] || keys[sf::Keyboard::Key::Right]) - (keys[sf::Keyboard::Key::A] || keys[sf::Keyboard::Key::Left]);
}
