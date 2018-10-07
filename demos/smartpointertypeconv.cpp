#include <iostream>
#include <memory>

using namespace std;



class MyClass {
};

void func(shared_ptr<MyClass> p) {
}

/*
 *  This is a demonstration of a function with an argument that is declared as type smart pointer.
 *  The constructors of smart pointers (the constructor that performs conversion from regular pointer)
 *  is declared as explicit. Therefore automatic type conversion will not happen if you try to 
 */
int main() {
	
	MyClass *p = new MyClass();

	 
	//
	// This will not work (compiler error) because func is expecting an argument of type shared_ptr,
	// but this is just a regular pointer, and type conversion will not happen.
	// The error is: 'could not convert p from MyClass* to std::shared_ptr<MyClass>'
	//
	//func(p);
	
	// This works because we have explicitly converted the pointer to a shared pointer.
	func(shared_ptr<MyClass>(p));
	
	// This also works because NULL does not have to be converted to a shared pointer.
	func(NULL);
	
	return 0;
}