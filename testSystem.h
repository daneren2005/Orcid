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

#ifndef _TEST_SYSTEM_H
#define	_TEST_SYSTEM_H

#include "System.h"
#include "Console.h"

void testSystem()
{
	console << "Vendor: " << sys.processor.vendor << newline;
	console << "Name: " << sys.processor.name << newline;
	console << "Cores: " << sys.processor.cores << newline;
	console << "Threads: " << sys.processor.threads << newline;
	
	console << "64 bit processor: " << sys.processor.x64 << newline;
	console << "Hyptherthread: " << sys.processor.hyperthread << newline;
	console << "Virtualized: " << sys.processor.hypervisor << newline;
	
	console << "SSE: " << sys.processor.sse << newline;
	console << "SSE2: " << sys.processor.sse2 << newline;
	console << "SSE3: " << sys.processor.sse3 << newline;
	console << "SSSE3: " << sys.processor.ssse3 << newline;
	console << "SSE4_1: " << sys.processor.sse4_1 << newline;
	console << "SSE4_2: " << sys.processor.sse4_2 << newline;
}

#endif
