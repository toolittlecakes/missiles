#pragma once

#include <SFML\System.hpp>
#include "Component.h"
#include "GameObject.h"
#include <iostream>

class Rocket1;
class Cloud;
class Player;
class MainObjectScript : public Script {
public:
	MainObjectScript(GameObject *_object) : Script(_object) {}

	time_t timeCloud = 1;
	time_t timeRocket1 = 10;
	sf::Clock clockCloud;
	sf::Clock clockRocket1;
	virtual void update() {
		GameObject* player = objectManager.getObject<Player>();
		Transform* trPlayer = player->getComponent<Transform>();
		
		if (clockCloud.getElapsedTime().asSeconds() > timeCloud) {
			clockCloud.restart();
			GameObject* cloud = objectManager.create<Cloud>();
			Transform* trCloud = cloud->getComponent<Transform>();
			float x = rand() % 2000 - 1000;
			float y = ((rand() % 2) * 2 - 1) * sqrt(1000000 - x * x);
			trCloud->x = trPlayer->x + x;
			trCloud->y = trPlayer->y + y;
		}
		if (clockRocket1.getElapsedTime().asSeconds() > timeRocket1) {
			clockRocket1.restart();
			GameObject* cloud = objectManager.create<Rocket1>();
			Transform* trRocket1 = cloud->getComponent<Transform>();
			float x = rand() % 2000 - 1000;
			float y = ((rand() % 2) * 2 - 1) * sqrt(1000000 - x * x);
			trRocket1->x = trPlayer->x + x;
			trRocket1->y = trPlayer->y + y;
			trRocket1->rotation = 180 * ((y < 0) ? 1 : 0) + 180 / 3.1415 *atan(-(x / y));
		}
	}

	virtual ~MainObjectScript() {}
};

class MainObject : public GameObject {
public:
	MainObject(int _id) : GameObject(_id) {
		assign<MainObjectScript>();
	}
	~MainObject() {};
};