#ifndef _TEST_DATA_FILE_H
#define	_TEST_DATA_FILE_H

#include "DataFile.h"

void writeDataFile()
{
	DataFile units(String("data/units.dat"));
	
	DataFile::Object* obj = new DataFile::Object("Ship1");
	obj->properties.insert("data/Danube/danube.obj", "model");
	
	DataFile::Object* obj2 = new DataFile::Object("Station1");
	obj2->properties.insert("data/Danube/danube.obj", "model");
	
	DataFile::Object* obj3 = new DataFile::Object("Ship2");
	obj3->properties.insert("data/Danube/danube.obj", "model");
	
	units.insertObject(obj);
	units.insertObject(obj2);
	units.insertObject(obj3);
	units.save();
}

void readDataFile()
{
	DataFile units(String("data/units.dat"));
	units.load();
	
	for(Map<DataFile::Object*, String>::Iterator it = units.begin(); !it; it++)
	{
		console << "Name: " << it.key() << newline;
		for(Map<String, String>::Iterator it2 = it.value()->properties.begin(); !it2; it2++)
		{
			console << it2.key() << ": " << it2.value() << newline;
		}
	}
}

#endif	/* TESTDATAFILE_H */

