#pragma once
#include "Component.h"
#include "GameObject.h"


class CloudScript : public Script {
public:
	CloudScript(GameObject *_object) : Script(_object) {}

	virtual void update() {
		GameObject* player = objectManager.getObject<Player>();
		Transform* playerTr = player->getComponent<Transform>();
		Transform* tr = getComponent<Transform>();
		if ((tr->x - playerTr->x) * (tr->x - playerTr->x) + (tr->y - playerTr->y) * (tr->y - playerTr->y) > 9000000) {
			objectManager.clear(getId());
		}
	}

	virtual ~CloudScript() {}
};


class Cloud : public GameObject {
public:
	Cloud(int _id) : GameObject(_id) {
		assign<Transform>(0, 0);
		assign<CloudScript>();
		assign<Image>("images/Cloud.png", 0.2);
	}
	~Cloud() {};
};