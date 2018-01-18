#pragma once
#include <vector>
#include <string>
#include <memory>
#include "Component.h"

class GameObject {
	std::vector<Component*> components;
	int id;
public:
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
	virtual ~GameObject() {};
};