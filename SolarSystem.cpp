/* 
 * File:   SolarSystem.cpp
 * Author: scott
 * 
 * Created on July 20, 2010, 3:50 PM
 */

#include "SolarSystem.h"

SolarSystem::SolarSystem()
{
	Ship* ship;
	ship = new Ship(5.0f, 1.0f, -20.0f);
	ship->load();
	objects.push_front(ship);
	ship = new Ship(-5.0f, -3.0f, -20.0f);
	ship->load();
	objects.push_front(ship);
	ship = new Ship(1.0f, 1.0f, 20.0f);
	ship->load();
	objects.push_front(ship);
	// objects.push_front(new AxisObject(-1.0f, 0.0f, 0.0f));
}

SolarSystem::SolarSystem(const SolarSystem& orig)
{
}

SolarSystem::~SolarSystem()
{
}

