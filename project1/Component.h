#pragma once
#include "InputManager.h"
#include "ObjectManager.h"
#include <SFML\Graphics.hpp>
class GameObject;

class Component {
	GameObject* object;
protected:
	int getId();
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
	
	sf::Texture texture;//создаем объект Texture (текстура)
	sf::Sprite sprite;//создаем объект Sprite(спрайт)
public:
	bool visible = 1;
	Image(GameObject* _object, std::string filename, float scale = 1) : Component(_object) {
		sf::Image image;
		image.loadFromFile(filename);
		texture.loadFromFile(filename);//загружаем картинку
		texture.setSmooth(true);
		sprite.setTexture(texture);//передаём в него объект Texture (текстуры)
		sprite.setOrigin(static_cast<float>(texture.getSize().x/2), static_cast<float>(texture.getSize().y/2));	
		sprite.setScale(scale, scale);
	}
	virtual sf::Texture& getTexture();
	virtual sf::Sprite& getSprite();
	virtual ~Image() {};
};

class Collide : public Component {
	std::vector<GameObject*> collided;
	float collideRadix;
public:
	Collide(GameObject* _object, float _collideRadix) : Component(_object), collideRadix(_collideRadix) {}
	void addObject(GameObject* newObject) { collided.push_back(newObject); }
	void clear() { collided.clear(); }
	float getRadix() { return collideRadix; }
	std::vector<GameObject*>& getCollision() { return collided; }

	virtual ~Collide() {};
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