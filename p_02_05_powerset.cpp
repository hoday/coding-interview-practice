#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

/**
 *   Problem: Print the power set of a set.
 *
 */

/**
 *  Prints a subset of the set that is specified by the bits in n.
 *  This is my solution to the problem.
 *  The time complexity of this function is O(n) where n is the 
 *  number if bits in the number representing the set. n is 2^N,
 *  where N is the size of the set.
 */
template <typename T>
void printSet(unsigned int n, vector<T> set) {
	cout << "(";
	int i = 0;
	while(n > 0) {
		if (n & 1) {
			cout << set[i];
			if (n != 1) {
				cout << ", ";
			}	
		}
		i++;
		n = n >> 1;
	}
	cout << ")";
	cout << endl;
}

/**
 *  Prints a subset of the set that is specified by the bits in n.
 *  This is the book's solution to the problem.
 *  The time complexity of this function is O(n) where n is the 
 *  number if bits in the number representing the set. n is 2^N,
 *  where N is the size of the set.but this algorithm. However,
 *  is faster than printSet1 above on average and in the best case.
 */
template <typename T>
void printSet2(unsigned int n, vector<T> set) {
	cout << "(";
	while(n > 0) {
		unsigned int i = log2(n & ~(n - 1)); // returns a number with only the bit that is the least-significant-1 set to a 1
		cout << set[i];
		if (n > (1 << i)) {
			cout << ", ";
		}	
		n = n & (n - 1); // switches the least-significant-1 to a zero.
	}
	cout << ")";
	cout << endl;
}

/**
 *  Prints the power set of a set.
 *  Time complexity is O(2^(2N)) (the outer loop time complexity is O(2^N)
 *  where N is the size of the set, and the inner loop time complexity 
 *  is also O(2^N).

 */
template <typename T>
void printPowerSet(vector<T> set) {
	unsigned int N = set.size(); // set must have less than or equal to 32 elements in this case.
	for (int n = 0; n < (1 << N); n++) {
		printSet2(n, set);
	}
}


int main() {
	
	vector<string> set = {"A", "B", "C"};
	
	printPowerSet(set);
	
	/*
	Result:
	()
	(A)
	(B)
	(A, B)
	(C)
	(A, C)
	(B, C)
	(A, B, C)
	*/
	
	//n & ~(n - 1) // returns a number with only the bit that is the least-significant-1 set to a 1
	//n & (n - 1)  // switches the least-significant-1 to a zero.
	
	return 0;
}