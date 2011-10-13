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

#ifndef _TEST_SORT_H
#define	_TEST_SORT_H

#include "Array.h"

#include <iostream>
using namespace std;

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
		cout << array[i] << endl;
	}
	cout << endl;

	array.sort(intCompare);
	for(uint i = 0; i < array.size(); i++)
	{
		cout << array[i] << endl;
	}
}

#endif