#ifndef _TEST_FUNCTION_H
#define	_TEST_FUNCTION_H

#include "Function.h"
#include "MemberFunction.h"

class test_function
{
public:
	int operator()(int x)
	{
		return x * 2;
	}
};

int test_function2(int x)
{
	return x;
}

class testClass
{
public:
	static int test_function(int x)
	{
		return x / 2;
	}

	int test_function2(int x)
	{
		return x / 3;
	}
	int test_function3(long x)
	{
		return x / 2 + 1;
	}
};

void output(int r)
{
	console << "Void return: " << r << newline;
}
void outputCast(long x)
{
	console << "Function cast: " << x << newline;
}

void testFunction()
{
	Function<int, int> function;
	function = test_function();
	console << "Struct Function:" << function(10) << " " << function(15) << newline;

	function = test_function2;
	Function<int, int> copyFunction = function;
	console << "Function: " << function(10) << " " << function(15) << newline;
	console << "Copy Function: " << copyFunction(10) << " " << copyFunction(15) << newline;

	function = testClass::test_function;
	console << "Static member function: " << function(10) << " " << function(15) << newline;
	copyFunction = function;
	console << "Copy Function: " << copyFunction(10) << " " << copyFunction(15) << newline;

	testClass t;
	MemberFunction<testClass, int, int> function2;
	function2 = &testClass::test_function2;
	function2.setObject(&t);
	console << "Actual member function: " << function2(10) << " " << function2(15) << newline;
	MemberFunction<testClass, int, int> copyFunction2 = function2;
	console << "Copy Function: " << copyFunction2(10) << " " << copyFunction2(15) << newline;

	// Should throw compiler error
	// function2 = test_function();
	// function2 = test_function2;

	MemberFunction<testClass, int, int> function3(&t);
	function3 = &testClass::test_function2;
	console << "Actual member function2: " << function3(10) << " " << function3(15) << newline;
	copyFunction2 = function2;
	console << "Copy Function: " << copyFunction2(10) << " " << copyFunction2(15) << newline;

	Function<int, int>* func = new Function<int, int>;
	*func = test_function();
	console << "Function pointer: " << (*func)(10) << " " << (*func)(15) << newline;

	func->setFunction(test_function());
	console << "Function pointer Set1: " << func->execute(10) << " " << func->execute(15) << newline;
	func->setFunction(test_function2);
	console << "Function pointer Set2: " << func->execute(10) << " " << func->execute(15) << newline;

	MemberFunction<testClass, int, int>* func2 = new MemberFunction<testClass, int, int>(&t);
	(*func2) = &testClass::test_function2;
	func = func2;
	console << "Member Function pointer: " << func->execute(10) << " " << func->execute(15) << newline;

	func2 = new MemberFunction<testClass, int, int>;
	func2->setObject(&t); 
	func2->setFunction(&testClass::test_function2);
	func = func2;
	console << "Member Function pointer Set: " << func->execute(10) << " " << func->execute(15) << newline;

	// Just checking it will compile correctly
	Function<void, int> function4;
	function4 = output;
	function4(19);

	// Function casting tests
	Function<void, long> function5 = outputCast;
	function4 = function5;
	function4(20);
	function4 = (Function<void, long>)function5;
	function4(21);
	function4 = output;
	// function4 = outputCast;
	function4(22);

	// Member function casting tests
	MemberFunction<testClass, int, long> function6(&t);
	function6 = &testClass::test_function3;
	function2 = function6;
	console << "Member implicit cast: " << function2(10) << newline;
	function2 = (MemberFunction<testClass, int, long>)function6;
	console << "Member explicit cast: " << function2(10) << newline;
}

class multi_function
{
public:
	int operator()(int x, int y)
	{
		return x * y;
	}
};

int multi_function2(int x, int y)
{
	return x * y + 2;
}

class testClass2
{
public:
	int function(int x, int y)
	{
		return x * y - 2;
	}
};

void testFunction2()
{
	Function<int, int, int> func = multi_function2;
	console << "Multiple paramater2: " << func(5, 2) << newline;
	
	func = multi_function();
	console << "Multiple paramter3: " << func(2, 3) << newline;
	
	testClass2 obj;
	MemberFunction<testClass2, int, int, int> func2(&obj);
	func2 = &testClass2::function;
	console << "Multiple Member Param: " << func2(10, 2) << newline;
	
	func = (Function<int, int, int>)func2;
	console << "Multiple Member Cast: " << func(10, 3) << newline;
}

#endif
