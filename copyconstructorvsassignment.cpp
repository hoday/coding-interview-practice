#include <iostream>
#include <memory>

using namespace std;

class MyClass {
public:	
	MyClass(void) {
		cout << "MyClass(void) called (default constructor)" << endl;
	}
	
	// copy construcotr
	MyClass(const MyClass &other) {
		cout << "MyClass(const MyClass&) called (copy constructor)" << endl;
		
	}
	
	
	/*
	// move assignment
	MyClass& operator=(MyClass& other) noexcept {
		cout << "operator=(MyClass&) called (move assignment)" << endl;
		if(this != &other) {
		}
		return *this;
	}
	*/
	
	
	// move assignment
	
	MyClass& operator=(const MyClass& other) noexcept {
		cout << "operator=(const MyClass&) called (move assignment)" << endl;
		if(this != &other) {
		}
		return *this;
	}
	
	
	
	 // move assignment for rvalue refs
	 /*
	MyClass& operator=(MyClass&& other) noexcept {
		cout << "operator=(MyClass&&) called (move assignment rvalue)" << endl;

		if(this != &other) {
		}
		return *this;
	}
	*/
	
	// move assignment for rvalue refs
	
	MyClass& operator=(const MyClass&& other) noexcept {
		cout << "operator=(const MyClass&&) called (move assignment rvalue)" << endl;

		if(this != &other) {
		}
		return *this;
	}
	

	// copy-and-swap idiom
	/*
	MyClass& operator=(MyClass arg) noexcept {
		cout << "operator=(MyClass) called (copy assignment)" << endl;

		swap(arg); 
		return *this;
	}
	*/
	
	
	
	void swap(MyClass& other) {
		cout << "swap called" << endl;
		//MyClass temp = other;
		//other = *this;
		//*this = temp;
	}
};

int main(void) {
	
	cout << "This calls the default constructor" << endl;
	MyClass myClassA;
	cout << endl;

	cout << "This also calls the default constructor" << endl;
	MyClass myClassAA();
	cout << endl;
	
	cout << "This also calls the default constructor" << endl;
	MyClass *myClassH = new MyClass();
	cout << endl;
	
	cout << "This also calls the default constructor" << endl;
	MyClass myClassAAA = MyClass();
	cout << endl;
	
	cout << "This calls the copy constructor" << endl;	
	MyClass myClassB = myClassA;
	cout << endl;
	
	cout << "This calls some type of assignment" << endl;	
	myClassB = myClassA;
	cout << endl;
	
	cout << "This calls default constructor first" << endl;
	cout << "then some kind of assignment" << endl;	
	myClassB = MyClass();
	cout << endl;
	

	
	return 0;
}