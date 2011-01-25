/*
 * File:   main.cpp
 * Author: scott
 *
 * Created on July 13, 2010, 10:34 PM
 */

#include "skyfire.h"
#include "Galaxy.h"
#include "ShipCamera.h"

#include <iostream>

#ifdef WIN32
	int WINAPI WinMain(HINSTANCE program, HINSTANCE prevProgram, LPSTR args, int nCmdShow)
#endif
#ifdef __linux__
	int main(int argc,char** argv)
#endif
{
	/*String str1 = ",,apple,blitz,,,mtez,,,,replace,";
	String str2 = ",,";
	String str3 = "-";
	String str4 = str1.replace(",", "..");
	std::cout << str4.cStr() << std::endl;*/

	/*String str1 = "test";
	String str3 = " - ";
	String str2 = str1.insert(3, " - ");
	std::cout << str2.cStr() << std::endl;*/

	Window win(1280, 720);

	#ifdef WIN32
		win.start(program);
	#endif
	#ifdef __linux__
		win.start();
	#endif

	Galaxy galaxy;
	galaxy.load();

	ShipCamera* camera = (ShipCamera*)galaxy.getCamera();
	Input* input = win.getInput();
	camera->setEventHandlers(input);

	win.setScene(camera);
	galaxy.setInput(input);
	galaxy.start();

	// Set program into infinite loop until window thread is stopped
	win.wait();

	return(0);
}
