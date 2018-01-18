#include "OutputManager.h"
#include "Component.h"
#include "GameObject.h"
#include "Camera.h"

#include <SFML\Graphics.hpp>
#include <iostream>
void OutputManager::update()
{
	window->clear();
	
	std::vector<GameObject*>& objects = objectManager.getObjects();
	GameObject* camera = objectManager.getObject<Camera>();
	Transform* cameraTransform = camera->getComponent<Transform>();

	std::cout << cameraTransform->x << ' ' << cameraTransform->y << std::endl;;
	
	sf::View view = window->getView();
	view.setCenter(cameraTransform->x, cameraTransform->y);
	view.setRotation(cameraTransform->rotation);
	window->setView(view);

	for (auto it = objects.begin(); it != objects.end(); ++it) {
		Image* image = (*it)->getComponent<Image>();
		Transform* transform = (*it)->getComponent<Transform>();
		
		if (image != nullptr && transform != nullptr) {
			image->getSprite().setPosition(transform->x, transform->y);
			window->draw(image->getSprite());
		}
	}
	window->display();
}
