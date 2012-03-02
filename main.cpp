/*
 * File:   main.cpp
 * Author: scott
 *
 * Created on July 13, 2010, 10:34 PM
 */

#include "skyfire.h"
#include "Galaxy.h"
#include "ShipCamera.h"

#ifdef WIN32
	int WINAPI WinMain(HINSTANCE program, HINSTANCE prevProgram, LPSTR args, int nCmdShow)
#endif
#ifdef __linux__
	int main(int argc,char** argv)
#endif
{
	Window win(1280, 720);

	Galaxy galaxy;
	galaxy.start();

	ShipCamera* camera = (ShipCamera*)galaxy.getCamera();
	Input* input = win.getInput();
	camera->setEventHandlers(input);
	win.setRenderer(camera);

	// Set program into infinite loop until window thread is stopped
	win.wait();

	exit(0);
}
