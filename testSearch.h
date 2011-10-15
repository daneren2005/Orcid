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

#include "SearchState.h"
#include "Console.h"

class BoatAction : public SearchAction
{
public:
	BoatAction(SearchState* result, int m, int c, bool b) : m(m), c(c), b(b)
	{
		this->resultState = result;
	}
	~BoatAction() {}

	virtual void execute()
	{
		console << "Move " << m << " Missionaries and " << c << " Cannibles" <<
			(b ? " Left" : " Right") << newline;
	}
	virtual double getCost()
	{
		return 1.0;
	}

private:
	int m, c;
	bool b;
};

class BoatState : public SearchState
{
public:
	BoatState(int missionaryLeft, int missionaryRight, int cannableLeft, int cannableRight, bool boatLeft) : 
		ml(missionaryLeft), mr(missionaryRight), cl(cannableLeft), cr(cannableRight), b(boatLeft) {}
	virtual ~BoatState() {}

	virtual double getHeuristic()
	{
		return ml+cl+(b ? 1 : 0);
	}
	virtual Array<SearchAction*> getActions()
	{
		Array<SearchAction*> actions;

		int sign = b ? +1 : -1;
		for(int m=0;m<=2;m++)
		{
			for(int c=0;c<=2;c++)
			{
				if (m+c<1) continue; //has to be at least 1 person
				if (m+c>2) continue; //cannot be more than 2

				// If new state would be valid, add it
				int newMl = ml - sign * m;
				int newMr = mr + sign * m;
				int newCl = cl - sign * c;
				int newCr = cr + sign * c;
				if((newMl >= newCl || newMl == 0) && (newMr >= newCr || newMr == 0))
				{
					BoatState* newState = new BoatState(newMl, newMr, newCl, newCr, !b);
					BoatAction* newAction = new BoatAction(newState, m, c, !b);
					actions.insert(newAction);
				}
			}
		}

		return actions;
	}
	virtual bool equal(SearchState* rhs)
	{
		BoatState* bs = (BoatState*)rhs;
		return bs->ml == ml && bs->mr == mr && bs->cl == cl && bs->cr == cr && bs->b == b;
	}
private:
	int ml, mr, cl, cr;
	bool b;
};

void testSearchState()
{
	console << "Starting Search" << newline;
	
	BoatState* start = new BoatState(3, 0, 3, 0, true);
	BoatState* end = new BoatState(0, 3, 0, 3, false);

	SearchStatePath path = start->getPathToGoal(end);
	for(SearchStatePath::Iterator it = path.begin(); !it; it++)
	{
		if(it.getNextAction() != 0x0)
			it.getNextAction()->execute();
	}
	
	console << "End search" << newline;
}

#endif
