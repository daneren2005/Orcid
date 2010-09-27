/* 
 * File:   Ship.cpp
 * Author: scott
 * 
 * Created on July 20, 2010, 3:50 PM
 */

#include "Ship.h"

#include <windows.h>

Ship::Ship() : BaseObject()
{
}

Ship::Ship(float x, float y, float z) : BaseObject(x, y, z)
{

}

Ship::Ship(const Ship& orig)
{
}

Ship::~Ship()
{
}

void Ship::update(double interval)
{
	// this->rotateByReference(interval * 360.0f, 0.0f, 0.0f);
}

void Ship::load()
{
	this->displayList = glGenLists(1);

	glNewList(this->displayList, GL_COMPILE_AND_EXECUTE);
		glBegin(GL_TRIANGLES);
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 1.0f, 0.0f);
			glVertex3f(-1.0f, -1.0f, 1.0f);
			glVertex3f(1.0f, -1.0f, 1.0f);

			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3f(0.0f, 1.0f, 0.0f);
			glVertex3f(1.0f, -1.0f, 1.0f);
			glVertex3f(1.0f, -1.0f, -1.0f);

			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex3f(0.0f, 1.0f, 0.0f);
			glVertex3f(1.0f, -1.0f, -1.0f);
			glVertex3f(-1.0f, -1.0f, -1.0f);

			glColor3f(1.0f, 0.0f, 1.0f);
			glVertex3f(0.0f, 1.0f, 0.0f);
			glVertex3f(-1.0f, -1.0f, -1.0f);
			glVertex3f(-1.0f, -1.0f, 1.0f);
		glEnd();
	glEndList();

	if(!glIsList(this->displayList))
	{
		MessageBox(NULL, TEXT("No list"), NULL, NULL);
	}
}

