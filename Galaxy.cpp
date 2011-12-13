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
	
	SolarSystem* system = new SolarSystem((FirstPersonCamera*)this->camera);
	this->addRegion(system);
	this->setActiveRegion(system);
}

