#ifndef _TEST_MAP_H
#define	_TEST_MAP_H

#include <iostream>
#include "Map.h"
#include <map>
#include "Timer.h"

using namespace std;

void testMapSpeed()
{
	Map<int, int> m;
	map<int, int> stl;

	Timer t;

	t.start();
	for(int i = 0; i < 1000000; i++)
	{
		int num = rand() % 1000000;
		m.insert(num, num);
	}
	console << "Map insert time: " << t.elapsedTime() << newline;

	t.reset();
	for(Map<int,int>::Iterator it = m.begin(); !it; it++)
	{

	}
	console << "Map iteration time: " << t.elapsedTime() << newline;

	t.reset();
	for(int i = 0; i < 1000000; i++)
	{
		int num = rand() % 1000000;
		stl.insert(pair<int, int>(num, num));
	}
	console << "STL map insert time: " << t.elapsedTime() << newline;

	t.reset();
	for(map<int,int>::iterator it = stl.begin(); it != stl.end(); it++)
	{

	}
	console << "STL map iteration time: " << t.elapsedTime() << newline;
}

void testMap()
{
	Map<int, int> m;
	map<int, int> stl;

	for(int i = 0; i < 10000; i++)
	{
		int num = rand() % 1000000;
		m.insert(num, num);
		stl.insert(pair<int, int>(num, num));

		// Do this check at each iteration
		long i = 0;
		long j = 0;
		map<int,int>::iterator it2 = stl.begin();
		for(Map<int,int>::Iterator it = m.begin(); !it; it++, it2++)
		{
			if(it.key() != (*it2).first)
				console << it.key() << " != " << (*it2).first << newline;
	
			i++; j++;
		}
	
		if(i != j)
			console << "Iterated different number of elements: " << i << " " << j << newline;
	
		if(m.size() != stl.size())
			console << "Different size: " << (long)m.size() << " " << (long)stl.size() << newline;
	}
}

#endif
