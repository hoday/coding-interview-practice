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
	
	void append(T data) {
		this->next.reset(new Node<T>(data));
	}

	T data;
	shared_ptr<Node<T>> next;
};


template <typename T>
class List {
public:
	
	List(void) : pLast(nullptr) {}

	void append(T data) {
		if (!pFirst) {
			pFirst.reset(new Node<T>(data));
			pLast = pFirst.get();
		} else {
			pLast->next.reset(new Node<T>(data));
			pLast = pLast->next.get();
		}
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
		
		this->pFirst.reset();   // pFirst relinquished control of first node
		this->pLast = nullptr;
		
		list.pFirst.reset();
		list.pLast = nullptr;		
		
		
		while(pNode1 || pNode2) {
			shared_ptr<Node<T>> *pSnNext;
			if (!pNode1) {
				pSnNext = &pNode2;
			} else if (!pNode2) {
				pSnNext = &pNode1;
				
			} else {
				if (pNode1->data < pNode2->data) {
					pSnNext = &pNode1;

				} else {
					pSnNext = &pNode2;

				}
			}
			
			if (!pFirst) {
				pFirst = *pSnNext;
				pLast = pFirst.get();
			} else {
				// append pNext node to node pointed to be pLast
				pLast->next = *pSnNext;
				pLast = pLast->next.get();	


			}
			
			//this->append(*pSnNext);

			*pSnNext = (*pSnNext)->next;
			pLast->next.reset();

		}
		
		
		

		
		
	}
	
private:
	shared_ptr<Node<T>> pFirst;
	Node<T> *pLast;
	
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
	
	list1.merge(list0);
	
	list0.print();
	list1.print();
	
	list0.merge(list1);
	
	list0.print();
	list1.print();
	 
	
	cout << "last line in main" << endl;
	
	return 0;
}