#pragma once

#include <vector>
#include "GameObject.h"
#include "Component.h"

#include "Player.h"

class ObjectManager {
	std::vector<GameObject*> objects;
public:
	template <typename T>
	void create() {
		objects.push_back(new T);
	}
	std::vector<GameObject*>& getObjects() { return objects; }
};