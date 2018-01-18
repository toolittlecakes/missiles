#pragma once

#include "ObjectManager.h"

class ScriptManager {
	ObjectManager& objectManager = ObjectManager::Instance();
public:
	void init() {};
	void update();
};