#pragma once
#include "Component.h"
#include "GameObject.h"


class Rocket1Script : public Script {
public:
	Rocket1Script(GameObject *_object) : Script(_object) {}
	float speed = 15;
	float rotationSpeed = 30 / 15;
	virtual void update() {
		GameObject* player = objectManager.getObject<Player>();
		Transform* trPlayer = player->getComponent<Transform>();
		Transform* tr = getComponent<Transform>();

		float x = tr->x - trPlayer->x;
		float y = tr->y - trPlayer->y;
		float rotation = 180 * ((y < 0) ? 1 : 0) + 180 / 3.1415 *atan(-(x / y));
		if (tr->rotation > rotation) {
			tr->rotation -= rotationSpeed;
		}
		else {
			tr->rotation += rotationSpeed;
		}

		tr->x += sinf(tr->rotation / 180 * 3.1415) * speed;
		tr->y -= cosf(tr->rotation / 180 * 3.1415) * speed;

		if ((tr->x - trPlayer->x) * (tr->x - trPlayer->x) + (tr->y - trPlayer->y) * (tr->y - trPlayer->y) > 9000000) {
			//objectManager.clear(getId());
		}
	}

	virtual ~Rocket1Script() {}
};


class Rocket1 : public GameObject {
public:
	Rocket1(int _id) : GameObject(_id) {
		assign<Transform>(0, 0);
		assign<Rocket1Script>();
		assign<Image>("images/Rocket1.png", 0.2);
	}
	~Rocket1() {};
};