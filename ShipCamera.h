/* 
 * File:   ShipCamera.h
 * Author: scott
 *
 * Created on January 24, 2011, 6:01 PM
 */

#ifndef _SHIPCAMERA_H
#define	_SHIPCAMERA_H

#include "skyfire.h"

class ShipCamera : public FirstPersonCamera
{
public:
	ShipCamera();
	ShipCamera(const ShipCamera& orig);
	virtual ~ShipCamera();

	void setEventHandlers(Input* input);

	static void* moveLeft(void* args, double interval);
	static void* moveRight(void* args, double interval);
	static void* moveUp(void* args, double interval);
	static void* moveDown(void* args, double interval);

	static void* rotateLeft(void* args, double interval);
	static void* rotateRight(void* args, double interval);
	static void* rotateUp(void* args, double interval);
	static void* rotateDown(void* args, double interval);

	static void* moveIn(void* args, double interval);
	static void* moveOut(void* args, double interval);

	static void* mouseMove(void* args, int x, int y);
	static void* mouseDown(void* args, double interval, int x, int y);
	static void* mouseClick(void* args, int x, int y);
private:

};

#endif	/* _SHIPCAMERA_H */

