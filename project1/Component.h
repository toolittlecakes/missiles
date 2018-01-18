#pragma once
#include "Input.h"

class GameObject;

class Component {
	GameObject* object;
public:
	Component(GameObject * _object) : object(_object) {};
	
	template<typename T>
	T* getComponent() {
		return object->getComponent<T>();
	}
	virtual ~Component() {};
};

class Transform : public Component {
public:
	double x, y;
	double xSpeed, ySpeed;
	double rotation;

	Transform(GameObject* _object, double _x = 0, double _y = 0, double _rotation = 0) : Component(_object), x(_x), y(_y), rotation(_rotation) {};
	~Transform() {}; 
};

class Image : public Component {

};

class Script : public Component {
public:
	Script(GameObject* _object) : Component(_object) {};
	virtual void update() = 0;
	virtual ~Script() { }
};



