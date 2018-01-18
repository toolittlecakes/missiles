#pragma once

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <map>


class Input {
	static sf::RenderWindow* window;
	static std::map<sf::Keyboard::Key, bool> keys;
public:
	static void init(sf::RenderWindow* _win) { window = _win ;};
	static void refresh() {
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
public:
	static int getAxisY() {
		return (keys[sf::Keyboard::Key::S] || keys[sf::Keyboard::Key::Down]) - (keys[sf::Keyboard::Key::W] || keys[sf::Keyboard::Key::Up]);
	}
	static int getAxisX() {
		return (keys[sf::Keyboard::Key::D] || keys[sf::Keyboard::Key::Right]) - (keys[sf::Keyboard::Key::A] || keys[sf::Keyboard::Key::Left]);
	}
	static bool getKeyState(sf::Keyboard::Key key) { return keys[key]; }
};

