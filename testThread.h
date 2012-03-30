#ifndef _TEST_THREAD_H
#define	_TEST_THREAD_H

#include "ThreadManager.h"
#include "ThreadLoop.h"
#include "Thread.h"

void nothing(ThreadLoop*)
{

}

void SampleThreadLoop(ThreadLoop* arg)
{
	console << "Ticks per second: " << arg->getTicksPerSecond() << newline;
}
void sampleJob(GenericType arg)
{
	usleep(rand() % 20 * 100000);
	console << "Job Done" << newline;
	*((int*)arg) = *((int*)arg) + 1;
}

void sampleShortThread()
{
	for(int i = 0; i < 3; i++)
	{
		console << i << newline;
		usleep(rand() % 20 * 100000);
	}
}
void sampleArgsThread(int i, int j, double k, char c)
{
	usleep(rand() % 20 * 200000);
	console << i << " " << j << " " << k << " " << c << newline;
}

void testThread2(Thread& thread)
{
	// Test copy/deleting while thread still running
	Thread thread2 = thread;
	Thread thread3;
	thread3 = thread;
}
void testThread()
{
	Thread thread(sampleShortThread);
	testThread2(thread);
	thread.join();
}

void testThreadLoop()
{
	ThreadLoop thread;
	thread.start(SampleThreadLoop, 5);
	// thread.setTicksPerSecond(10);
	thread.setTimeBetweenTicks(2);
	
	ThreadLoop main;
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
