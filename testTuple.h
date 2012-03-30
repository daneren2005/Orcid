#ifndef _TEST_TUPLE_H
#define	_TEST_TUPLE_H

#include "Console.h"
#include "Tuple.h"
#include "Lock.h"

void testTuple()
{
	Tuple<int, char, Lock> t(5, 'c', Lock());
	console << "Size of <int, char, Lock>: " << t.size() << newline;
	console << "Front/next accessing: " << newline;
	console << t.front() <<  " " << t.next().front() << " " << t.next().next().front().isLocked() << newline;
	t.front() = 15;
	t.next().next().front().lock();
	console << "Front/next changing: " << newline;
	console << t.get<0>() << " " << t.get<1>() << " " << t.get<2>().isLocked() << newline;
	int& i = t.get<0>();
	i = 30000;
	char& c = t.get<1>();
	c = 'f';
	Lock lock = t.get<2>();
	lock.unlock();
	console << "Test = get<i>; test = ? changing: " << newline;
	console << t.get<0>() << " " << t.get<1>() << " " << t.get<2>().isLocked() << newline;
	t.get<0>() = 5000;
	t.get<1>() = 'b';
	t.get<2>().lock();
	console << "Get<i> = ? changing: " << newline;
	console << t.get<0>() << " " << t.get<1>() << " " << t.get<2>().isLocked() << newline;

	Tuple<int, char> t2(5, 'c');
	Tuple<int, char> t3;
	t3 = t2;
	console << "Testing assign: " << newline;
	console << t3.get<0>() << " " << t3.get<1>() << newline;
	Tuple<int, char> t4(4, 'c');
	Tuple<int, char> t5(5, 'd');
	Tuple<int, char> t6(8, 'f');

	console << newline << "Testing equalities: " << newline;
	console << (int)(t2 == t2) << newline;
	console << (int)(t2 == t3) << newline;
	console << (int)(t2 == t4) << newline;
	console << (int)(t2 == t5) << newline;
	console << (int)(t2 == t6) << newline;
	console << (int)(t3 != t4) << newline;
	console << (int)(t3 != t2) << newline;

	console << newline << "Testing comparisons: " << newline;
	console << (int)(t2 < t3) << " (0)" << newline;
	console << (int)(t2 < t6) << " (1)" << newline;
	console << (int)(t2 > t3) << " (0)" << newline;
	console << (int)(t2 > t4) << " (1)" << newline;
	console << (int)(t2 <= t3) << " (1)" << newline;
	console << (int)(t2 >= t3) << " (1)" << newline;
}

#endif