#ifndef _TEST_QUEUE_H
#define	_TEST_QUEUE_H

#include "Console.h"
#include "Queue.h"
#include "ThreadLoop.h"

void addQueue(ThreadLoop* thread)
{
	((Queue<int>*)(thread->getArg()))->insert(25);
}

void testQueue()
{
	Queue<int> queue;
	queue.insert(10);
	queue.insert(5);
	queue.insert(8);
	console << (long)queue.size() << " " << (long)queue.reserved() << newline;
	queue.insert(9);
	console << (long)queue.size() << " " << (long)queue.reserved() << newline;
	queue.insert(20);
	console << (long)queue.size() << " " << (long)queue.reserved() << newline;

	console << queue.remove() << " ";
	console << queue.remove() <<  " ";
	console << queue.remove() << " ";
	console << queue.remove() << newline;
	queue.insert(10);
	queue.insert(5);
	queue.insert(8);
	queue.insert(20);
	console << (long)queue.size() << " " << (long)queue.reserved() << newline;
	console << "10 exists (yes): " << queue.search(10) << newline;
	console << "234 exists (no): " << queue.search(234) << newline;

	Queue<int> queue2; // = queue;
	queue2 = queue;

	ThreadLoop thread;
	thread.setTicksPerSecond(1);
	thread.start(addQueue, (void*)&queue2);
	console << "started loop" << newline;
	while(1)
	{
		// Should add 1 every second forever
		console << queue2.removeWait() << newline;
	}
}

#endif
