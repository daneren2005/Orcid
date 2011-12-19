/* 
 * File:   SolarSystem.cpp
 * Author: scott
 * 
 * Created on July 20, 2010, 3:50 PM
 */

#include "SolarSystem.h"
#include "Explosion.h"

SolarSystem::SolarSystem(FirstPersonCamera* camera)
{
	units = 0x0;
}

SolarSystem::SolarSystem(const SolarSystem& orig)
{
}

SolarSystem::~SolarSystem()
{
}

void SolarSystem::load()
{
	/*for(Map<DataFile::Object*, String>::Iterator it = units->begin(); !it; it++)
	{
		String model = it.value()->properties.search("Model");
		resourceManager.loadModel(model, it.value()->name);
	}*/
	
	DataFile::Object* obj = units->getObject("Ship1");
	resourceManager.loadModel(obj->strings.search("model"), obj->name);

	Ship* ship;
	ship = new Ship(obj, 0x0);
	// ship->load();
	objects.pushBack(ship);
        
    // camera->attachTo(ship);
	// ship = new Ship(0.0f, -6.0f, 20.0f);
	// ship->load();
	// objects.push_back(ship);
	// ship = new Ship(5.0f, 1.0f, -60.0f);
	// ship->load();
	// objects.pushBack(ship);

	/*Explosion* explosion = new Explosion();
	explosion->start();
	objects.push_back(explosion);*/

	objects.pushFront(new AxisObject(0.0f, 0.0f, 0.0f));
}

