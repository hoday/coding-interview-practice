#include <iostream>
#include <memory>

using namespace std;

class MyClass {
public:	
	// default constructor
	MyClass(void) {
		cout << "MyClass(void) called (default constructor)" << endl;
	}

	// a parameterized constructor
	MyClass(int i) {
		cout << "MyClass(int) called (a parameterized constructor)" << endl;
	}
	
	// copy construcotr
	MyClass(const MyClass &other) {
		cout << "MyClass(const MyClass&) called (copy constructor)" << endl;
	}
	
	// move constructor
	MyClass(MyClass &&other) {
		cout << "MyClass(const MyClass&&) called (move constructor)" << endl;
	}	

};

MyClass getMyClass(void) {
	return MyClass();
}

int main(void) {
	
	cout << "This calls the default constructor" << endl;
	MyClass myClassA;
	cout << endl;

	//cout << "This is a function declaration, not a call to a constructor" << endl;
	//MyClass myClassAA();
	//myClassAA.print();
	//cout << endl;

	cout << "This calls a parameterized constructor" << endl;
	MyClass myClassP(5);
	cout << endl;
	
	cout << "This also calls the default constructor" << endl;
	MyClass *myClassH1 = new MyClass;
	cout << endl;

	cout << "This also calls the default constructor" << endl;
	MyClass *myClassH2 = new MyClass();
	cout << endl;
	
	cout << "This also calls the default constructor" << endl;
	new MyClass();
	cout << endl;
	
	cout << "This calls the copy constructor" << endl;	
	MyClass myClassB = myClassA;
	cout << endl;

	cout << "This calls the default constructor and move constructor" << endl;	
	cout << "With copy elision turned on, only calls the default constructor" << endl;		
	MyClass myClassC = MyClass();
	cout << endl;
	
	cout << "This calls the move constructor" << endl;	
	MyClass myClassAAA = std::move(myClassB);
	cout << endl;
	
	cout << "This calls the default constructor and move constructor" << endl;	
	cout << "With copy elision turned on, only calls the move constructor" << endl;	
	MyClass myClassAAAA = std::move(MyClass());
	cout << endl;
	
	cout << "This calls default and move constructor in the function, and then the move constructor again" << endl;	
	cout << "With copy elision on, only the defualt constructor is called" << endl;	
	MyClass myClassAAAAA = getMyClass();
	cout << endl;
	
	cout << "This calls the parameterized constructor (type conversion) and a move constructor" << endl;
	cout << "With copy elision turned on, only calls the parameterized constructor" << endl;	
	MyClass myClassE = 4;
	cout << endl;
	
	cout << "This calls the parameterized constructor and then move constructor" << endl;
	cout << "With copy elision on, only the parameterized is called" << endl;	
	MyClass myClassEE = MyClass(4);
	cout << endl;
	
	
	
	cout << "Try compiling this with the -fno-elide-constructors flag. It will show different output." << endl;	

	
	


	
	

	
	return 0;
}