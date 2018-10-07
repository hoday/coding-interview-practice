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
	
	int* returnPointer(void) {
		return &x;
	}
	
	int& returnReference(void) {
		return x;
	}
	
	int x;
};


int main()
{ 
	A a(5);	

	cout << "By reference:         address of a.x:" << &a.returnReference() << "  value of a.x: " << a.returnReference() << endl; 
	cout << "By pointer:           address of a.x:" << a.returnPointer() << "  value of a.x: " << *a.returnPointer() << endl; 
	cout << "Direct member access: address of a.x:" << &a.x << "  value of a.x: " << a.x << endl; 

	 int &aRef = a.returnReference();
	 int *aPtr = a.returnPointer();
	cout << "address of aRef: " << &aRef << "  vallue of aRef: " << aRef << endl; 
	cout << "address of aPtr: " << &aPtr << "  vallue of aPtr: " << aPtr << " deref of aPtr: " << *aPtr << endl; 

	aRef = 6;
	
	cout << "address of aRef: " << &aRef << "  vallue of aRef: " << aRef << endl; 
	cout << "address of aPtr: " << &aPtr << "  vallue of aPtr: " << aPtr << " deref of aPtr: " << *aPtr << endl; 

}