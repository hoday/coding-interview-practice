#include <iostream>
#include <memory>

using namespace std;

template <typename T>
class List;


template <typename T>
class Node {
	friend class List<T>;
private:

	Node(T data) : data(data) {}
	
	void append(const T &data) {
		this->next.reset(new Node<T>(data));
	}

	T data;
	shared_ptr<Node<T>> next;
};


template <typename T>
class List {
public:
	
	List(void) : pLast(nullptr) {}

	void append(const shared_ptr<Node<T>> &node) {
		if (!pFirst) {
			pFirst = node;
		} else {
			pLast->next = node;
		}
		pLast = node;
	}
	
	void append(const T &data) {
		shared_ptr<Node<T>> pNode = shared_ptr<Node<T>>(new Node<T>(data));
		this->append(pNode);
	}
	

	
	void print(void) {
		Node<T> *pNode = pFirst.get();
		while(pNode) {
			cout << pNode->data << " ";
			pNode = pNode->next.get();
		}
		cout << endl;
	}
	
	void merge(List<T> &list) {
		shared_ptr<Node<T>> pNode1 = this->pFirst; // pNode1 and 2 have control of list heads now
		shared_ptr<Node<T>> pNode2 = list.pFirst;
		
		this->pFirst = nullptr;   // pFirst relinquished control of first node
		this->pLast = nullptr;
		
		list.pFirst = nullptr;
		list.pLast = nullptr;		
		
		while(pNode1 || pNode2) {

			shared_ptr<Node<T>> & pSnNext = (
				pNode1 && pNode2
					? (
						pNode1->data < pNode2->data
						? pNode1
						: pNode2
					)
					: (
						!pNode1
						? pNode2
						: pNode1
					)
			);
			
			this->append(pSnNext);
			pSnNext = pSnNext->next;


			pLast->next.reset();


		}
		
	}
	
private:
	shared_ptr<Node<T>> pFirst;
	shared_ptr<Node<T>> pLast;
};


int main() {
		
	List<int> list0;
	list0.append(0);
	list0.append(2);
	list0.append(4);
	list0.append(6);

	List<int> list1;
	list1.append(1);
	list1.append(3);
	list1.append(7);
	
	list0.print();
	list1.print();
	
	list0.merge(list1);
	
	list0.print();
	list1.print();
	
	
	cout << "last line in main" << endl;
	
	return 0;
}