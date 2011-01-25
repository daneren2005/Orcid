/* 
 * File:   Explosion.cpp
 * Author: scott
 * 
 * Created on January 13, 2011, 3:43 PM
 */

#include "Explosion.h"
#include <math.h>

Explosion::Explosion()
{
	runningTime = 0.0;
}

Explosion::Explosion(const Explosion& orig)
{
}

Explosion::~Explosion()
{
}

void Explosion::load()
{
	
}

void Explosion::emitParticles(double interval)
{
	runningTime += interval;
	if(runningTime <= 0.01)
	{
		float r = 2.0f;
		for(float x = -r; x <= r; x += .01f)
		{
			float y = sqrt(r * r - x * x);
			this->emitParticle(Vector(0.0f, 1.0f, -10.0f), Vector(x, y, 0.0f), Vector(), .6f);
			this->emitParticle(Vector(0.0f, 1.0f, -10.0f), Vector(x, -y, 0.0f), Vector(), .6f);
		}
	}
}

