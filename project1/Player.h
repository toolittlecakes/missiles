#pragma once
#include "Component.h"
#include "GameObject.h"
class PlayerScript : public Script {
public:
	PlayerScript(GameObject *_object) : Script(_object) {
	
	}

	virtual void update() {
		Transform* tr = getComponent<Transform>();
		
		input.getAxisX();


	}

	virtual ~PlayerScript() {}
};

class Player : public GameObject {
public:
	Player() : GameObject() {
		assign<Transform>(0,0);
		assign<PlayerScript>();
		assign<Image>("images/Player.png", -45);
	}
	~Player() {};
};