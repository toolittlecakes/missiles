#include "ScriptManager.h"
#include "GameObject.h"
#include "Component.h"

void ScriptManager::update()
{
	std::vector<GameObject*>& objects = objectManager.getObjects();
	for (auto it = objects.begin(); it != objects.end(); ++it) {
		Script* script = (*it)->getComponent<Script>();
		if (script != nullptr) {
			script->update();
		}
	}
}
