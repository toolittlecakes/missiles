#include "CollisionManager.h"
#include "Component.h"
#include "GameObject.h"

void CollisionManager::update()
{
	std::vector<GameObject*> objects = objectManager.getObjects();
	for (auto it = objects.begin(); it != objects.end(); ++it) {
		Collide* collide = (*it)->getComponent<Collide>();
		if(collide != nullptr) {
			collide->clear();
		}
	}


	for (auto it1 = objects.begin(); it1 != objects.end(); ++it1) {
		Transform* transform1 = (*it1)->getComponent<Transform>();
		Collide* collide1 = (*it1)->getComponent<Collide>();
		if (transform1 != nullptr && collide1 != nullptr) {
			for (auto it2 = it1 + 1; it2 != objects.end(); ++it2) {

				Transform* transform2 = (*it2)->getComponent<Transform>();
				Collide* collide2 = (*it2)->getComponent<Collide>();
				if (transform2 != nullptr && collide2 != nullptr) {
					float x1 = transform1->x;
					float y1 = transform1->y;
					float x2 = transform2->x;
					float y2 = transform2->y;
					float r1 = collide1->getRadix();
					float r2 = collide2->getRadix();
					if ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) < (r1 + r2) * (r1 + r2)) {
						//collision
						collide1->addObject(*it2);
						collide2->addObject(*it1);
					}
				}
			}
		}
	}
}
