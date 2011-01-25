/* 
 * File:   SolarSystem.cpp
 * Author: scott
 * 
 * Created on July 20, 2010, 3:50 PM
 */

#include "SolarSystem.h"
#include "Explosion.h"

SolarSystem::SolarSystem()
{
	// modelManager.addModel(&mesh, std::string("ship"));
	// modelManager.loadModels(std::string("data/ships.obj"));
	// modelManager.loadModels(std::string("data/teapot.obj"));
	// modelManager.loadModels(std::string("data/Daedalus.obj"));
	// modelManager.loadModels(std::string("data/Danube/danube.obj"));
	// modelManager.loadModels(std::string("data/ak47.obj"));

	/*Ship* ship;
	ship = new Ship(0.0f, 0.0f, 20.0f);
	ship->load();
	objects.push_back(ship);
	// ship = new Ship(0.0f, -6.0f, 20.0f);
	// ship->load();
	// objects.push_back(ship);
	ship = new Ship(5.0f, 1.0f, -60.0f);
	ship->load();
	objects.push_back(ship);*/

	/*Explosion* explosion = new Explosion();
	explosion->start();
	objects.push_back(explosion);*/

	objects.push_front(new AxisObject(0.0f, 0.0f, 0.0f));
}

SolarSystem::SolarSystem(const SolarSystem& orig)
{
}

SolarSystem::~SolarSystem()
{
}

