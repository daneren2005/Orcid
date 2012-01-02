/* 
 * File:   Galaxy.cpp
 * Author: scott
 * 
 * Created on July 20, 2010, 3:49 PM
 */

#include "Galaxy.h"
#include "ShipCamera.h"

Galaxy::Galaxy() : Universe()
{
	units = 0x0;
	this->camera = new ShipCamera();
}

Galaxy::Galaxy(const Galaxy& orig)
{

}

Galaxy::~Galaxy()
{

}

void Galaxy::load()
{
	units = new DataFile(String("data/units.dat"));
	units->load();
	DataFile::Object* obj = units->getObject("Ship1");
	resourceManager.loadModel(obj->strings.search("model"), obj->name);
	
	DataFile world(String("data/sol_system.dat"));
	world.load();
	
	SolarSystem* system = new SolarSystem((FirstPersonCamera*)this->camera);
	this->addRegion(system);
	system->load(world);
	this->setActiveRegion(system);
}

void Galaxy::addRegion(Region* region)
{
	((SolarSystem*)region)->universe = this;
	((SolarSystem*)region)->units = units;
	this->regions.pushFront(region);
}

