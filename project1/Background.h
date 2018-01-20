#pragma once
#include "Component.h"
#include "GameObject.h"
class BackgroundScript : public Script {
public:
	BackgroundScript(GameObject *_object) : Script(_object) {}

	virtual void update() {
		GameObject* player = objectManager.getObject<Player>();
		if (player == nullptr) { return; }
		Transform* playerTr = player->getComponent<Transform>();
		Transform* tr = getComponent<Transform>();
		tr->x = playerTr->x;
		tr->y = playerTr->y;
	}

	virtual ~BackgroundScript() {}
};

class Background : public GameObject {
public:
	Background(int _id) : GameObject(_id) {
		assign<Transform>(0, 0);
		assign<BackgroundScript>();
		assign<Image>("images/Background.png");
	}
	~Background() {};
};