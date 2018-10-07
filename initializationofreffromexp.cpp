#include <iostream>
#include <memory>

using namespace std;

class MyClass {
	
};



//
// Test all combinations of "const" and "ref" to declare a variable that is not assigned.
// Conclusion: If you declare a variable with "&" (whether const or not), you must "assign" something to it (called initializing).
// As seen from test 0, 
// if it is marked "const &", it is ok to initialize it by assigning it to an rvalue/temporary.
// but if it is marked "&" only, it is NOT ok to do this.
//
void testUninitializedVarConstRef(void) {
	//const MyClass &myClassA; // ERROR: 'myClassA' declared as reference but not initialized
}
void testUninitializedVarConst(void) {
	const MyClass myClassA; // OK.
}
void testUninitializedVarRef(void) {
	//MyClass &myClassA; // ERROR: 'myClassA' declared as reference but not initialized
}
void testUninitializedVar(void) {
	MyClass myClassA;  // OK.
}

//
// Test all combinations of "const" and "ref" to declare a variable for an object that is created on the stack.
//  Conclusion: cannot assign an rvalue (temporary) to a variable declared as a reference.
// But it is ok to assign an rvalue to a variable declared as a CONST reference.
//
void testVarInitializedToStackConstRef(void) {
	const MyClass &myClassA = MyClass(); // OK. Because myClassA will never change the rvalue.
}
void testVarInitializedToStackConst(void) {
	const MyClass myClassA = MyClass(); // OK. The value is copied when assigned.
}
void testVarInitializedToStackRef(void) {
	//MyClass &myClassA = MyClass(); // ERROR: invalid initialization of non-const reference of type 'MyClass&' from an rvalue of type 'MyClass'
}
void testVarInitializedToStack(void) {
	MyClass myClassA = MyClass();  // OK. The value is copied when assigned.
}

//
// Test all combinations of "const" and "ref" to declare a variable for an object that is created on the stack that is an lvalue,
// not an rvalue (created earlier and given a different variable name).
//  Conclusion: All of the following are OK (no errors). This works the same way as does assigning from a heap object.
//
void testVarInitializedToStackLValueConstRef(void) {
	MyClass myClass;
	const MyClass &myClassA = myClass;
}
void testVarInitializedToStackLValueConst(void) {
	MyClass myClass;
	const MyClass myClassA = myClass;
}
void testVarInitializedToStackLValueRef(void) {
	MyClass myClass;
	MyClass &myClassA = myClass;
}
void testVarInitializedToStackLValue(void) {
	MyClass myClass;
	MyClass myClassA = myClass; 
}

//
// Test all combinations of "const" and "ref" to declare a variable for an object that is created on the heap.
//  Conclusion: all of these are OK (no error). That means we can assign a heap object to anything.
// The heap object is not an "rvalue".
//
void testVarInitializedToHeapConstRef(void) {
	const MyClass &myClassA = *(new MyClass()); // OK
}
void testVarInitializedToHeapConst(void) {
	const MyClass myClassA = *(new MyClass()); // OK.
}
void testVarInitializedToHeapRef(void) {
	MyClass &myClassA = *(new MyClass());  // OK
}
void testVarInitializedToHeap(void) {
	MyClass myClassA = *(new MyClass());  // OK
}



//
// Test all combinations of "const" and "ref" to declare a variable for REASSIGNING a variable declared const ref.
// Only the 2nd test (assigning a const ref var to a ref var) caused an error.
// Conclusion: If you are reassigining a variable declared "const ref", the new var must also be const, or if it is not a const, then it must not be a ref.
// 
//
void testReassignConstRefToVar(void) {
	const MyClass &myClassA = MyClass();
	MyClass myClassB = myClassA; // OK because it is not a ref (value is copied)
}
void testReassignConstRefToRefVar(void) {
	const MyClass &myClassA = MyClass();
	//MyClass &myClassB = myClassA; // ERROR: invalid initialization of reference of type 'MyClass&' 
	                                // from expression of type 'const MyClass'
	
}
void testReassignConstRefToConstVar(void) {
	const MyClass &myClassA = MyClass();
	const MyClass myClassB = myClassA;  // OK because it is const
}
void testReassignConstRefToConstRefVar(void) {
	const MyClass &myClassA = MyClass();
	const MyClass &myClassB = myClassA;  // OK because both are const ref
}

//
// Test all combinations of "const" and "ref" to declare a variable for REASSIGNING a variable declared const (but no ref).
// Only the 2nd test (assigning a const ref var to a ref var) caused an error.
// Conclusion: Same as above.
//
void testReassignConstToVar(void) {
	const MyClass myClassA = MyClass();
	MyClass myClassB = myClassA; // OK
}
void testReassignConstToRefVar(void) {
	const MyClass myClassA = MyClass();
	//MyClass &myClassB = myClassA; // ERROR: invalid initialization of reference of type 'MyClass&' 
	                                // from expression of type 'const MyClass'
	
}
void testReassignConstToConstVar(void) {
	const MyClass myClassA = MyClass();
	const MyClass myClassB = myClassA;   // OK
}
void testReassignConstToConstRefVar(void) {
	const MyClass myClassA = MyClass();
	const MyClass &myClassB = myClassA;  // OK
}

//
// Test all combinations of "const" and "ref" to declare a variable for REASSIGNING a variable declared WITHOUT const nor ref.
// All tests are ok
//
void testReassignVarToVar(void) {
	MyClass myClassA = MyClass();
	MyClass myClassB = myClassA; // OK
}
void testReassignVarToRefVar(void) {
	MyClass myClassA = MyClass();
	MyClass &myClassB = myClassA;  // OK
}
void testReassignVarToConstVar(void) {
	MyClass myClassA = MyClass();
	const MyClass myClassB = myClassA;   // OK  
}
void testReassignVarToConstRefVar(void) {
	MyClass myClassA = MyClass();
	const MyClass &myClassB = myClassA;    // OK
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
	
	testReassignVarToVar();
	testReassignVarToRefVar();
	testReassignVarToConstVar();
	testReassignVarToConstRefVar();
	
	return 0;
}