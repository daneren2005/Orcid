#ifndef _TESTLOCK_H
#define	_TESTLOCK_H

#include "Lock.h"
#include "SharedLock.h"
#include "Condition.h"
#include <iostream>

using namespace std;

void testLock()
{
	Lock lock;

	cout << lock.isLocked() << endl;
	cout << lock.tryLock() << endl;
	cout << lock.isLocked() << endl;
	cout << lock.tryLock() << endl << endl;

	Lock lock2 = lock;
	cout << lock2.isLocked() << endl;
	cout << lock2.tryLock() << endl;
	cout << (lock == lock2) << endl;
	cout << (lock2 != lock) << endl;
}

void testSharedLock()
{
	SharedLock lock;

	cout << lock.isLocked() << endl;
	cout << lock.isWriteLocked() << endl;
	cout << lock.tryReadLock() << endl;
	cout << lock.isWriteLocked() << endl;
	cout << lock.tryWriteLock() << endl << endl;

	SharedLock lock2 = lock;
	cout << lock2.isWriteLocked() << endl;
	cout << lock2.tryWriteLock() << endl;
	cout << (lock == lock2) << endl;
	cout << (lock2 != lock) << endl;
	cout << lock2.tryReadLock() << endl << endl;

	cout << lock.isLocked() << endl;
	cout << lock2.isReadLocked() << endl;
	cout << lock.isReadLocked() << endl;
	lock.unlock();
	lock.unlock();
	cout << lock.isReadLocked() << endl;
	cout << lock2.isReadLocked() << endl << endl;

	cout << lock.tryWriteLock() << endl;
	cout << lock2.isWriteLocked() << endl;
	cout << lock2.tryReadLock() << endl;
	cout << lock.isReadLocked() << endl;
	cout << lock.isLocked() << endl;
}

#endif
