/* 
 * File:   SolarSystem.cpp
 * Author: scott
 * 
 * Created on July 20, 2010, 3:50 PM
 */

#include "SolarSystem.h"

SolarSystem::SolarSystem()
{
	objects.push_front(new Ship(5.0f, 1.0f, -20.0f));
	objects.push_front(new Ship(-5.0f, -1.0f, -20.0f));
	objects.push_front(new Ship(1.0f, 1.0f, 20.0f));
	// objects.push_front(new AxisObject(-1.0f, 0.0f, 0.0f));
}

SolarSystem::SolarSystem(const SolarSystem& orig)
{
}

SolarSystem::~SolarSystem()
{
}

