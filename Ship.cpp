/*
 * File:   Ship.cpp
 * Author: scott
 *
 * Created on July 20, 2010, 3:50 PM
 */

#include "Ship.h"

#ifdef WIN32
	#include <windows.h>
#endif

Ship::Ship() : BaseObject()
{
}

Ship::Ship(float x, float y, float z) : BaseObject(x, y, z)
{

}

Ship::Ship(const Ship& orig)
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
	mesh = Mesh(4);
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
	
	/*this->shape->addTriangle(new Triangle(Vector(0.0f, 1.0f, 0.0f),
			Vector(-1.0f, -1.0f, 1.0f),
			Vector(1.0f, -1.0f, 1.0f),
			Vector(1.0f, 0.0f, 0.0f)));
	this->shape->addTriangle(new Triangle(Vector(0.0f, 1.0f, 0.0f),
			Vector(1.0f, -1.0f, 1.0f),
			Vector(1.0f, -1.0f, -1.0f),
			Vector(0.0f, 1.0f, 0.0f)));
	this->shape->addTriangle(new Triangle(Vector(0.0f, 1.0f, 0.0f),
			Vector(1.0f, -1.0f, -1.0f),
			Vector(-1.0f, -1.0f, -1.0f),
			Vector(0.0f, 0.0f, 1.0f)));
	this->shape->addTriangle(new Triangle(Vector(0.0f, 1.0f, 0.0f),
			Vector(-1.0f, -1.0f, -1.0f),
			Vector(-1.0f, -1.0f, 1.0f),
			Vector(1.0f, 0.0f, 1.0f)));*/
}

