#include <iostream>

using namespace std;

/**
 *  This algorithm adds two unsigned integers using only bit operations
 *  (only bit shifts and bitwise operations) (no logical comparisons)
 *  The time complexity is N where N is the number of bits in 
 *  the representation of the integer.
 */
unsigned int add(const unsigned &x, const unsigned &y) {
	
	unsigned int mask = 1;
	unsigned int c = 0;
	unsigned int sum = 0;
	while(mask) {
		unsigned int bit = mask & (x ^ y ^ c);
		sum |= bit;

		if (mask & c) {
			// if c has a 1 in this place,
			// if both x and y are 0: carry a 0
			// else:                  carry a 1
			c = mask & (x | y);
		} else {
			// if c has a 0 in this place,
			// if both x and y are 1: carry a 1
			// else:                  carry a 0
			c = mask & (x & y);
		}
		c <<= 1;
		mask <<= 1;
	}
	return sum;
	

}

/**
 *  Multiplies two numbers using only bit operations
 *  (only bit shifts and bitwise operations) (no logical comparisons)
 *  The time complexity is N where N is the number of bits in 
 *  the representation of the integer.
 *  
 */
unsigned int multiply(const unsigned int &x, const unsigned int &y) {
	unsigned int sum = 0;
	unsigned int xShift = x;
	unsigned int yShift = y;
	while(yShift) {
		if (yShift & 1) {
			sum = add(sum, xShift);
		}
		xShift <<= 1;
		yShift >>= 1;
	}
	return sum;
}

int main() {
	
	unsigned int x = 9;
	unsigned int y = 5;
	cout << multiply(x, y) << endl;
	
	return 0;
}