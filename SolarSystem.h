/* 
 * File:   SolarSystem.h
 * Author: scott
 *
 * Created on July 20, 2010, 3:50 PM
 */

#ifndef _SOLARSYSTEM_H
#define	_SOLARSYSTEM_H

#include "skyfire.h"
#include "Ship.h"

class SolarSystem : public Region
{
public:
	SolarSystem();
	SolarSystem(const SolarSystem& orig);
	virtual ~SolarSystem();
private:

};

#endif	/* _SOLARSYSTEM_H */

