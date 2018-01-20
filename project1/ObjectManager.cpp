#include "ObjectManager.h"
#include "Camera.h"


#include "Background.h"
#include "Player.h"
#include "Cloud.h"
#include "Rocket1.h"

#include "CloudSystem.h"
#include "RocketSystem.h"

#include <iostream>

void ObjectManager::init()
{
	//engine objects
	create<Camera>();
	
	//user objects

	create<Background>();
	
	create<CloudSystem>();
	create<Player>();
	create<RocketSystem>();

}

void ObjectManager::clear(int id)
{
	objectToClear.push_back(id);
}

void ObjectManager::update()
{
	for (int i = objectToClear.size(); i > 0; i--) {
		int id = objectToClear.back();
		for (auto it = objects.begin(); it != objects.end();) {
			if ((*it)->getId() == id) {
				it = objects.erase(it);
			}
			else {
				++it;
			}
		}
		objectToClear.pop_back();
	}
}



