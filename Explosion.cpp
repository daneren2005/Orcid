/* 
 * File:   Explosion.cpp
 * Author: scott
 * 
 * Created on January 13, 2011, 3:43 PM
 */

#include "Explosion.h"
#include <math.h>

Explosion::Explosion(float x, float y, float z)
{
	this->position = Vector(x, y, z);
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
	if(runningTime <= 0.05f)
	{
		float r = 2.0f;
		for(float x = -r; x <= r; x += .01f)
		{
			float y = sqrt(r * r - x * x);
			this->emitParticle(this->position, Vector(x, y, 0.0f), Vector(), .6f);
			this->emitParticle(this->position, Vector(x, -y, 0.0f), Vector(), .6f);
		}
	}
}

