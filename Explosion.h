/* 
 * File:   Explosion.h
 * Author: scott
 *
 * Created on January 13, 2011, 3:43 PM
 */

#ifndef _EXPLOSION_H
#define	_EXPLOSION_H

#include "skyfire.h"

class Explosion : public ParticleEmitter
{
public:
	Explosion();
	Explosion(const Explosion& orig);
	virtual ~Explosion();

	virtual void load();
private:
	double runningTime;

	virtual void emitParticles(double interval);
	virtual void emitParticle(float x, float y, float z);
};

#endif	/* _EXPLOSION_H */

