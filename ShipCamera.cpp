/* 
 * File:   ShipCamera.cpp
 * Author: scott
 * 
 * Created on January 24, 2011, 6:01 PM
 */

#include "ShipCamera.h"
#include "Explosion.h"

ShipCamera::ShipCamera() : Camera()
{
}

ShipCamera::ShipCamera(const ShipCamera& orig) : Camera(orig)
{
}

ShipCamera::~ShipCamera()
{
}

void ShipCamera::setEventHandlers(Input* input)
{
	input->setKeyDownEventHandler(KEY_LEFT, ShipCamera::moveLeft, this);
	input->setKeyDownEventHandler(KEY_RIGHT, ShipCamera::moveRight, this);
	input->setKeyDownEventHandler(KEY_DOWN, ShipCamera::moveDown, this);
	input->setKeyDownEventHandler(KEY_UP, ShipCamera::moveUp, this);
	// TODO: doesn't work if its here
	// input->setKeyDownEventHandler(KEY_DOWN, ShipCamera::moveDown, this);

	input->setKeyDownEventHandler(KEY_PAGEUP, ShipCamera::moveIn, this);
	input->setKeyDownEventHandler(KEY_PAGEDOWN, ShipCamera::moveOut, this);

	input->setKeyDownEventHandler(KEY_A, ShipCamera::rotateLeft, this);
	input->setKeyDownEventHandler(KEY_D, ShipCamera::rotateRight, this);
	input->setKeyDownEventHandler(KEY_W, ShipCamera::rotateUp, this);
	input->setKeyDownEventHandler(KEY_S, ShipCamera::rotateDown, this);

	input->setMousePressEventHandler(BUTTON_LEFT, ShipCamera::mouseClick, this);
	// input->setMouseDownEventHandler(BUTTON_LEFT, ShipCamera::mouseDown, this);
	// this->input->setMouseMoveEventHandler(ShipCamera::mouseMove, this);
}

void* ShipCamera::moveLeft(void* args, double interval)
{
	// TODO: should ahve direct access to camera
	ShipCamera* camera = (ShipCamera*)args;
	camera->moveByDirection(-interval * 10, 0.0f, 0.0f);

	return NULL;
}
void* ShipCamera::moveRight(void* args, double interval)
{
	ShipCamera* camera = (ShipCamera*)args;
	camera->moveByDirection(interval * 10, 0.0f, 0.0f);

	return NULL;
}
void* ShipCamera::moveUp(void* args, double interval)
{
	ShipCamera* camera = (ShipCamera*)args;
	camera->moveByDirection(0.0f, interval * 10, 0.0f);

	return NULL;
}
void* ShipCamera::moveDown(void* args, double interval)
{
	ShipCamera* camera = (ShipCamera*)args;
	camera->moveByDirection(0.0f, -interval * 10, 0.0f);

	return NULL;
}

void* ShipCamera::rotateLeft(void* args, double interval)
{
	ShipCamera* camera = (ShipCamera*)args;
	camera->rotateBy(-interval * 100.0f, 0.0f, 0.0f);

	return NULL;
}
void* ShipCamera::rotateRight(void* args, double interval)
{
	ShipCamera* camera = (ShipCamera*)args;
	camera->rotateBy(interval * 100.0f, 0.0f, 0.0f);

	return NULL;
}
void* ShipCamera::rotateUp(void* args, double interval)
{
	ShipCamera* camera = (ShipCamera*)args;
	camera->rotateBy(0.0f, interval * 100.0f, 0.0f);

	return NULL;
}
void* ShipCamera::rotateDown(void* args, double interval)
{
	ShipCamera* camera = (ShipCamera*)args;
	camera->rotateBy(0.0f, -interval * 100.0f, 0.0f);

	return NULL;
}

void* ShipCamera::moveIn(void* args, double interval)
{
	ShipCamera* camera = (ShipCamera*)args;
	camera->moveByDirection(0.0f, 0.0f, -interval * 10);

	return NULL;
}
void* ShipCamera::moveOut(void* args, double interval)
{
	ShipCamera* camera = (ShipCamera*)args;
	camera->moveByDirection(0.0f, 0.0f, interval * 10);

	return NULL;
}

void* ShipCamera::mouseMove(void* args, int x, int y)
{
	ShipCamera* camera = (ShipCamera*)args;
	// console << x << " " << y << newline;

	return NULL;
}
void* ShipCamera::mouseDown(void* args, double interval, int x, int y)
{
	ShipCamera* camera = (ShipCamera*)args;
	console << x << " " << y << " for " << interval << newline;

	return NULL;
}
void* ShipCamera::mouseClick(void* args, int x, int y)
{
	ShipCamera* camera = (ShipCamera*)args;

	/*Explosion* explosion = new Explosion(x / 200.0f - 6.0f, 1.0f - y / 200.0f, -10.0f);
	explosion->start();
	camera->activeRegion->insertObject(explosion);*/

	BaseObject* object = camera->getObjectAt(x, y);
	if(object != 0x0)
	{
		Explosion* explosion = new Explosion(object->getPosition()[0], object->getPosition()[1], -10.0f);
		explosion->start();
		camera->activeRegion->insertObject(explosion);
		// console << object->objectId() << newline;
	}

	// console << x << " " << y << newline;

	return NULL;
}

