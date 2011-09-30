#ifndef _TEST_DATES_H
#define	_TEST_DATES_H

#include "Date.h"
#include "Time.h"

void testString()
{
	cout << "Testing String: " << endl;
	String string = "%L, %d %m %Y";
	String str2 = string.replace(0, 2, "Month");
	String str3 = string.replace(4, 2, "Day");

	cout << str2.cStr() << endl;
	cout << str3.cStr() << endl;

	cout << "Done testing string" << endl;
}

void testDate()
{
	cout << "Testing Dates: " << endl;
	
	Date date;
	cout << date.getYear() << endl;
	cout << "Leap Year: " << date.isLeapYear() << endl;
	cout << date.toString().cStr() << endl;
	cout << date.toString("%L, %d %M %y").cStr() << endl;
	cout << date.toString("%f of %N").cStr() << endl;
	cout << date.toString("%F of %Y").cStr() << endl;
	cout << date.toString("%d of %t").cStr() << endl;
	cout << "System time zone: " << Date::getSystemTimeZone() << endl;
	date.convertTimeZone(-5);
	cout << date.toString().cStr() << endl;
	date.convertTimeZone(5);
	cout << date.toString().cStr() << endl << endl;

	date.convertTimeZone(-8);
	date.addTime(0, 10, 5);
	cout << date.toString().cStr() << endl;
	date.addTime(100, 5, 10);
	cout << date.toString().cStr() << endl;
	date.addTime(7, 0, 5, 10);
	cout << date.toString().cStr() << endl;
	date.addTime(300, 0, 5, 10);
	cout << date.toString().cStr() << endl;
	cout << "Leap Year: " << date.isLeapYear() << endl << endl;

	date = Date(2011, 12, 31, 23, 0, 0);
	cout << date.toString().cStr() << endl;
	date.convertTimeZone(-7);
	cout << date.toString().cStr() << endl;
	date.convertTimeZone(-8);
	cout << date.toString().cStr() << endl;
	date.addTime(1, 0, 0);
	cout << date.toString().cStr() << endl;
	date.addTime(0, 0, -1);
	cout << date.toString().cStr() << endl;
	date.addTime(0, 1, 0);
	cout << date.toString().cStr() << endl;
	date.addTime(0, -1, 0);
	cout << date.toString().cStr() << endl;
	date.addTime(1, 0, 0);
	cout << date.toString().cStr() << endl;
	date.addTime(-1, 0, 0);
	cout << date.toString().cStr() << endl;
	date.addTime(2, 0, 0, 0);
	cout << date.toString().cStr() << endl << endl;

	Time t = 5000;
	cout << date.toString().cStr() << endl;
	date = date - t;
	cout << date.toString().cStr() << endl;
	date = date + t;
	cout << date.toString().cStr() << endl;
	date += t;
	cout << date.toString().cStr() << endl;
	date -= t;

	Date date2 = date;
	date2 += t;
	Time t2 = date2 - date;
	cout << t2.toString().cStr() << endl;
}

void testTime()
{
	Time t;
	cout << t << endl;
	t = 10000;
	cout << t << endl;
	cout << t.getSeconds() << endl;
	cout << t.getMinutes() << endl;
	cout << t.getHours() << endl;
	t += 100;
	cout << t.getSeconds() << endl;
	cout << t.toString().cStr() << endl;
	t+= 10000000;
	cout << t.toString("%+%g:%G:%h:%H").cStr() << endl << endl;

	Time t2 = 5000;
	cout << t2.toString().cStr() << endl;
	t2 = -5000;
	cout << t2 << endl;
	cout << t2.getSeconds() << endl;
	cout << t2.getMinutes() << endl;
	cout << t2.getHours() << endl;
	cout << t2.toString().cStr() << endl;
	cout << t2.toString("%+%g:%G:%h:%H").cStr() << endl;	
}

#endif
