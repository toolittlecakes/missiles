#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <map>
class InputManager {
	sf::RenderWindow* window = nullptr;
	std::map<sf::Keyboard::Key, bool> keys;
public:


	void init(sf::RenderWindow* _window) { window = _window; }
	
	void update();

	int getAxisY();
	int getAxisX();
	bool getKeyState(sf::Keyboard::Key key) { return keys[key]; }

	//singleton part
	static InputManager& Instance() {
		static InputManager singleInstance;
		return singleInstance;
	}
private:
	InputManager() {};
	InputManager(const InputManager& root) = delete;
	InputManager& operator=(const InputManager&) = delete;
};
