#include <iostream>
#include <memory>
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
void print(std::shared_ptr<Node<T>> pNode) {
	cout << "ttt" << endl;

	std::queue<std::shared_ptr<Node<T>>> q;
	q.push(pNode);
	
	
	while(!q.empty()) {
		
		std::shared_ptr<Node<T>> pCurr = q.front();
		q.pop();
		cout << pCurr->data << " ";
		
		if (pCurr->pLeft) {
			q.push(pCurr->pLeft);
		}
		if (pCurr->pRight) {
			q.push(pCurr->pRight);
		}
				
	}
	cout << endl;
	
	
}

template <typename T>
class BinaryTree {
public:
		
private:
	std::shared_ptr<Node<T>> pHead;
};

void foo(void) {
	cout << "eee" << endl;
}
template <typename T>
void foo2(std::shared_ptr<Node<T>> pHead) {
	cout << "eee2" << pHead->data << endl;
}

int main(void) {

	std::shared_ptr<Node<int>> pN1 = std::shared_ptr<Node<int>>(new Node<int>(1));
	std::shared_ptr<Node<int>> pN1Left  = pN1->appendLeft(2);
	pN1Left->appendLeft(4);
	pN1Left->appendRight(5);
	std::shared_ptr<Node<int>> pN1Right = pN1->appendRight(3);
	pN1Right->appendLeft(6);
	pN1Right->appendRight(7);

	cout << "print" << endl;


	print(pN1);
	cout << "done" << endl;
	
	return 0;
};