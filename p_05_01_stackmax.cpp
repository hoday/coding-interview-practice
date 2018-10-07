#include <iostream>
#include <stack> //stack
#include <utility> //pair
#include <algorithm> // max
#include <stdexcept> //exception

using namespace std;

template <typename T>
class Stack {
public:
	void push(T t) {
		T prevMax = s.empty() ? t : std::max(t, s.top().second);
		pair<T,T> entry(t, prevMax);
		s.push(entry);
	}
	
	T pop(void) {
		pair<T,T> entry = s.top();
		s.pop();
		return entry.first;
	}
	
	const T &max(void) {
		if (s.empty()) {
			throw out_of_range("Stack is empty");
		} else {
			const T &val = std::max(s.top().first, s.top().second);
			return val;
		}
	}
	
	void print(void) {
		stack<pair<T,T>> s2;
		
		// unwind stack
		while(!s.empty()) {
			s2.push(s.top());
			s.pop();
		}
		// replace stack and print while replace
		while (!s2.empty()) {
			pair<T,T> entry = s2.top();
			s2.pop();
			cout << entry.first << " ";
			s.push(entry);
		}
		cout << endl;
	}
private:
	stack<pair<T,T>> s;
};




int main() {
		
	
	Stack<int> stack;
	
	stack.print();	
	try{
	cout << "max: " << stack.max() << endl << endl;
	} catch (exception &e) {
		cout << "exception caught: " << e.what() << endl;
	}
	
	
	stack.push(1);
	
	stack.print();	
	cout << "max: " << stack.max() << endl << endl;
	
	stack.push(100);
	stack.push(2);
	stack.push(300);
	stack.push(4);
	
	stack.print();	
	cout << "max: " << stack.max() << endl << endl;
	
	stack.pop();

	stack.print();	
	cout << "max: " << stack.max() << endl << endl;	
	
	stack.pop();

	stack.print();	
	cout << "max: " << stack.max() << endl << endl;
	
	stack.push(300);
	stack.print();	
	cout << "max: " << stack.max() << endl << endl;
		
	
	return 0;
}