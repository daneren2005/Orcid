/*
 * File:   main.cpp
 * Author: scott
 *
 * Created on July 13, 2010, 10:34 PM
 */

#include "skyfire.h"
#include "Galaxy.h"

#include <iostream>
// using namespace std;

#ifdef WIN32
	int WINAPI WinMain(HINSTANCE program, HINSTANCE prevProgram, LPSTR args, int nCmdShow)
#endif
#ifdef __linux__
	int main(int argc,char** argv)
#endif
{
	Window win(1280, 720);

	#ifdef WIN32
		win.start(program);
	#endif
	#ifdef __linux__
		win.start();
	#endif

	Thread thisThread(&win);
	thisThread.createContext();

	Galaxy galaxy;
	galaxy.load();
	win.setScene(galaxy.getCamera());
	galaxy.setInput(win.getInput());
	galaxy.start();

	// Set program into infinite loop until window thread is stopped
	win.wait();
	std::cout << "test" << std::endl;

	return(0);
}
