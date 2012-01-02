/* 
 * File:   Ship.h
 * Author: scott
 *
 * Created on July 20, 2010, 3:50 PM
 */

#ifndef _SHIP_H
#define	_SHIP_H

#include "skyfire.h"

class Ship : public BaseObject
{
public:
	Ship();
	Ship(float x, float y, float z);
	Ship(const Ship& orig);
	virtual ~Ship();

	virtual void update(double interval);

	virtual void load(DataFile::Object* unit, DataFile::Object* instance);
private:

};

#endif	/* _SHIP_H */

