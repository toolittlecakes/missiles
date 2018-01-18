#pragma once
#include "GameObject.h"
#include "Component.h"

class CameraScript : public Script {
public:
	CameraScript(GameObject *_object) : Script(_object) {}

	void update() {
		Transform* tr = getComponent<Transform>();
		tr->x += input.getAxisY();
	}

	virtual ~CameraScript() {}
};

class Camera : public GameObject {
public:
	Camera() : GameObject() {
		assign<Transform>(0, 0);
		assign<CameraScript>();
	}
	~Camera() {};
};