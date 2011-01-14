/* 
 * File:   Explosion.cpp
 * Author: scott
 * 
 * Created on January 13, 2011, 3:43 PM
 */

#include "Explosion.h"

Explosion::Explosion()
{
}

Explosion::Explosion(const Explosion& orig)
{
}

Explosion::~Explosion()
{
}

void Explosion::update(double interval)
{
	this->emitParticles();

	Particle* ptr = this->particles.getPointer();
	for(int i = 0; i < this->particles.size(); i++)
	{
		ptr[i].position += ptr[i].speed;
		ptr[i].life += (float)interval;
		if(ptr[i].life >= ptr[i].totalLife)
		{
			ptr[i].fade = 1.0f;
		}
	}
}
void Explosion::draw()
{
	Particle* ptr = this->particles.getPointer();
	for(int i = 0; i < this->particles.size(); i++)
	{

	}
}
void Explosion::load()
{

}

void Explosion::emitParticles()
{
	Particle p;
	p.speed[0] = 1.0f;
	p.totalLife = 10.0f;
	particles.insert(p);
}

