#include "ObjectManager.h"
#include "Camera.h"

#include "Background.h"
#include "Player.h"
#include "Player2.h"


void ObjectManager::init()
{
	//engine objects
	create<Camera>();
	
	//user objects
	create<Background>();
	create<Player>();
	create<Player2>();
}



