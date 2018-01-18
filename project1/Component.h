#pragma once
#include "InputManager.h"
#include "ObjectManager.h"
#include <SFML\Graphics.hpp>
class GameObject;

class Component {
	GameObject* object;
protected:
	template<typename T>
	T* getComponent() {
		return object->getComponent<T>();
	}
public:
	Component(GameObject * _object) : object(_object) {};
	
	
	virtual ~Component() {};
};

class Transform : public Component {
public:
	float x, y;
	float rotation;

	Transform(GameObject* _object, float _x = 0, float _y = 0, float _rotation = 0) 
		: Component(_object), x(_x), y(_y), rotation(_rotation) {};
	virtual ~Transform() {}; 
};

class Image : public Component {
	bool visible = 1;
	sf::Texture texture;//создаем объект Texture (текстура)
	sf::Sprite sprite;//создаем объект Sprite(спрайт)
public:
	Image(GameObject* _object, std::string filename, float start_angle = 0) : Component(_object) {
		texture.loadFromFile(filename);//загружаем картинку
		texture.setSmooth(true);
		sprite.setTexture(texture);//передаём в него объект Texture (текстуры)
		sprite.setOrigin(static_cast<float>(texture.getSize().x/2), static_cast<float>(texture.getSize().y/2));
		sprite.rotate(start_angle);
	}
	virtual sf::Texture& getTexture();
	virtual sf::Sprite& getSprite();
	virtual ~Image() {};
};

class Script : public Component {
protected:
	InputManager& input = InputManager::Instance();
	ObjectManager& objectManager = ObjectManager::Instance();
public:
	Script(GameObject* _object) : Component(_object) {};
	virtual void update() = 0;
	virtual ~Script() { }
};

class Tag : public Component {
	std::string tag;
public:
	Tag(GameObject* _object, std::string& _tag) : Component(_object), tag(_tag) {};
	virtual ~Tag() {};
};