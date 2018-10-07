#include <iostream>
#include <memory>

using namespace std;

template <typename T>
class Node {
public:
	Node(T data) : data(data) { }

	std::shared_ptr<Node<T>> appendLeft(T data) {
		pLeft = std::shared_ptr<Node<T>>(new Node<T>(data));
		return pLeft;
	}
	
	std::shared_ptr<Node<T>> appendRight(T data) {
		pRight = std::shared_ptr<Node<T>>(new Node<T>(data));
		return pRight;
	}
	
	T data;
	std::shared_ptr<Node<T>> pLeft, pRight;
	
};

template <typename T>
T getMin(const std::shared_ptr<Node<T>> &pNode) {
	// pNode must not be null.
	T dataMin = pNode->data;
	if (pNode->pRight) {
		dataMin = min(dataMin, getMin(pNode->pRight)); 
	}
	if (pNode->pLeft) {
		dataMin = min(dataMin, getMin(pNode->pLeft)); 
	}	
	return dataMin;
}

template <typename T>
T getMax(const std::shared_ptr<Node<T>> &pNode) {
	// pNode must not be null.
	T dataMax = pNode->data;
	if (pNode->pRight) {
		dataMax = max(dataMax, getMax(pNode->pRight)); 
	}
	if (pNode->pLeft) {
		dataMax = max(dataMax, getMax(pNode->pLeft)); 
	}	
	return dataMax;
}

template <typename T>
bool isBinarySearchTree(const std::shared_ptr<Node<T>> &pNode) {
	if (!pNode) {
		return true;
	} else {	
		return 
		(!pNode->pRight || pNode->data <= getMin(pNode->pRight)) &&
		(!pNode->pLeft  || pNode->data >= getMax(pNode->pLeft))  &&
		(!pNode->pRight || isBinarySearchTree(pNode->pRight)) &&
		(!pNode->pLeft  || isBinarySearchTree(pNode->pLeft));
	}

}


int main() { 

	std::shared_ptr<Node<int>> pNull = std::shared_ptr<Node<int>>(nullptr);

	cout << "null tree: expected:true, actual: " << isBinarySearchTree(pNull) << endl;

	std::shared_ptr<Node<int>> pN1 = std::shared_ptr<Node<int>>(new Node<int>(3));
	
	
	cout << "one-node tree: expected:true, actual: " << isBinarySearchTree(pN1) << endl;

	std::shared_ptr<Node<int>> pN2 = pN1->appendLeft(1);
	
	cout << "two-node tree: expected:true, actual: " << isBinarySearchTree(pN1) << endl;

	std::shared_ptr<Node<int>> pN3 = pN1->appendRight(5);
	
	cout << "three-node balanced tree: expected:true, actual: " << isBinarySearchTree(pN1) << endl;
	
	std::shared_ptr<Node<int>> pN4 = pN3->appendLeft(2);
	cout << "not a binary search tree: expected:false, actual: " << isBinarySearchTree(pN1) << endl;

		
	return 0;
}
