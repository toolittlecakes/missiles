#pragma once
#include "GameObject.h"

class PlayerScript : public Script {
public:
	PlayerScript(GameObject *_object) : Script(_object) {}

	void update() {
		Transform* tr = getComponent<Transform>();
		tr->x += Input::getAxisX();
	}

	virtual ~PlayerScript() {}
};

class Player : public GameObject {
public:
	Player() : GameObject() {
		assign<Transform>();
		assign<PlayerScript>();
	}
	~Player() {};
};