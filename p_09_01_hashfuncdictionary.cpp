#include <iostream>
#include <string>

using namespace std;

unsigned int hashfunc(string s) {
	
	unsigned int value = 0;
	for (auto it = s.begin(); it != s.end(); it++) {
		char letter = (*it) - 'a';
		value = value*26 + letter;
	}
	
	return value;
}

int main() { 

	string word;

	word = "doughnut";
	cout << word << " : " << hashfunc(word) << endl;
	word = "doughnuty";
	cout << word << " : " << hashfunc(word) << endl;
	word = "doughnu";
	cout << word << " : " << hashfunc(word) << endl;
	word = "do";
	cout << word << " : " << hashfunc(word) << endl;
	word = "d";
	cout << word << " : " << hashfunc(word) << endl;
		
	return 0;
}