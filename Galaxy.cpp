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
	SolarSystem* system = new SolarSystem((FirstPersonCamera*)this->camera);
	this->addRegion(system);
	this->setActiveRegion(system);
}

