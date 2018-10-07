#include <iostream>
#include <memory>
#include <stack>
#include <vector>
#include <queue>


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
	std::shared_ptr<Node<T>> pLeft;
	std::shared_ptr<Node<T>> pRight;
};


template <typename T>
void preorderTraversal(std::shared_ptr<Node<T>> pNode) {
	
	if (pNode) {
		cout << pNode->data << " ";
		preorderTraversal(pNode->pLeft);
		preorderTraversal(pNode->pRight);
		
	}
}

template <typename T>
void postorderTraversal(std::shared_ptr<Node<T>> pNode) {
	
	if (pNode) {
		postorderTraversal(pNode->pLeft);
		postorderTraversal(pNode->pRight);
		cout << pNode->data << " ";
		
	}
}

template <typename T>
void inorderTraversal(std::shared_ptr<Node<T>> pNode) {
	
	if (pNode) {
		inorderTraversal(pNode->pLeft);
		cout << pNode->data << " ";
		inorderTraversal(pNode->pRight);
	}
}


int main(void) {

	std::shared_ptr<Node<int>> pN1 = std::shared_ptr<Node<int>>(new Node<int>(1));
	std::shared_ptr<Node<int>> pN1Left  = pN1->appendLeft(2);
	pN1Left->appendLeft(4);
	pN1Left->appendRight(5);
	std::shared_ptr<Node<int>> pN1Right = pN1->appendRight(3);
	pN1Right->appendLeft(6);
	pN1Right->appendRight(7);

	cout << endl << "preorder traverse" << endl;
	preorderTraversal(pN1);
	cout << endl << "postorder traverse" << endl;
	postorderTraversal(pN1);
	cout << endl << "inorder traverse" << endl;
	inorderTraversal(pN1);	
	return 0;
};