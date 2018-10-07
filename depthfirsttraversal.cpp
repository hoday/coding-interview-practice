#include <iostream>
#include <memory>
#include <stack>
#include <vector>


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

/*
template <typename T>
void print(const std::shared_ptr<Node<T>> &pNode) {

	std::stack<std::shared_ptr<Node<T>>> s;
	s.push(pNode);
	
	
	while(!s.empty()) {
		
		std::shared_ptr<Node<T>> pCurr = s.top();
		s.pop();
		cout << pCurr->data << " ";
		
		//for (auto pChild : pCurr->pChildren) {
		for (std::vector<std::shared_ptr<Node<T>>>::reverse_iterator i = pCurr->pChildren.rbegin(); i != pCurr->pChildren.rend(); i++) {
			std::shared_ptr<Node<T>> pChild = *i;
			if (pChild) {
				s.push(pChild);
			}
		}
				
	}
	cout << endl;
	
	
}
*/


template <typename T>
void print(std::shared_ptr<Node<T>> pNode) {
	
	if (pNode) {
		cout << pNode->data << " ";
		for (auto pChild : pNode->pChildren) {
			print(pChild);
		}
		
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

	print(pN1);
	
	return 0;
};