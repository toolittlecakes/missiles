#pragma once
#include "Component.h"
#include "GameObject.h"
class PlayerScript : public Script {
public:
	PlayerScript(GameObject *_object) : Script(_object) {}


	float speed = 10;
	float rotationSpeed = 30 / speed;
	virtual void update() {
		Transform* tr = getComponent<Transform>();
		
		tr->x += sinf(tr->rotation / 180 * 3.1415) * speed;
		tr->y -= cosf(tr->rotation / 180 * 3.1415) * speed;


		tr->rotation += input.getAxisX() * rotationSpeed;


	}

	virtual ~PlayerScript() {}
};

class Player : public GameObject {
public:
	Player(int _id) : GameObject(_id) {
		assign<Transform>(0,0);
		assign<PlayerScript>();
		assign<Image>("images/Player.png", 0.2);
	}
	~Player() {};
};