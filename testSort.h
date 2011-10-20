/*
	This file is part of Skyfire.

    Skyfire is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Skyfire is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Skyfire.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _TEST_SORT_H_
#define	_TEST_SORT_H_

#include "Array.h"
#include "List.h"
#include "Console.h"
#include <list>
#include "Timer.h"

bool intCompare(int a, int b)
{
	return a > b;
}

void testArraySort()
{
	Array<int> array;
	for(uint i = 0; i < 100; i++)
	{
		array.insert(rand() % 10000);
	}

	array.sort();

	for(uint i = 0; i < array.size(); i++)
	{
		console << array[i] << newline;
	}
	console << newline;

	array.sort(intCompare);
	for(uint i = 0; i < array.size(); i++)
	{
		console << array[i] << newline;
	}
}

void testListSort()
{
	List<int> list;
	for(uint i = 0; i < 20; i++)
	{
		list.pushBack(rand() % 10000);
	}
	
	for(List<int>::Iterator it = list.begin(); !it; it++)
	{
		console << it.value() << newline;
	}
	console << newline;
	
	list.sort();
	
	for(List<int>::Iterator it = list.begin(); !it; it++)
	{
		console << it.value() << newline;
	}
}

void testSortAccuracy()
{
	console << "Testing sorts runtime:" << newline;
	
	List<int> list;
	Array<int> array;
	std::list<int> base;
	
	for(uint i = 0; i < 1000000; i++)
	{
		int num = rand() % 1000000;
		list.pushBack(num);
		array.insert(num);
		base.push_back(num);
	}
	
	Timer timer;
	timer.start();
	
	list.sort();
	console << "List runtime: " << timer.elapsedTime() << newline;
	
	array.sort();
	console << "Array runtime: " << timer.elapsedTime() << newline;
	
	base.sort();
	console << "STL List runtime: " << timer.elapsedTime() << newline;
	
	console << newline << "Testing sorts accuracy" << newline;
	List<int>::Iterator listIt = list.begin();
	std::list<int>::iterator baseIt = base.begin();
	for(uint i = 0; i < array.size(); i++)
	{
		if(array[i] != *baseIt)
			console << "Array different value!" << newline;
		if(listIt.value() != *baseIt)
			console << "List different value!" << newline;
		
		listIt++;
		baseIt++;
	}
	console << "Done testing sorts accuracy" << newline;
}

#endif