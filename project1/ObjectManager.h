#pragma once

#include <vector>
//#include "GameObject.h"
class GameObject;

class ObjectManager {
private:
	std::vector<GameObject*> objects;
public:

	template <typename T>
	void create() { objects.push_back(new T); }
	void init();
	std::vector<GameObject*>& getObjects() { return objects; }

	template <typename T>
	std::vector<GameObject*> getObjects() {
		std::vector<GameObject*> result;
		for (auto it = objects.begin(); it != objects.end(); ++it) {
			if (dynamic_cast<T*>(*it) != nullptr) {
				result.push_back(*it);
			}
		}
		return std::move(result);
	}
	template <typename T>
	GameObject* getObject() {
		for (auto it = objects.begin(); it != objects.end(); ++it) {
			if (dynamic_cast<T*>(*it) != nullptr) {
				return *it;
			}
		}
		return nullptr;
	}
	//singleton part
	static ObjectManager& Instance() {
		static ObjectManager singleInstance;
		return singleInstance;
	}
private:
	ObjectManager(const ObjectManager& root) = delete;
	ObjectManager& operator=(const ObjectManager&) = delete;
	ObjectManager() {};

};