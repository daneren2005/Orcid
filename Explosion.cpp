/* 
 * File:   Explosion.cpp
 * Author: scott
 * 
 * Created on January 13, 2011, 3:43 PM
 */

#include "Explosion.h"

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
	if(runningTime <= 1.0)
	{
		this->emitParticle(1.0f, 0.0f, 0.0f);
		this->emitParticle(-1.0f, 0.0f, 0.0f);
		this->emitParticle(0.0f, .6f, 0.0f);
		this->emitParticle(0.0f, -.6f, 0.0f);

		this->emitParticle(1.0f, .6f, 0.0f);
		this->emitParticle(-1.0f, .6f, 0.0f);
		this->emitParticle(1.0f, -.6f, 0.0f);
		this->emitParticle(-1.0f, -.6f, 0.0f);
	}
}

void Explosion::emitParticle(float x, float y, float z)
{
	Particle p;
	p.position[0] = 5.0f;
	p.position[1] = 1.0f;
	p.position[2] = -10.0f;
	p.speed[0] = x;
	p.speed[1] = y;
	p.speed[2] = z;
	p.life = .6f;
	p.fade = 0.1f;
	particles.insert(p);
}

