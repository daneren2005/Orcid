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

void SolarSystem::load(DataFile& world)
{
	DataFile::Object* obj = units->getObject("Ship1");
	
	Ship* ship;
	for(Map<DataFile::Object*, String>::Iterator it = world.begin(); !it; it++)
	{	
		ship = new Ship();
		ship->load(obj, it.value());
		// ship->load();
		objects.pushBack(ship);
	}
	
	objects.pushFront(new AxisObject(0.0f, 0.0f, 0.0f));
}

