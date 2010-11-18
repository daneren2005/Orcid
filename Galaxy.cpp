/* 
 * File:   Galaxy.cpp
 * Author: scott
 * 
 * Created on July 20, 2010, 3:49 PM
 */

#include "Galaxy.h"

Galaxy::Galaxy() : Universe()
{
	
}

Galaxy::Galaxy(const Galaxy& orig)
{

}

Galaxy::~Galaxy()
{

}

void Galaxy::load()
{
	SolarSystem* system = new SolarSystem();
	this->addRegion(system);
	this->setActiveRegion(system);

	// BaseObject* ship = this->camera->getActiveRegion()->getFront();
	// this->camera->moveByDirection(0.0f, 0.0f, -40.0f);
	// this->camera->attachTo(ship);
}

