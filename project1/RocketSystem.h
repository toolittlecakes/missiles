#pragma once
#include "Component.h"
#include "GameObject.h"
#include <iostream>

class Rocket1;
class Player;
class RocketSystemObjectScript : public Script {
public:
	RocketSystemObjectScript(GameObject *_object) : Script(_object) {}

	time_t timeRocket1 = 10;
	sf::Clock clockRocket1;
	virtual void update() {
		GameObject* player = objectManager.getObject<Player>();
		Transform* trPlayer = player->getComponent<Transform>();

		if (clockRocket1.getElapsedTime().asSeconds() > timeRocket1) {
			clockRocket1.restart();
			GameObject* rocket1 = objectManager.create<Rocket1>();
			Transform* trRocket1 = rocket1->getComponent<Transform>();
			float x = rand() % 2000 - 1000;
			float y = ((rand() % 2) * 2 - 1) * sqrt(1000000 - x * x);
			trRocket1->x = trPlayer->x + x;
			trRocket1->y = trPlayer->y + y;
			trRocket1->rotation = 180 * ((y < 0) ? 1 : 0) + 180 / 3.1415 *atan(-(x / y));
		}
	}

	virtual ~RocketSystemObjectScript() {}
};

class RocketSystemObject : public GameObject {
public:
	RocketSystemObject(int _id) : GameObject(_id) {
		assign<RocketSystemObjectScript>();
	}
	~RocketSystemObject() {};
};