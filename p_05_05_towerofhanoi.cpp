#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

std::vector<stack<int>> stacks(3);

unsigned int getOther(unsigned int src, unsigned int dest) {
	
	//cout << ((1U<<3) - 1U) << endl;
	//cout << ~((1U << src) | (1U << dest)) << endl;
	//cout << (((1U<<3) - 1U) & ~((1U << src) | (1U << dest))) << endl;
	//cout <<  log2(((1U<<3) - 1U) & ~((1U << src) | (1U << dest))) << endl;
	unsigned int other = (((1U<<3) - 1U) & ~((1U << src) | (1U << dest)));
	unsigned int i = 0;
	while (other) {
		other >>= 1;
		i++;
	}
	return i-1;
}

void transfer(int n, int src, int dest, int via) {
	if (n==1) {
		cout << "move ring from " << " tower " << src << " to " << " tower " << dest << endl;
		int ring = stacks[src].top();
		stacks[src].pop();
		stacks[dest].push(ring);
	} else {
		transfer(n-1, src, via, dest);
		transfer(1, src, dest, via);
		transfer(n-1, via, dest, src);
		
		
	}
}


int main(void) {
	stacks[0].push(3);
	stacks[0].push(2);
	stacks[0].push(1);
	
	transfer(3, 0, 1, 2);
	
	return 0;
}