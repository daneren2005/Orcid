#ifndef _TEST_FILES_H
#define	_TEST_FILES_H

#include "File.h"
#include "Folder.h"

using namespace std;

void testFile()
{
	cout << "Testing files accessors: " << endl;
	File file("data/war_jet.3ds");
	cout << file.getFileName().cStr() << endl;
	cout << file.getFileType().cStr() << endl;
	cout << file.getFullName().cStr() << endl;
	cout << file.getParentPath().cStr() << endl;
	cout << file.getFullPath().cStr() << endl;
	cout << "Size: " << file.getSize() << endl;
	cout << "Blocked Size: " << file.getPhysicalSize() << endl;
	cout << "KB: " << file.getSizeKB() << endl;
	cout << "MB: " << file.getSizeMB() << endl;
	cout << "GB: " << file.getSizeGB() << endl;
	cout << "Accessed: " << file.getLastAccessed().toString().cStr() << endl;
	cout << "Modified: " << file.getLastModified().toString().cStr() << endl;
	cout << "Done testing files accessors" << endl << endl;

	cout << "Testing files reads: " << endl;
	File file2("main.cpp");
	file2.open();
	// for(int i = 0; i < 10; i++)
		cout << file2.getLine().cStr() << endl;
	cout << file2.getCharacter() << " " << file2.getCharacter() << " " << file2.peekCharacter() << " " << file2.getCharacter() << endl;
	cout << file2.peekLine().cStr() << endl;
	cout << file2.peekLine().cStr() << endl;
	cout << file2.getLine().cStr() << endl;
	cout << file2.getLine().cStr() << endl;
	cout << file2.peekString(5).cStr() << endl;
	cout << file2.getString(5).cStr() << endl;
	cout << file2.getLine().cStr() << endl;
	cout << file2.getString(27).cStr() << endl;
	cout << file2.getLine().cStr() << endl;
	cout << "Done testing files reads" << endl << endl;

	cout << "Testing files writes: " << endl;
	File file3("test_folder/test2");
	file3.open(File::WRITE);
	file3.writeString("Test this out\n\n");
	file3.writeString("Test with no endl");
	file3.writeLine("Test again");
	file3.writeString("See if this works\n");
	// file3.writeString("See if this works too");
	file3.close();

	file3.open();
	while(!file3.eof())
	{
		cout << file3.getLine().cStr() << endl;
	}
	cout << "Done testing files writes" << endl << endl;

	cout << "Testing file usability" << endl;
	File file4("rarar");
	cout << file4.getFullPath().cStr() << endl;
	cout << "Exists: " << file4.doesExist() << endl;
	cout << "Read: " << file4.canRead() << endl;
	cout << "Write: " << file4.canWrite() << endl;
	file4 = file3;
	cout << file4.getFullPath().cStr() << endl;
	cout << "Exists: " << file4.doesExist() << endl;
	cout << "Read: " << file4.canRead() << endl;
	cout << "Write: " << file4.canWrite() << endl;
	cout << "Owner ID: " << file4.getOwnerID() << endl;
	cout << "Group ID: " << file4.getGroupID() << endl;
	file4 = "test_folder/test";
	cout << file4.getFullPath().cStr() << endl;
	cout << "Exists: " << file4.doesExist() << endl;
	cout << "Read: " << file4.canRead() << endl;
	cout << "Write: " << file4.canWrite() << endl;
	cout << "Permissions: " << file4.getPermissions() << endl;
	cout << "Owner: " << file4.getOwnerPermissions() << endl;
	cout << "Group: " << file4.getGroupPermissions() << endl;
	cout << "Other: " << file4.getOtherPermissions() << endl;
	cout << "Done testing file usability" << endl << endl;
}

void testFileDelimiter()
{
	cout << "Start File Delimiter read:" << endl;
	String str;
	File file("test_folder/delim", ',');
	file.open();
	for(int i = 0; i < 10; i++)
	{
		file >> str;
		cout << str.cStr() << endl;
	}
	file.close();
	cout << "End File Delimiter read" << endl << endl;

	cout << "Start File Delimiter write:" << endl;
	File file2("test_folder/delim2", "!!");
	file2.open(File::WRITE);

	file2 << "test" << "Rar" << "Check this out" << "Lol";
	file2.writeString("End");
	file2.close();
	file2.open();
	while(!file2.eof())
	{
		cout << file2.getLine().cStr() << endl;
	}
	cout << "End File Delimiter write" << endl;
}

void testFileDirectory()
{
	cout << "Testing folders: " << endl;

	Folder currDir;
	cout << currDir.getPath().cStr() << endl;
	cout << "Size: " << currDir.getSize() << endl;
	cout << "Blocked Size: " << currDir.getPhysicalSize() << endl;
	cout << "MB: " << currDir.getSizeMB() << endl << endl;

	/*cout << endl << "Creating folder: " << endl;
	Folder sub = currDir.createSubFolder("test_folder");
	cout << sub.getPath().cStr() << endl;
	cout << "Size: " << sub.getSize() << endl;*/

	cout << currDir.getRootFolder().getPath().cStr() << endl;
	currDir.changeLocation("../");
	cout << currDir.getPath().cStr() << endl;
	cout << "Size: " << currDir.getSize() << endl;
	cout << "Blocked Size: " << currDir.getPhysicalSize() << endl;
	cout << "MB: " << currDir.getSizeMB() << endl;
	cout << "MB: " << currDir.getSizeMB() << endl;
	cout << "Blocked MB: " << currDir.getPhysicalSizeMB() << endl;
	cout << currDir.getPath().cStr() << endl << endl;

	Folder dir2 = currDir.getParentFolder();
	cout << dir2.getPath().cStr() << endl;

	Folder dir3("data");
	cout << "Files in " << dir3.getPath().cStr() << endl;
	Array<File> files = dir3.getFiles();

	for(unsigned long i = 0; i < files.size(); i++)
	{
		cout << files[i].getFullName().cStr() << endl;
	}

	cout << "Done testing folders" << endl;
}

#endif
