#include "Component.h"
#include "GameObject.h"
sf::Texture & Image::getTexture()
{
	return texture;
}

sf::Sprite& Image::getSprite()
{
	return sprite;
}

int Component::getId()
{
	return object->getId();
}
