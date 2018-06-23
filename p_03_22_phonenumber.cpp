#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<string> getAllNumbers(const string &phoneNumber, map<char, vector<char>> &phonePad) {
	
	vector<string> partials;
	vector<string> completes;
	partials.push_back("");
	
	while (!partials.empty()) {
		string partial = partials[partials.size() - 1];
		partials.pop_back();
		cout << "visit: " << partial << endl;
		if (partial.size() == phoneNumber.length()) {
			// transfer to finished list
			cout << "complete: " << partial << endl;
			completes.push_back(partial);
		} else {
			char digit = phoneNumber[partial.length()];
			cout << "next digit: " << digit << endl;
			vector<char> letters = phonePad.at(digit);
			//vector<char> letters;
			//vector<char> letters = phonePad[digit];
			// for each letter, append it to the partial phone number
			for (auto it = letters.crbegin(); it != letters.crend(); it++) {
				char letter = *it;
				cout << "next letter: " << letter << endl;
				// put the partial phone number in the queue
				partials.push_back(partial + letter);
			}
		}
	}
	return completes;
}


int main() {
	map<char,vector<char>> phonePad;
	
	phonePad['0'] = vector<char>({});
	phonePad['1'] = vector<char>({});
	phonePad['2'] = vector<char>({'a', 'b', 'c'});
	phonePad['3'] = vector<char>({'d', 'e', 'f'});
	phonePad['4'] = vector<char>({'g', 'h', 'i'});
	phonePad['5'] = vector<char>({'j', 'k', 'l'});
	phonePad['6'] = vector<char>({'m', 'n', 'o'});
	phonePad['7'] = vector<char>({'p', 'q', 'r', 's'});
	phonePad['8'] = vector<char>({'t', 'u', 'v'});
	phonePad['9'] = vector<char>({'w', 'x', 'y', 'z'});
	
		
	vector<string> words = getAllNumbers("22", phonePad);

	for (auto word : words) {
		cout << word << endl;
	}
	
	return 0;
}