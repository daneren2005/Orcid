#ifndef _TEST_TS_LIST_H
#define	_TEST_TS_LIST_H

#include "ThreadLoop.h"
#include "List.h"
#include "Console.h"

void pushFrontList(ThreadLoop* thread)
{
	List<int>* list = thread->getArg();
	list->pushFront(rand() % 1000000);
}
void pushBackList(ThreadLoop* thread)
{
	List<int>* list = thread->getArg();
	list->pushBack(rand() % 1000000);
}
void popFrontList(ThreadLoop* thread)
{
	List<int>* list = thread->getArg();
	list->popFront();
}
void popBackList(ThreadLoop* thread)
{
	List<int>* list = thread->getArg();
	list->popBack();
}
void countList(ThreadLoop* thread)
{
	List<int>* list = thread->getArg();
	console << list->size() << newline;
}

void testListThreadSafety()
{
	List<int>* list = new List<int>();

	ThreadLoop i1, i2, i3, i4, i5, i6, i7, i8, r1, r2, r3, r4;
	i1.start(pushFrontList, list);
	i2.start(pushBackList, list);
	r1.start(popFrontList, list);
	r2.start(popBackList, list);
	r3.start(popFrontList, list);

	ThreadLoop t;
	t.start(countList, list);
	t.setTicksPerSecond(1);
	t.waitFor();
}

#endif
