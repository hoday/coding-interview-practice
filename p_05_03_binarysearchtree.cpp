#include <iostream>
#include <memory>
#include <stack>

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
void sort (const shared_ptr<Node<T>> &pTop) {
	
	//
	// Stack s holds nodes that need to be printed and whose right-hand trees need to be explored.
	// Every time a node is popped from this stack, the node is first printed, and then current node is set to the right-hand side.
	//
	stack<shared_ptr<Node<int>>> s;
	
	
	shared_ptr<Node<T>> pNode = pTop;
	//s.push(pTop);
	
	cout << "stack size:" << s.size() << endl;
	int i = 0;
	while(!s.empty() || pNode) {
		
		if (i++ == 10) break;
		
		if (pNode) {			
			cout << "current node: " << pNode->data << " " << endl;
			s.push(pNode);
			cout << "pNode " << pNode->data << " pushed onto stack" << endl;
			cout << "stack size: " << s.size() << endl;			
			pNode = pNode->pLeft;
			if (pNode) cout << "pNode incremented to left: " << pNode->data << endl;
		} else {
			cout << "pNode was empty" << endl;

			pNode = s.top();
			s.pop();
			cout << "pNode " << pNode->data << " popped from stack" << endl;
			cout << "stack size: " << s.size() << endl;	
			cout << "pNode data: " << pNode->data << "****" << endl;
			
			pNode = pNode->pRight;
			if (pNode) cout << "pNode incremented to right: " << pNode->data << endl;

		}
		
		cout << "---" << endl;
	}
	
}


int main() { 

	cout << "Binary search tree: should print: " << "1 3 4 5" << endl;
	shared_ptr<Node<int>> n1 = shared_ptr<Node<int>>(new Node<int>(5));
	shared_ptr<Node<int>> n2 = n1->appendLeft(3);
	shared_ptr<Node<int>> n3 = n2->appendLeft(1);
	shared_ptr<Node<int>> n4 = n2->appendRight(4);

	
	sort(n1);
	
	
	return 0;
}