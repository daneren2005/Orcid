/*
 * File:   Ship.cpp
 * Author: scott
 *
 * Created on July 20, 2010, 3:50 PM
 */

#include "Ship.h"
#include "ResourceManager.h"

#ifdef WIN32
	#include <windows.h>
#endif

Ship::Ship() : BaseObject()
{
	this->selected = false;
}

Ship::Ship(float x, float y, float z) : BaseObject(x, y, z)
{
	this->selected = false;
}

Ship::Ship(const Ship& orig) : BaseObject(orig)
{
	this->selected = orig.selected;
}

Ship::~Ship()
{
}

void Ship::update(double interval)
{
	// this->moveByDirection(0.0f, 0.0f, interval * 1.0f);

	// this->rotateBy(interval * 20.0f, 0.0f, 0.0f);
	// this->rotateBy(0.0f, interval * 360.0f, 0.0f);
	// this->rotateBy(0.0f, 0.0f, interval * 360.0f);
}

void Ship::draw()
{
	if(selected)
		this->getBoundingBox().draw();
	
	BaseObject::draw();
}

void Ship::load(DataFile::Object* unit, DataFile::Object* instance)
{
	model = resourceManager.getModel(unit->name);
	this->position[0] = instance->floats.search("x");
	this->position[1] = instance->floats.search("y");
	this->position[2] = instance->floats.search("z");
}

void Ship::select()
{
	selected = true;
}
void Ship::deselect()
{
	selected = false;
}
void Ship::switchSelect()
{
	if(selected)
		selected = false;
	else
		selected = true;
}

