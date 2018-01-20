#pragma once
#include "Component.h"
#include "GameObject.h"
#include <iostream>
class Camera;

class PlayerScript : public Script {
public:
	PlayerScript(GameObject *_object) : Script(_object) {}


	float speed = 10;
	float rotationSpeed = 40 / speed;
	virtual void update() {
		Transform* tr = getComponent<Transform>();
		
		tr->x += sinf(tr->rotation / 180 * 3.1415) * speed;
		tr->y -= cosf(tr->rotation / 180 * 3.1415) * speed;


		tr->rotation += input.getAxisX() * rotationSpeed;

		if (!getComponent<Collide>()->getCollision().empty()) {
			objectManager.clear(getId());
			
			/*getComponent<Image>()->visible = 0;
			speed = 0;*/
		}
	}

	virtual ~PlayerScript() {}
};

class Player : public GameObject {
public:
	Player(int _id) : GameObject(_id) {
		assign<Transform>(0,0);
		assign<PlayerScript>();
		assign<Image>("images/Player.png", 0.2);
		assign<Collide>(15);
	}
	~Player() {};
};