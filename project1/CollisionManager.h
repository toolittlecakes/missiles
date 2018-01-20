#pragma once

#include "ObjectManager.h"

class CollisionManager {
	ObjectManager& objectManager = ObjectManager::Instance();

public:
	void init() {};
	void update();
};