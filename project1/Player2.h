#pragma once


#include "Component.h"
#include "GameObject.h"
class Player2Script : public Script {
public:
	Player2Script(GameObject *_object) : Script(_object) {}

	virtual void update() {
		Transform* tr = getComponent<Transform>();
		tr->x += input.getAxisX();
	}

	virtual ~Player2Script() {}
};

class Player2 : public GameObject {
public:
	Player2() : GameObject() {
		assign<Transform>(100, 100);
		assign<Player2Script>();
		assign<Image>("images/Player.png", -45);
	}
	~Player2() {};
};