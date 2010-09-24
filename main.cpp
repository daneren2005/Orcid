/* 
 * File:   main.cpp
 * Author: scott
 *
 * Created on July 13, 2010, 10:34 PM
 */

#include "skyfire.h"
#include "Galaxy.h"

// #include <iostream>
// using namespace std;

Input* setupInput()
{
	return new Input();
}


#ifdef WIN32
	int WINAPI WinMain(HINSTANCE program, HINSTANCE prevProgram, LPSTR args, int nCmdShow)
#endif
#ifdef __linux__
	int main(int argc,char** argv)
#endif
{
	Application app(program);

	Input* input = setupInput();

	Window win(1280, 720);
	win.start(program);
	win.setInput(input);

	Galaxy galaxy;
	galaxy.load();
	win.setScene(galaxy.getCamera());
	galaxy.start();
	galaxy.setInput(input);

	win.wait();

	return(0);
}