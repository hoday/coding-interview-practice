#include <iostream>
#include <memory>
#include <limits>


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
void inorderTraversal(const std::shared_ptr<Node<T>> &pNode, T &prev, bool &res) {
	if (pNode) {
		inorderTraversal(pNode->pLeft, prev, res);
		if (!(prev < pNode->data)) {
			res = false;
		} else {
			prev = pNode->data;
		}
		inorderTraversal(pNode->pRight, prev, res);
	}
}

template <typename T>
bool isBinarySearchTree(const std::shared_ptr<Node<T>> &pNode) {
	T prev = numeric_limits<T>::min();
	bool res = true;
	inorderTraversal(pNode, prev, res);
	return res;
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
