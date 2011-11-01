#ifndef _TEST_LIST_H
#define	_TEST_LIST_H

#include "BasicList.h"
#include "List.h"
#include <iostream>
#include <time.h>
#include <sys/time.h>
#include <list>

using namespace std;

void testBaseIterationSpeed()
{
	list<int> l;
	timeval start, donePushing, doneIterating;

	gettimeofday(&start, 0);
	for(int i = 0; i < 1000000; i++)
	{
		l.push_back(rand() % 1000000);
	}
	gettimeofday(&donePushing, 0);

	for(list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		
	}
	gettimeofday(&doneIterating, 0);

	double pushing = (donePushing.tv_sec - start.tv_sec) * 1000 + (donePushing.tv_usec - start.tv_usec) / 1000;
	double iterating = (doneIterating.tv_sec - donePushing.tv_sec) * 1000 + (doneIterating.tv_usec - donePushing.tv_usec) / 1000;

	cout << "Times for stl list" << endl;
	cout << "Time to push: " << pushing << endl;
	cout << "Time to iterator: " << iterating << endl << endl;
}

void testBasicIterationSpeed()
{
	BasicList<int> l;
	timeval start, donePushing, doneIterating;

	gettimeofday(&start, 0);
	for(int i = 0; i < 1000000; i++)
	{
		l.pushBack(rand() % 1000000);
	}
	gettimeofday(&donePushing, 0);

	for(BasicList<int>::Iterator it = l.begin(); !it; it++)
	{
		
	}
	gettimeofday(&doneIterating, 0);

	double pushing = (donePushing.tv_sec - start.tv_sec) * 1000 + (donePushing.tv_usec - start.tv_usec) / 1000;
	double iterating = (doneIterating.tv_sec - donePushing.tv_sec) * 1000 + (doneIterating.tv_usec - donePushing.tv_usec) / 1000;

	cout << "Times for BasicList" << endl;
	cout << "Time to push: " << pushing << endl;
	cout << "Time to iterator: " << iterating << endl << endl;
}


void testListIterationSpeed()
{
	List<int> l;
	timeval start, donePushing, doneIterating;

	gettimeofday(&start, 0);
	for(int i = 0; i < 1000000; i++)
	{
		l.pushBack(rand() % 1000000);
	}
	gettimeofday(&donePushing, 0);

	for(List<int>::Iterator it = l.begin(); !it; it++)
	{
		
	}
	gettimeofday(&doneIterating, 0);

	double pushing = (donePushing.tv_sec - start.tv_sec) * 1000 + (donePushing.tv_usec - start.tv_usec) / 1000;
	double iterating = (doneIterating.tv_sec - donePushing.tv_sec) * 1000 + (doneIterating.tv_usec - donePushing.tv_usec) / 1000;
	
	cout << "Times for List" << endl;
	cout << "Time to push: " << pushing << endl;
	cout << "Time to iterator: " << iterating << endl << endl;
}

void testListSpeed()
{
	testBaseIterationSpeed();
	testBasicIterationSpeed();
	testListIterationSpeed();
}

#endif
