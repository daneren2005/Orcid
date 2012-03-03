/* 
 * File:   ShipCamera.cpp
 * Author: scott
 * 
 * Created on January 24, 2011, 6:01 PM
 */

#include "ShipCamera.h"
#include "Ship.h"
#include "Explosion.h"

ShipCamera::ShipCamera() : FirstPersonCamera()
{
	this->selected = 0x0;
}

ShipCamera::ShipCamera(const ShipCamera& orig) : FirstPersonCamera(orig)
{
	this->selected = orig.selected;
}

ShipCamera::~ShipCamera()
{
}

void ShipCamera::render()
{
	if(selected != 0x0)
		selected->getBoundingBox().draw();
	
	FirstPersonCamera::render();
}

void ShipCamera::setEventHandlers(Input* input)
{
	input->setKeyDownEventHandler(KEY_LEFT, (Function<void, double>)(MemberFunction<ShipCamera, void, double>(&ShipCamera::moveLeft, this)));
	input->setKeyDownEventHandler(KEY_RIGHT, (Function<void, double>)MemberFunction<ShipCamera, void, double>(&ShipCamera::moveRight, this));
	input->setKeyDownEventHandler(KEY_DOWN, (Function<void, double>)MemberFunction<ShipCamera, void, double>(&ShipCamera::moveDown, this));
	input->setKeyDownEventHandler(KEY_UP, (Function<void, double>)MemberFunction<ShipCamera, void, double>(&ShipCamera::moveUp, this));
	// TODO: doesn't work if its here
	// input->setKeyDownEventHandler(KEY_DOWN, ShipCamera::moveDown, this);

	input->setKeyDownEventHandler(KEY_PAGEUP, (Function<void, double>)MemberFunction<ShipCamera, void, double>(&ShipCamera::moveIn, this));
	input->setKeyDownEventHandler(KEY_PAGEDOWN, (Function<void, double>)MemberFunction<ShipCamera, void, double>(&ShipCamera::moveOut, this));

	input->setKeyDownEventHandler(KEY_A, (Function<void, double>)MemberFunction<ShipCamera, void, double>(&ShipCamera::rotateLeft, this));
	input->setKeyDownEventHandler(KEY_D, (Function<void, double>)MemberFunction<ShipCamera, void, double>(&ShipCamera::rotateRight, this));
	input->setKeyDownEventHandler(KEY_W, (Function<void, double>)MemberFunction<ShipCamera, void, double>(&ShipCamera::rotateUp, this));
	input->setKeyDownEventHandler(KEY_S, (Function<void, double>)MemberFunction<ShipCamera, void, double>(&ShipCamera::rotateDown, this));

	input->setMousePressEventHandler(BUTTON_LEFT, (Function<void, int, int>)MemberFunction<ShipCamera, void, int, int>(&ShipCamera::mouseClick, this));
	// input->setMouseDownEventHandler(BUTTON_LEFT, ShipCamera::mouseDown, this);
	// this->input->setMouseMoveEventHandler(ShipCamera::mouseMove, this);
}

void ShipCamera::moveLeft(double interval)
{
	moveByDirection(-interval * 10, 0.0f, 0.0f);
}
void ShipCamera::moveRight(double interval)
{
	moveByDirection(interval * 10, 0.0f, 0.0f);
}
void ShipCamera::moveUp(double interval)
{
	moveByDirection(0.0f, interval * 10, 0.0f);
}
void ShipCamera::moveDown(double interval)
{
	moveByDirection(0.0f, -interval * 10, 0.0f);
}

void ShipCamera::rotateLeft(double interval)
{
	rotateBy(-interval * 100.0f, 0.0f, 0.0f);

}
void ShipCamera::rotateRight(double interval)
{
	rotateBy(interval * 100.0f, 0.0f, 0.0f);
}
void ShipCamera::rotateUp(double interval)
{
	rotateBy(0.0f, interval * 100.0f, 0.0f);
}
void ShipCamera::rotateDown(double interval)
{
	rotateBy(0.0f, -interval * 100.0f, 0.0f);
}

void ShipCamera::moveIn(double interval)
{
	moveByDirection(0.0f, 0.0f, -interval * 10);
}
void ShipCamera::moveOut(double interval)
{
	moveByDirection(0.0f, 0.0f, interval * 10);
}

void ShipCamera::mouseMove(int x, int y)
{
	
}
void ShipCamera::mouseDown(double interval, int x, int y)
{
	console << x << " " << y << " for " << interval << newline;
}
void ShipCamera::mouseClick(int x, int y)
{
	Ship* object = (Ship*)getObjectAt(x, y);
	if(object != 0x0)
	{
		selected = object;
		object->switchSelect();
	}
	else
	{
		selected = 0x0;
	}
}

