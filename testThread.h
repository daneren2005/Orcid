#ifndef _TEST_THREAD_H
#define	_TEST_THREAD_H

#include "ThreadManager.h"
#include "Thread.h"

void nothing(Thread*)
{

}

void SampleThread(Thread* arg)
{
	console << "Ticks per second: " << arg->getTicksPerSecond() << newline;
}
void sampleJob(GenericType arg)
{
	Sleep(rand() % 20 * 100);
	console << "Job Done" << newline;
	*((int*)arg) = *((int*)arg) + 1;
}

void testThread()
{
	Thread thread;
	thread.start(SampleThread, 5);
	// thread.setTicksPerSecond(10);
	thread.setTimeBetweenTicks(2);
	
	Thread main;
	main.setTicksPerSecond(1);
	main.startMain(nothing, 0);
}

void testThreadManager()
{
	ThreadManager manager;
	manager.setWorkers(5);
	int* j = new int(0);

	for(int i = 0; i < 10; i++)
	{
		manager.addJob(sampleJob, j);
	}

	manager.waitTillDone();
	console << "Finished jobs: " << *j << newline;
}

#endif
