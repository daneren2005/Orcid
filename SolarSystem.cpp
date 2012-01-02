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
}

void SolarSystem::load(const DataFile& world)
{
	DataFile::Object* obj = units->getObject("Ship1");
	
	DataFile::Object* shipData = world.getObject("Ship1");
	Ship* ship;
	ship = new Ship();
	ship->load(obj, shipData);
	// ship->load();
	objects.pushBack(ship);
	
	shipData = world.getObject("Ship2");
	ship = new Ship();
	ship->load(obj, shipData);
	// ship->load();
	objects.pushBack(ship);
	
	objects.pushFront(new AxisObject(0.0f, 0.0f, 0.0f));
}

