/* 
 * File:   Galaxy.h
 * Author: scott
 *
 * Created on July 20, 2010, 3:49 PM
 */

#ifndef _GALAXY_H
#define	_GALAXY_H

#include "skyfire.h"
#include "SolarSystem.h"

class Galaxy : public Universe
{
public:
	Galaxy();
	Galaxy(const Galaxy& orig);
	virtual ~Galaxy();

	virtual void addRegion(Region* region);
private:
	DataFile* units;
};

#endif	/* _GALAXY_H */

