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
	
	// move assignment
	MyClass& operator=(MyClass& other) noexcept {
		cout << "operator=(MyClass&) called (move assignment)" << endl;
		if(this != &other) {
		}
		return *this;
	}
	
	// move assignment
	MyClass& operator=(const MyClass& other) noexcept {
		cout << "operator=(const MyClass&) called (move assignment)" << endl;
		if(this != &other) {
		}
		return *this;
	}
	
	 // move assignment for rvalue refs
	MyClass& operator=(MyClass&& other) noexcept {
		cout << "operator=(MyClass&&) called (move assignment rvalue)" << endl;

		if(this != &other) {
		}
		return *this;
	}
	
	// move assignment for rvalue refs
	MyClass& operator=(const MyClass&& other) noexcept {
		cout << "operator=(const MyClass&&) called (move assignment rvalue)" << endl;

		if(this != &other) {
		}
		return *this;
	}

	// copy-and-swap idiom
	MyClass& operator=(MyClass arg) noexcept {
		cout << "operator=(MyClass&&) called (copy assignment)" << endl;

		swap(arg); 
		return *this;
	} 
	
	void swap(MyClass& other) {
		cout << "swap called" << endl;
		//MyClass temp = other;
		//other = *this;
		//*this = temp;
	}
};


//
// Test all combinations of "const" and "ref" to declare a variable that is not assigned.
// Conclusion: If you declare a variable with "&" (whether const or not), you must "assign" something to it (called initializing).
// As seen from test 0, 
// if it is marked "const &", it is ok to initialize it by assigning it to an rvalue/temporary.
// but if it is marked "&" only, it is NOT ok to do this.
//
void testUninitializedVarConstRef(void) {
	cout << "Declare uninitialized const ref variable" << endl;
	cout << "ERROR: 'myClassA' declared as reference but not initialized" << endl;
	//const MyClass &myClassA; // ERROR: 'myClassA' declared as reference but not initialized
	cout << endl;
}
void testUninitializedVarConst(void) {
	cout << "Declare uninitialized const variable" << endl;
	const MyClass myClassA; // OK.
	cout << endl;
}
void testUninitializedVarRef(void) {
	cout << "Declare uninitialized ref variable" << endl;
	cout << "ERROR: 'myClassA' declared as reference but not initialized" << endl;
	//MyClass &myClassA; // ERROR: 'myClassA' declared as reference but not initialized
	cout << endl;
}
void testUninitializedVar(void) {
	cout << "Declare uninitialized  variable" << endl;
	MyClass myClassA;  // OK.
	cout << endl;
}

//
// Test all combinations of "const" and "ref" to declare a variable for an object that is created on the stack.
//  Conclusion: cannot assign an rvalue (temporary) to a variable declared as a reference.
// But it is ok to assign an rvalue to a variable declared as a CONST reference.
//
void testVarInitializedToStackConstRef(void) {
	cout << "Declare const ref variable with a temporary obj assigned to it" << endl;
	const MyClass &myClassA = MyClass(); // OK. Because myClassA will never change the rvalue.
	cout << endl;
}
void testVarInitializedToStackConst(void) {
	cout << "Declare const variable with a temporary obj assigned to it" << endl;
	const MyClass myClassA = MyClass(); // OK. The value is copied when assigned.
	cout << endl;
}
void testVarInitializedToStackRef(void) {
	cout << "Declare a ref variable with a temporary obj assigned to it" << endl;
	cout << "ERROR: invalid initialization of non-const reference of type 'MyClass&' from an rvalue of type 'MyClass'" << endl;
	//MyClass &myClassA = MyClass(); // ERROR: invalid initialization of non-const reference of type 'MyClass&' from an rvalue of type 'MyClass'
	cout << endl;
}
void testVarInitializedToStack(void) {
	cout << "Declare a variable with a temporary obj assigned to it" << endl;
	MyClass myClassA = MyClass();  // OK. The value is copied when assigned.
	cout << endl;
}

//
// Test all combinations of "const" and "ref" to declare a variable for an object that is created on the stack that is an lvalue,
// not an rvalue (created earlier and given a different variable name).
//  Conclusion: All of the following are OK (no errors). This works the same way as does assigning from a heap object.
//
void testVarInitializedToStackLValueConstRef(void) {
	cout << "Declare a const ref variable with a stack lvalue var assigned to it" << endl;
	MyClass myClass;
	const MyClass &myClassA = myClass;
	cout << endl;
}
void testVarInitializedToStackLValueConst(void) {
	cout << "Declare a const variable with a stack lvalue var assigned to it" << endl;
	MyClass myClass;
	const MyClass myClassA = myClass; // MyClass(const MyClass&) called (copy constructor)
	cout << endl;
}
void testVarInitializedToStackLValueRef(void) {
	cout << "Declare a ref variable with a stack lvalue var assigned to it" << endl;
	MyClass myClass;
	MyClass &myClassA = myClass;
	cout << endl;
}
void testVarInitializedToStackLValue(void) {
	cout << "Declare a variable with a stack lvalue var assigned to it" << endl;
	MyClass myClass;
	MyClass myClassA = myClass; // MyClass(const MyClass&) called (copy constructor)
	cout << endl;
}

//
// Test all combinations of "const" and "ref" to declare a variable for an object that is created on the heap.
//  Conclusion: all of these are OK (no error). That means we can assign a heap object to anything.
// The heap object is not an "rvalue".
//
void testVarInitializedToHeapConstRef(void) {
	cout << "Declare a const ref variable with a heap obj assigned to it" << endl;
	const MyClass &myClassA = *(new MyClass()); // OK
	cout << endl;
}
void testVarInitializedToHeapConst(void) {
	cout << "Declare a const variable with a heap obj assigned to it" << endl;
	const MyClass myClassA = *(new MyClass()); // MyClass(const MyClass&) called (copy constructor)
	cout << endl;
}
void testVarInitializedToHeapRef(void) {
	cout << "Declare a ref variable with a heap obj assigned to it" << endl;
	MyClass &myClassA = *(new MyClass());  // OK
	cout << endl;
}
void testVarInitializedToHeap(void) {
	cout << "Declare a variable with a heap obj assigned to it" << endl;
	MyClass myClassA = *(new MyClass());  // MyClass(const MyClass&) called (copy constructor)
	cout << endl;
}



//
// Test all combinations of "const" and "ref" to declare a variable for REASSIGNING a variable declared const ref.
// Only the 2nd test (assigning a const ref var to a ref var) caused an error.
// Conclusion: If you are reassigining a variable declared "const ref", the new var must also be const, or if it is not a const, then it must not be a ref.
// 
//
void testReassignConstRefToVar(void) {
	cout << "Declare a const ref variable with a temporary obj assigned to it" << endl;
	const MyClass &myClassA = MyClass();
	cout << "Declare a variable and assign it to it" << endl;
	MyClass myClassB = myClassA; // MyClass(const MyClass&) called (copy constructor)
	cout << endl;
}
void testReassignConstRefToRefVar(void) {
	cout << "Declare a const ref variable with a temporary obj assigned to it" << endl;
	const MyClass &myClassA = MyClass();
	cout << "Declare a ref variable and assign it to it" << endl;
	cout << "ERROR: invalid initialization of reference of type 'MyClass&' from expression of type 'const MyClass'"<< endl;
	//MyClass &myClassB = myClassA; // ERROR: invalid initialization of reference of type 'MyClass&' 
	                                // from expression of type 'const MyClass'
									cout << endl;
	
}
void testReassignConstRefToConstVar(void) {
	cout << "Declare a const ref variable with a temporary obj assigned to it" << endl;
	const MyClass &myClassA = MyClass();
	cout << "Declare a const variable and assign it to it" << endl;
	const MyClass myClassB = myClassA;  // MyClass(const MyClass&) called (copy constructor)
	cout << endl;
}
void testReassignConstRefToConstRefVar(void) {
	cout << "Declare a const ref variable with a temporary obj assigned to it" << endl;
	const MyClass &myClassA = MyClass();
	cout << "Declare const a ref variable and assign it to it" << endl;
	const MyClass &myClassB = myClassA;  // OK because both are const ref
	cout << endl;
}

//
// Test all combinations of "const" and "ref" to declare a variable for REASSIGNING a variable declared const (but no ref).
// Only the 2nd test (assigning a const ref var to a ref var) caused an error.
// Conclusion: Same as above.
//
void testReassignConstToVar(void) {
	cout << "Declare a const variable with a temporary obj assigned to it" << endl;
	const MyClass myClassA = MyClass();
	MyClass myClassB = myClassA; // MyClass(const MyClass&) called (copy constructor)
	cout << endl;
}
void testReassignConstToRefVar(void) {
	cout << "Declare a const variable with a temporary obj assigned to it" << endl;
	const MyClass myClassA = MyClass();
	cout << "ERROR: invalid initialization of reference of type 'MyClass&' from expression of type 'const MyClass'" << endl;
	
	//MyClass &myClassB = myClassA; // ERROR: invalid initialization of reference of type 'MyClass&' 
	                                // from expression of type 'const MyClass'
	cout << endl;
}
void testReassignConstToConstVar(void) {
	cout << "Declare a const variable with a temporary obj assigned to it" << endl;
	const MyClass myClassA = MyClass();
	const MyClass myClassB = myClassA;   // MyClass(const MyClass&) called (copy constructor)
	cout << endl;
}
void testReassignConstToConstRefVar(void) {
	cout << "Declare a const variable with a temporary obj assigned to it" << endl;
	const MyClass myClassA = MyClass();
	const MyClass &myClassB = myClassA;  // OK
	cout << endl;
}

int main(void) {
	
	//testt();
	testUninitializedVarConstRef();
	testUninitializedVarConst();
	testUninitializedVarRef();
	testUninitializedVar();
	
	testVarInitializedToStackConstRef();
	testVarInitializedToStackConst();
	testVarInitializedToStackRef();
	testVarInitializedToStack();

	testVarInitializedToStackLValueConstRef();
	testVarInitializedToStackLValueConst();
	testVarInitializedToStackLValueRef();
	testVarInitializedToStackLValue();
	
	testVarInitializedToHeapConstRef();
	testVarInitializedToHeapConst();
	testVarInitializedToHeapRef();
	testVarInitializedToHeap();
	
	
	testReassignConstRefToVar();
	testReassignConstRefToRefVar();
	testReassignConstRefToConstVar();
	testReassignConstRefToConstRefVar();

	
	testReassignConstToVar();
	testReassignConstToRefVar();
	testReassignConstToConstVar();
	testReassignConstToConstRefVar();
	
	return 0;
}