/*
 * File:   Ship.cpp
 * Author: scott
 *
 * Created on July 20, 2010, 3:50 PM
 */

#include "Ship.h"
#include "ModelManager.h"

#ifdef WIN32
	#include <windows.h>
#endif

Ship::Ship() : BaseObject()
{

}

Ship::Ship(float x, float y, float z) : BaseObject(x, y, z)
{
	
}

Ship::Ship(const Ship& orig) : BaseObject(orig)
{
	
}

Ship::~Ship()
{
}

void Ship::update(double interval)
{
	// this->rotateBy(interval * 360.0f, 0.0f, 0.0f);
	// this->rotateBy(0.0f, interval * 360.0f, 0.0f);
	// this->rotateBy(0.0f, 0.0f, interval * 360.0f);
}

void Ship::load()
{
	// this->model = modelManager.getModel(std::string("daedalus"));
	this->model = modelManager.getModel(std::string("danube"));
	// this->model = modelManager.getModel(std::string("AK47"));
}

