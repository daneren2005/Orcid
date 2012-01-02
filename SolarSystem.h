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

class Galaxy;

class SolarSystem : public Region
{
public:
	SolarSystem(FirstPersonCamera* camera);
	SolarSystem(const SolarSystem& orig);
	virtual ~SolarSystem();
	
	virtual void load();
	virtual void load(const DataFile& world);
	
	friend class Galaxy;
protected:
	DataFile* units;
};

#endif	/* _SOLARSYSTEM_H */

