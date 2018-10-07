#include <iostream>

using namespace std;


void foo(int i) {
	cout << "foo(int)" << endl << endl;
}


// It will not compile at all when this function exists
// ERROR: Redefinition of void foo(int)
/*
void foo(const int i) {
	cout << "foo(const int)" << endl << endl;
}
*/


void foo(int &i) {
	cout << "foo(&int)" << endl << endl;
}


void foo(const int &i) {
	cout << "foo(const &int)" << endl << endl;
}


void foo(int &&i) {
	cout << "foo(&&int)" << endl << endl;
}


void foo(const int &&i) {
	cout << "foo(const &&int)" << endl << endl;
}


int main(void) {
	int i = 4;
	// Produces the following error: foo(int) is ambiguous. candidates are:
	// (5 candidats)
	// foo(int)
	// foo(int&)
	// foo(const int&)
	// foo(int&&) <near match>
	// foo(const int&&) <near match>
	// Only one of the above can coexist at a time.
	//foo(i);
	
	// Produces the following error: foo(int) is ambiguous. candidates are:
	// (4 candidats)
	// foo(int)
	// foo(const int&)
	// foo(int&&)
	// foo(const int&&)
	// Only one of the above can coexist at a time.
	//foo(5);
	return 0;
}