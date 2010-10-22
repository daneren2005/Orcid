/* 
 * File:   SolarSystem.cpp
 * Author: scott
 * 
 * Created on July 20, 2010, 3:50 PM
 */

#include "SolarSystem.h"

SolarSystem::SolarSystem()
{
	Mesh mesh(4);
	mesh[0] = Triangle(Vector(0.0f, 1.0f, 0.0f),
			Vector(-1.0f, -1.0f, 1.0f),
			Vector(1.0f, -1.0f, 1.0f),
			Vector(1.0f, 0.0f, 0.0f));
	mesh[1] = Triangle(Vector(0.0f, 1.0f, 0.0f),
			Vector(1.0f, -1.0f, 1.0f),
			Vector(1.0f, -1.0f, -1.0f),
			Vector(0.0f, 1.0f, 0.0f));
	mesh[2] = Triangle(Vector(0.0f, 1.0f, 0.0f),
			Vector(1.0f, -1.0f, -1.0f),
			Vector(-1.0f, -1.0f, -1.0f),
			Vector(0.0f, 0.0f, 1.0f));
	mesh[3] = Triangle(Vector(0.0f, 1.0f, 0.0f),
			Vector(-1.0f, -1.0f, -1.0f),
			Vector(-1.0f, -1.0f, 1.0f),
			Vector(1.0f, 0.0f, 1.0f));

	modelManager.addModel(&mesh, std::string("ship"));
	modelManager.loadModels(std::string("ships.obj"));

	Ship* ship;
	ship = new Ship(5.0f, 1.0f, -20.0f);
	ship->load();
	objects.push_front(ship);
	ship = new Ship(-5.0f, -6.0f, -14.0f);
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

