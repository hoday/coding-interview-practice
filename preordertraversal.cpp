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
	
	std::shared_ptr<Node<T>> appendChild(T data) {
		pChildren.push_back(std::shared_ptr<Node<T>>(new Node<T>(data)));
		return pChildren.back();
	}
	
	T data;
	std::vector<std::shared_ptr<Node<T>>> pChildren;
};


template <typename T>
void preorderTraversal(std::shared_ptr<Node<T>> pNode) {
	
	if (pNode) {
		cout << pNode->data << " ";
		for (auto pChild : pNode->pChildren) {
			preorderTraversal(pChild);
		}
		
	}
}

template <typename T>
void postorderTraversal(std::shared_ptr<Node<T>> pNode) {
	
	if (pNode) {
		for (auto pChild : pNode->pChildren) {
			postorderTraversal(pChild);
		}
		cout << pNode->data << " ";
		
	}
}

template <typename T>
void inorderTraversal(std::shared_ptr<Node<T>> pNode) {
	
	if (pNode) {
		std::shared_ptr<Node<T>> pLeftChild = pNode->pChildren.size() > 0 ? pNode->pChildren[0] : nullptr;
		std::shared_ptr<Node<T>> pRightChild = pNode->pChildren.size() > 1 ? pNode->pChildren[1] : nullptr;
		inorderTraversal(pLeftChild);
		cout << pNode->data << " ";
		inorderTraversal(pRightChild);
	}
}


int main(void) {

	std::shared_ptr<Node<int>> pN1 = std::shared_ptr<Node<int>>(new Node<int>(1));
	std::shared_ptr<Node<int>> pN1Left  = pN1->appendChild(2);
	pN1Left->appendChild(4);
	pN1Left->appendChild(5);
	std::shared_ptr<Node<int>> pN1Right = pN1->appendChild(3);
	pN1Right->appendChild(6);
	pN1Right->appendChild(7);

	cout << endl << "preorder traverse" << endl;
	preorderTraversal(pN1);
	cout << endl << "postorder traverse" << endl;
	postorderTraversal(pN1);
	cout << endl << "inorder traverse" << endl;
	inorderTraversal(pN1);	
	return 0;
};