#pragma once
#include "Component.h"
#include "GameObject.h"
#include <iostream>

class RocketScript : public Script {
private:
	float speed;
	float rotationSpeed;

public:
	RocketScript(GameObject *_object,float _speed = 15, float _rotationSpeed = 4) : Script(_object) , speed(_speed), rotationSpeed(_rotationSpeed){}
	
	virtual void update() {
		GameObject* player = objectManager.getObject<Player>();
		if (player == nullptr) { return; }
		Transform* trPlayer = player->getComponent<Transform>();
		Transform* tr = getComponent<Transform>();

		float x = tr->x - trPlayer->x;
		float y = tr->y - trPlayer->y;
		float rotation = 180 * ((y < 0) ? 1 : 0) + 180 / 3.1415 * atan(-(x / y));
		if (tr->rotation > rotation) {
			tr->rotation -= rotationSpeed;
		}
		else {
			tr->rotation += rotationSpeed;
		}

		tr->x += sinf(tr->rotation / 180 * 3.1415) * speed;
		tr->y -= cosf(tr->rotation / 180 * 3.1415) * speed;

//		std::vector<GameObject*> collisions = getComponent<Collide>()->getCollision();
		if (!getComponent<Collide>()->getCollision().empty()) {
			objectManager.clear(getId());
		}
		

	}

	virtual ~RocketScript() {}
};



class Rocket1 : public GameObject {
public:
	Rocket1(int _id) : GameObject(_id) {
		assign<Transform>(0, 0);
		assign<RocketScript>(10,2);
		assign<Image>("images/Rocket1.png", 0.1);
		assign<Collide>(10);
	}
	~Rocket1() {};
};

class Rocket2 : public GameObject {
public:
	Rocket2(int _id) : GameObject(_id) {
		assign<Transform>(0, 0);
		assign<RocketScript>(11, 3);
		assign<Image>("images/Rocket2.png", 0.1);
		assign<Collide>(10);
	}
	~Rocket2() {};
};

class Rocket3 : public GameObject {
public:
	Rocket3(int _id) : GameObject(_id) {
		assign<Transform>(0, 0);
		assign<RocketScript>(12, 3.5);
		assign<Image>("images/Rocket3.png", 0.1);
		assign<Collide>(10);
	}
	~Rocket3() {};
};