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
		pLeft->pParent = this;
		return pLeft;
	}
	
	std::shared_ptr<Node<T>> appendRight(T data) {
		pRight = std::shared_ptr<Node<T>>(new Node<T>(data));
		pRight->pParent = this;
		return pRight;
	}
	
	
	
	T data;
	std::shared_ptr<Node<T>> pLeft;
	std::shared_ptr<Node<T>> pRight;
	Node<T> *pParent;
};



template <typename T>
void o1InorderTraversal(std::shared_ptr<Node<T>> pNode) {
	Node<T> *pCurr = pNode.get();
	Node<T> *pPrev = nullptr;
	int i = 0;
	while (pCurr || pPrev) {
		if (i++ == 6) break;
		if (pCurr) {
			
			if (pPrev == pCurr->pParent) {
				cout << "go down further left" << endl;
				cout << pCurr->data << " " << endl;

				pPrev = pCurr;
				if (pCurr->pLeft.get()) {
					pCurr = pCurr->pLeft.get();
				} else {
					cout << "backing up" << endl;
					pCurr = pCurr->pParent;
				}
			} else if (pPrev == pCurr->pLeft.get()) {
				cout << "go down further right" << endl;
				cout << pCurr->data << " " << endl;
				pPrev = pCurr;
				if (pCurr->pRight.get()) {
					pCurr = pCurr->pRight.get();
				} else {
					cout << "backing up" << endl;
					pCurr = pCurr->pParent;
				}				
			} else if (pPrev == pCurr->pRight.get()) {
				cout << "go up" << endl;
				pPrev = pCurr;
				pCurr = pCurr->pParent;					
			}
			
		} else {
			cout << "a leaf" << endl;
			pCurr = pPrev->pParent;
			//pPrev = pCurr;
			//pCurr = pCurr->pParent;

		}
	}
	
}

/*
C:\work\coding_interview>bash -c "var=o1binarytreetraversal; g++ $var.cpp -o $va
r  -std=c++11 && ./$var.exe"
*/
int main(void) {

	std::shared_ptr<Node<int>> pN1 = std::shared_ptr<Node<int>>(new Node<int>(1));
	std::shared_ptr<Node<int>> pN1Left  = pN1->appendLeft(2);
	pN1Left->appendLeft(4);
	pN1Left->appendRight(5);
	std::shared_ptr<Node<int>> pN1Right = pN1->appendRight(3);
	pN1Right->appendLeft(6);
	pN1Right->appendRight(7);

	cout << endl << "O(1) inorder traverse" << endl;
	o1InorderTraversal(pN1);	
	return 0;
};