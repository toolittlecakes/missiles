#pragma once
#include "Component.h"
#include "GameObject.h"
class BackgroundScript : public Script {
public:
	BackgroundScript(GameObject *_object) : Script(_object) {}

	virtual void update() {
		Transform* tr = getComponent<Transform>();
		tr->x += input.getAxisX();
	}

	virtual ~BackgroundScript() {}
};

class Background : public GameObject {
public:
	Background() : GameObject() {
		assign<Transform>(0, 0);
		assign<BackgroundScript>();
		assign<Image>("images/Background.png");
	}
	~Background() {};
};