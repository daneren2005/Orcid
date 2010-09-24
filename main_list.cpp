/* 
 * File:   main.cpp
 * Author: scott
 *
 * Created on July 6, 2010, 5:31 PM
 */

#include "skyfire.h"

#include <iostream>
using namespace std;

void* getSize(void* arg)
{
	List<int>* list = (List<int>*)arg;
	int temp = 0;

	while(true)
	{
		cout << list->size() << endl;

		for(int i = 0; i < 240000000; i++)
		{
			temp += temp;
		}
	}
}

void* pushFront(void* arg)
{
	List<int>* list = (List<int>*)arg;

	while(true)
	{
		for(int i = 0; i < 100000; i++)
		{
			list->push_front(i);
		}
	}
}
void* pushBack(void* arg)
{
	List<int>* list = (List<int>*)arg;

	while(true)
	{
		for(int i = 0; i < 100000; i++)
		{
			list->push_back(i);
		}
	}
}

void* popFront(void* arg)
{
	List<int>* list = (List<int>*)arg;

	while(true)
	{
		list->pop_front();
	}
}
void* popBack(void* arg)
{
	List<int>* list = (List<int>*)arg;

	while(true)
	{
		list->pop_back();
	}
}

int main_list(int argc, char** argv)
{
	List<int>* list = new List<int>();
	pthread_t size;
	pthread_t pushFront1, pushFront2, pushFront3;
	pthread_t pushBack1, pushBack2;
	pthread_t popFront1, popFront2, popFront3;
	pthread_t popBack1, popBack2, popBack3;

	// size reader
	pthread_create(&size, NULL, getSize, (void*)list);

	// pushers
	pthread_create(&pushFront1, NULL, pushFront, (void*)list);
	// pthread_create(&pushFront2, NULL, pushFront, (void*)list);
	// pthread_create(&pushFront3, NULL, pushFront, (void*)list);
	pthread_create(&pushBack1, NULL, pushBack, (void*)list);
	// pthread_create(&pushBack2, NULL, pushBack, (void*)list);

	// poppers
	pthread_create(&popFront1, NULL, popFront, (void*)list);
	// pthread_create(&popFront2, NULL, popFront, (void*)list);
	// pthread_create(&popFront3, NULL, popFront, (void*)list);
	pthread_create(&popBack1, NULL, popBack, (void*)list);
	pthread_create(&popBack2, NULL, popBack, (void*)list);
	// pthread_create(&popBack3, NULL, popBack, (void*)list);

	pthread_join(size, NULL);
    return (0);
}

