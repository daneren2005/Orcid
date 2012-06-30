#ifndef _TEST_DATA_FILE_H
#define	_TEST_DATA_FILE_H

#include "DataFile.h"

void writeDataFile()
{
	DataFile units(String("data/units.dat"));
	
	DataFile::Object* obj = new DataFile::Object("Ship1");
	obj->strings.insert("data/Danube/danube.obj", "model");
	obj->floats.insert(1.0f, "offset");
	
	DataFile::Object* obj2 = new DataFile::Object("Ship2");
	obj2->strings.insert("data/Daedalus.obj", "model");
	obj2->floats.insert(2.0f, "offset");
	
	DataFile::Object* obj3 = new DataFile::Object("Ship3");
	obj3->strings.insert("data/Daedalus.3ds", "model");
	obj3->floats.insert(3.0f, "offset");
	
	DataFile::Object* obj4 = new DataFile::Object("Ship4");
	obj4->strings.insert("data/Cobra fighter/cobra fighter.obj", "model");
	obj4->floats.insert(0.25f, "scale");
	obj4->floats.insert(3.0f, "offset");
	
	DataFile::Object* obj5 = new DataFile::Object("Ship5");
	obj5->strings.insert("data/Ghoul - fighter/GhoulOBJ.obj", "model");
	obj5->floats.insert(3.0f, "offset");
	
	DataFile::Object* obj6 = new DataFile::Object("Ship6");
	obj6->strings.insert("data/miranda1/start-miranda-class-bay.obj", "model");
	obj6->floats.insert(3.0f, "offset");

	DataFile::Object* item1 = new DataFile::Object("item1");
	DataFile::Object* item2 = new DataFile::Object("item2");

	/*obj->objects.insert(item1, "Gun");
	obj2->objects.insert(item2, "Trash");
	obj3->objects.insert(item1, "Main Drive");
	obj3->objects.insert(item2, "Trash Drive");
	obj3->objects.insert(item1, "Test Drive");*/
	
	units.insertObject(obj);
	units.insertObject(obj2);
	units.insertObject(obj3);
	units.insertObject(obj4);
	units.insertObject(obj5);
	units.insertObject(obj6);
	units.save();
	
	DataFile world(String("data/sol_system.dat"));
	
	obj = new DataFile::Object("Ship1");
	obj->floats.insert(0.0f, "x");
	obj->floats.insert(0.0f, "y");
	obj->floats.insert(40.0f, "z");
	world.insertObject(obj);
	
	obj = new DataFile::Object("Ship2");
	obj->floats.insert(30.0f, "x");
	obj->floats.insert(0.0f, "y");
	obj->floats.insert(40.0f, "z");
	world.insertObject(obj);
	
	world.save();
}

void readDataFile()
{
	DataFile units(String("data/units.dat"));
	units.load();
	
	for(Map<DataFile::Object*, String>::Iterator it = units.begin(); !it; it++)
	{
		console << "Name: " << it.key() << newline;
		for(Map<String, String>::Iterator it2 = it.value()->strings.begin(); !it2; it2++)
		{
			console << it2.key() << ": " << it2.value() << newline;
		}
		for(Map<float, String>::Iterator it2 = it.value()->floats.begin(); !it2; it2++)
		{
			console << it2.key() << ": " << it2.value() << newline;
		}
	}
}

#endif	/* TESTDATAFILE_H */

