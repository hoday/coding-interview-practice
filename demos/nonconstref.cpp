#include <iostream>
#include <string>

using namespace std;

/*
 * A function with an argument passed in as a non-constant reference
 */
void nonConstRef(string & s){
	cout << s << endl;
}

/*
 * A function with an argument passed in as a constant reference
 */
void constRef(const string & s){
	cout << s << endl;
}

int main() {
	
	//
	// 1. Attempt to call both functions with an rvalue as the parameter.
	//
	
	//nonConstRef(string("abc")); // illegal
	constRef(string("abc")); // legal
	
	//
	// 2. Attempt to call both functions with an lvalue as the parameter.
	//
	
	string s = string("abc");
	
	nonConstRef(s); // legal
	constRef(s); // legal
	
	
	// The first call produces this error: 
	// invalid initialization of non-const reference of type 
	// 'std::string& {aka std::basic_string<char>&}' 
	// from an rvalue of type 
	// 'std::string {aka std::basic_string<char>}'
	// This error is thrown because the argument is an rvalue, not lvalue.	
	
	return 0;
}