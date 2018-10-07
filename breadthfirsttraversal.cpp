#include <iostream>
#include <memory>
#include <queue>
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

template <typename T>
void print(const std::shared_ptr<Node<T>> &pNode) {

	std::queue<std::shared_ptr<Node<T>>> q;
	q.push(pNode);
	
	
	while(!q.empty()) {
		
		std::shared_ptr<Node<T>> pCurr = q.front();
		q.pop();
		cout << pCurr->data << " ";
		
		for (auto pChild : pCurr->pChildren) {
			if (pChild) {
				q.push(pChild);
			}
		}
				
	}
	cout << endl;
	
	
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