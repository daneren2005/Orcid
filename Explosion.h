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

	virtual void update(double interval);
	virtual void draw();
	virtual void load();
private:
	virtual void emitParticles();
};

#endif	/* _EXPLOSION_H */

