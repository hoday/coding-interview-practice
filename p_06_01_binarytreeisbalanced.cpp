#include <iostream>
#include <memory>
#include <stack>
#include <stdlib.h>

using namespace std;

template <typename T>
class Node {
public:
	Node(T data) : data(data) {}
	
	shared_ptr<Node<T>> appendLeft(T data) {
		this->pLeft = shared_ptr<Node<T>>(new Node<T>(data)); 
		return (this->pLeft);
	}
	
	shared_ptr<Node<T>> appendRight(T data) {
		this->pRight = shared_ptr<Node<T>>(new Node<T>(data)); 
		return (this->pRight);
	}
	shared_ptr<Node<T>> pLeft;
	shared_ptr<Node<T>> pRight;
	T data;
};

template <typename T>
bool isBalanced (const shared_ptr<Node<T>> &pTop) {
	
	if (!pTop) {
		return true;
	} else {
		return abs(height(pTop->pLeft) - height(pTop->pRight)) <= 1;
	}
	
}

template <typename T>
int height(const shared_ptr<Node<T>> &pTop) {
	
	if (!pTop) {
		return 0;
	} else {
		return 1 + max(height(pTop->pLeft), height(pTop->pRight));
	}	
	
}


int main() { 

	shared_ptr<Node<int>> n1 = shared_ptr<Node<int>>(new Node<int>(5));
	shared_ptr<Node<int>> n2 = n1->appendLeft(3);
	shared_ptr<Node<int>> n3 = n2->appendLeft(1);
	shared_ptr<Node<int>> n4 = n2->appendRight(4);
	
	cout << "isBalanced: expected: false, actual: " <<  isBalanced(n1) << endl;
		
	shared_ptr<Node<int>> n5 = n1->appendRight(5);
	
	cout << "isBalanced: expected: true, actual: " <<  isBalanced(n1) << endl;
	
	
	return 0;
}