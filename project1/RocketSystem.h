#pragma once
#include "Component.h"
#include "GameObject.h"
#include <iostream>

class Rocket1;
class Rocket2;
class Rocket3;
class Player;
class RocketSystemScript : public Script {
public:
	RocketSystemScript(GameObject *_object) : Script(_object) {}

	time_t timeRocket1 = 7;
	sf::Clock clockRocket1;
	
	time_t timeRocket2 = 20;
	sf::Clock clockRocket2;

	time_t timeRocket3 = 15;
	sf::Clock clockRocket3;
	virtual void update() {
		GameObject* player = objectManager.getObject<Player>();
		if (player == nullptr) { return; }
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

		if (clockRocket2.getElapsedTime().asSeconds() > timeRocket2) {
			clockRocket2.restart();
			GameObject* rocket2 = objectManager.create<Rocket2>();
			Transform* trRocket2 = rocket2->getComponent<Transform>();
			float x = rand() % 2000 - 1000;
			float y = ((rand() % 2) * 2 - 1) * sqrt(1000000 - x * x);
			trRocket2->x = trPlayer->x + x;
			trRocket2->y = trPlayer->y + y;
			trRocket2->rotation = 180 * ((y < 0) ? 1 : 0) + 180 / 3.1415 *atan(-(x / y));
		}
		
		if (clockRocket3.getElapsedTime().asSeconds() > timeRocket3) {
			clockRocket3.restart();
			GameObject* rocket3 = objectManager.create<Rocket3>();
			Transform* trRocket3 = rocket3->getComponent<Transform>();
			float x = rand() % 2000 - 1000;
			float y = ((rand() % 2) * 2 - 1) * sqrt(1000000 - x * x);
			trRocket3->x = trPlayer->x + x;
			trRocket3->y = trPlayer->y + y;
			trRocket3->rotation = 180 * ((y < 0) ? 1 : 0) + 180 / 3.1415 *atan(-(x / y));
		}
	}

	virtual ~RocketSystemScript() {}
};

class RocketSystem : public GameObject {
public:
	RocketSystem(int _id) : GameObject(_id) {
		assign<RocketSystemScript>();
	}
	~RocketSystem() {};
};