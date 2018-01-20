#pragma once

#include <vector>
#include "Component.h"

class GameObject {
	std::vector<Component*> components;
	int id;
public:
	GameObject(int _id) : id(_id) {};
	
	int getId() { return id; }

	template <typename T>
	T* getComponent() {
		for (auto it = components.begin(); it != components.end(); ++it) {
			if (dynamic_cast<T*>(*it) != nullptr) { return dynamic_cast<T*>(*it); }
		}
		return nullptr;
	}

	template<typename T, typename ...Args>
	void assign(Args&& ...args) {
		components.push_back(new T(this, args...));
	}
	template <typename T>
	void unAssign() {
		for (auto it = components.begin(); it != components.end(); ++it) {
			if (dynamic_cast<T*>(*it) != nullptr) { components.erase(it); return; }
		}
		return;
	}
	virtual ~GameObject() {};
};