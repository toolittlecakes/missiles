#pragma once
#include "GameObject.h"
#include "Component.h"
#include "Player.h"

class CameraScript : public Script {
public:
	CameraScript(GameObject *_object) : Script(_object) {}

	void update() {
		GameObject* player = objectManager.getObject<Player>();
		if (player == nullptr) { return; }
		Transform* playerTr = player->getComponent<Transform>();
		Transform* tr = getComponent<Transform>();
		tr->x = playerTr->x + 15 * sinf(playerTr->rotation /180 * 3.1415);
		tr->y = playerTr->y - 15 * cosf(playerTr->rotation / 180 * 3.1415);
	}

	virtual ~CameraScript() {}
};

class Camera : public GameObject {
public:
	Camera(int _id) : GameObject(_id) {
		assign<Transform>(0, 0);
		assign<CameraScript>();
	}
	~Camera() {};
};