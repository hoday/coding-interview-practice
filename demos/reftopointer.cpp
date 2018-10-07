#include <iostream>
#include <memory>

using namespace std;



class MyClass {
public:
	MyClass(string s) : s(s) {}
	string s;
};


/*
 *  This is a demonstration of changing what a pointer points to through a reference to that pointer.
 *  (The same thing could be done through a pointer to a pointer).
 *  This pattern is useful for manipulating linked lists.
 */
int main() {
	 
	//
	// Case 1: shared pointers
	//
	
	shared_ptr<MyClass> p1 = make_shared<MyClass>("1");
	shared_ptr<MyClass> p2 = make_shared<MyClass>("2");

	// p is initially assigned to point to p1
	shared_ptr<MyClass> p = p1;
	
	// refp is used to manipulate where p points to
	shared_ptr<MyClass> & refp = p; 
	
	// p now points to object 1
	cout << p->s << endl;
	
	// p is initially reassigned to point to p2
	refp = p2;

	// p now points to object 2
	cout << p->s << endl;

	
	return 0;
}