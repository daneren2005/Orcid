/* 
 * File:   ShipCamera.h
 * Author: scott
 *
 * Created on January 24, 2011, 6:01 PM
 */

#ifndef _SHIPCAMERA_H
#define	_SHIPCAMERA_H

#include "skyfire.h"
#include "Ship.h"

class ShipCamera : public FirstPersonCamera
{
public:
	ShipCamera();
	ShipCamera(const ShipCamera& orig);
	virtual ~ShipCamera();
	
	virtual void render();

	virtual void setEventHandlers(Input* input);

	void moveLeft(double interval);
	void moveRight(double interval);
	void moveUp(double interval);
	void moveDown(double interval);

	void rotateLeft(double interval);
	void rotateRight(double interval);
	void rotateUp(double interval);
	void rotateDown(double interval);

	void moveIn(double interval);
	void moveOut(double interval);

	void mouseMove(int x, int y);
	void mouseDown(double interval, int x, int y);
	void mouseClick(int x, int y);
private:
	Ship* selected;
};

#endif	/* _SHIPCAMERA_H */

