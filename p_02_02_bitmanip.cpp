#include <iostream>
#include <cstdint>

using namespace std;

/**
 *  Computes the parity of a long int
 *  Time complexity is proportional to number of bits in an int
 */
short parity1(unsigned long x) {
	short p = 0;
	while (x > 0) {
		p = p ^ (x & 1);
		x >>= 1;
	}
	return p;
}

/**
 *  Computes the parity of a long int
 *  Time complexity is proportional to number of bits in a long int.
 *  This algorithm is slightly faster than parity1 on average.
 */
short parity2(unsigned long x) {
	short p = 0;
	while (x > 0) {
		p = p ^ 1;
		x &= (x - 1);
	}
	return p;
}

const int PARITY_PRECOMPUTED_SIZE = 1 << 16; // number of shorts
short parityPrecomputedArray[PARITY_PRECOMPUTED_SIZE];
short parityPrecomputedFlags[PARITY_PRECOMPUTED_SIZE];

short parityPrecomputed(unsigned short x) {
	short result;
	if (parityPrecomputedFlags[x]) {
		result = parityPrecomputedArray[x];
	} else {
		result = parity2(x);
		parityPrecomputedArray[x] = result;
		parityPrecomputedFlags[x] = 1;
	}
	return result;
}

/**
 *  Computes the parity of a long int
 *  Time complexity is proportional to number of bits in a long int.
 *  This algorithm is made for use repeatedly when you need to compute the 
 *  parity of a large number of numbers and uses memoization
 */
short parity3(uint64_t x) {
	
	return 
		parityPrecomputed((x >> 48) & 0xFFFF) ^
		parityPrecomputed((x >> 32) & 0xFFFF) ^
		parityPrecomputed((x >> 16) & 0xFFFF) ^
		parityPrecomputed((x      ) & 0xFFFF);
	
}



int dropLsb(unsigned long x) {
	return x & (x - 1);
}

int main() {
	
	long x = 7; // 111
	//long x = 6; // 110
	//long x = 5; // 101 100
	
	std::cout << dropLsb(x) << std::endl;

	std::cout << parity1(x) << std::endl;
	
	std::cout << parity2(x) << std::endl;
	
	std::cout << parity3(x) << std::endl;
	
	return 0;
}