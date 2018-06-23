#include <iostream>
#include <string>
#include <stdexcept> 

using namespace std;


string uintToString(unsigned int x) {
	string s = string();
	while (x > 0) {
		unsigned int digit = x % 10;
		char c = '0' + digit;
		s.insert(s.begin(), c);
		x = x / 10;
	}
	if (s.empty()) {
		s.push_back('0');
	}
	return s;	
}

/**
 *  Converts an int to a string.
 *  It works for negative numbers as well.
 *  The time complexity is n where n is log10 of the input number
 *  (so basically log n where n is the number).
 */
string intToString(int x) {
	bool isNegative = false;
	if (x < 0){
		isNegative = true;
		x = -x;
	}
	string s = uintToString(x);
	if (isNegative) {
		s.insert(s.begin(), '-');
	}
	return s;
}

/**
 *  Converts a string to an int.
 *  It works for negative numbers as well.
 *  It throws an exception if the string is an invalid int.
 *  The time complexity is n where n is the length of the string.
 */
int stringToInt(const string & s){
	bool isNegative = (s[0] == '-');
	int number = 0;
	for (string::const_iterator it = isNegative ? s.begin() + 1 : s.begin(); it != s.end(); it++) {
		char c = *it;
		if (isdigit(c)) {
			int digit = c - '0';
			number = number * 10 + digit;
		} else {
			throw invalid_argument("illegal input");
		}
	}
	if (isNegative) {
		number = -number;
	}
	return number;
}

int main() {
	cout << intToString(-22) << endl;
	cout << stringToInt("-22") << endl;
	
	return 0;
}