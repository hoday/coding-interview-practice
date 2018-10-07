#include <iostream>

using namespace std;

class A {
public:
    A(int x) : x(x) {
		cout << "A constructor called: x=" << x << endl;
	}
	
	~A() {
		cout << "A destructor called: x=" << x << endl;
	}
	
	int x;
};

const A& getA1()
{
 A a(1);
 return a; // causes a compiler warning - reference to a local variable returned
}

A& getA2()
{
 A a(2);
 int b = 5;

 return a; // causes a compiler warning - reference to a local variable returned
}

A getA3()
{
 A a(3);
 return a;
}

int main()
{ 
	const A& a1 = getA1(); //1
	cout << a1.x << endl;  // returns 1 as expected because the data on popped stack frame was not overwritten yet
	cout << a1.x << endl;  // returns garbage - the data was overwritten already
	
	A& a2 = getA2();       //2
	cout << a2.x << endl;  // returns 2 as expected because the data on popped stack frame was not overwritten yet
	cout << a2.x << endl;  // returns garbage - the data was overwritten already
	 
	// A& newA3 = getA3();       //3 compiler error
	const A& a3 = getA3();       //3
	cout << a3.x << endl;  // returns 3 as expected because the data on popped stack frame was not overwritten yet
	cout << a3.x << endl;  // still returns 3 because it was returned by val not reference

	cout << "address of a1.x:" << &a1.x << "  value of a1.x: " << a1.x << endl; 
	cout << "address of a2.x:" << &a2.x << "  value of a2.x: " << a2.x << endl;  
	cout << "address of a3.x:" << &a3.x << "  value of a3.x: " << a3.x << endl; 
	// a1 and a2 have the same addr (they were created at same place on the stack)	

	 // 
}