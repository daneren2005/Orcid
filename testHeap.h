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

#ifndef _TEST_PRIORITY_QUEUE_H
#define	_TEST_PRIORITY_QUEUE_H

#include "Timer.h"
#include "PriorityQueue.h"
#include <queue>

#include <iostream>
using namespace std;

struct compare
{
	bool operator()(const int& l, const int& r)
	{
		return l > r;
	}
};

void testPriorityQueue()
{
	cout << "Start heap" << endl;
	PriorityQueue<int> heap;
	heap.insert(5);
	heap.insert(10);
	heap.insert(2);
	heap.insert(8);
	heap.insert(4);
	heap.insert(6);
	heap.insert(1);

	cout << "Iterate heap:" << endl;
	for(PriorityQueue<int>::Iterator it = heap.begin(); !it; it++)
	{
		cout << it.value() << endl;
	}
	cout << endl;

	PriorityQueue<int> heap3 = heap;

	cout << "Iterate copied heap:" << endl;
	for(PriorityQueue<int>::Iterator it = heap3.begin(); !it; it++)
	{
		cout << it.value() << endl;
	}
	cout << endl;

	cout << "Remove all values from heap:" << endl;
	while(!heap.empty())
	{
		cout << heap.remove() << " -";
		for(PriorityQueue<int>::Iterator it = heap.begin(); !it; it++)
		{
			cout << " " << it.value();
		}
		cout << endl;
	}
	cout << endl;

	cout << "Iterate empty heap:" << endl;
	for(PriorityQueue<int>::Iterator it = heap.begin(); !it; it++)
	{
		cout << it.value() << endl;
	}
	cout << endl;


	PriorityQueue<int> heap2 = heap;
	cout << "Iterate empty copied heap:" << endl;
	for(PriorityQueue<int>::Iterator it = heap2.begin(); !it; it++)
	{
		cout << it.value() << endl;
	}
	cout << endl;

	heap.insert(5);
	heap.insert(1);
	heap.insert(3);
	heap.insert(4);
	heap.remove();
	heap.insert(2);

	cout << "Done heap" << endl << endl;
}

void testPriorityQueueAccuracy()
{
	PriorityQueue<int> heap;
	priority_queue<int, vector<int>, compare> pq;

	cout << "Reporting all heap errors:" << endl;
	for(int i = 0; i < 100000; i++)
	{
		int value = rand() % 1000000;
		heap.insert(value);
		pq.push(value);

		if(heap.peek() != pq.top())
		{
			cout << "Different! " << heap.peek() << " " << pq.top() << endl;
		}
	}

	while(!heap.empty())
	{
		int val1 = heap.remove();
		int val2 = pq.top();
		pq.pop();
		if(val1 != val2)
		{
			cout << "Different! " << val1 <<  " " << val2 << endl;
		}
	}
	cout << "Done reporting all heap errors" << endl;
}

void testSTDPriorityQueueSpeed()
{
	priority_queue<int, vector<int>, compare> heap;
	Timer t;
	t.start();

	for(int i = 0; i < 1000000; i++)
	{
		heap.push(rand() % 100000000);
	}
	double pushing = t.elapsedTime();

	while(!heap.empty())
	{
		heap.pop();
	}
	double popping = t.elapsedTime();
	
	cout << "Times for STL PriorityQueue" << endl;
	cout << "Time to push: " << pushing << endl;
	cout << "Time to get all: " << popping << endl << endl;
}

void testBinaryPriorityQueueSpeed()
{
	PriorityQueue<int> heap;
	Timer t;
	t.start();

	for(int i = 0; i < 1000000; i++)
	{
		heap.insert(rand() % 1000000);
	}
	double pushing = t.elapsedTime();

	while(!heap.empty())
	{
		heap.remove();
	}
	double popping = t.elapsedTime();
	
	cout << "Times for PriorityQueue" << endl;
	cout << "Time to push: " << pushing << endl;
	cout << "Time to get all: " << popping << endl << endl;
}

void testPriorityQueueSpeed()
{
	testBinaryPriorityQueueSpeed();
	testSTDPriorityQueueSpeed();
}

#endif
