#ifndef _TEST_DATA_FILE_H
#define	_TEST_DATA_FILE_H

#include "DataFile.h"

void writeDataFile()
{
	DataFile units(String("data/units.dat"));
	
	DataFile::Object obj("Ship1");
	obj.properties.insert("data/Danube/danube.obj", "model");
	
	units.insertObject(obj);
	units.save();
}

#endif	/* TESTDATAFILE_H */

