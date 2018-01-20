#pragma once
#include "Component.h"
#include "GameObject.h"
#include <iostream>

class Cloud;
class Player;
class CloudSystemScript : public Script {
public:
	CloudSystemScript(GameObject *_object) : Script(_object) {}

	time_t timeCloud = 1;
	sf::Clock clockCloud;
	virtual void update() {
		GameObject* player = objectManager.getObject<Player>();
		if (player == nullptr) { return; }
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
	}

	virtual ~CloudSystemScript() {}
};

class CloudSystem : public GameObject {
public:
	CloudSystem(int _id) : GameObject(_id) {
		assign<CloudSystemScript>();
	}
	~CloudSystem() {};
};