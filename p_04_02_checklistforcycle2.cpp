#include <iostream>
#include <memory>

using namespace std;

template <typename T>
class List;


template <typename T>
class Node {
	friend class List<T>;
public:

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
	
	shared_ptr<Node<T>> checkForCycles(void) {
		
		shared_ptr<Node<T>> pCycleStart;
		
		shared_ptr<Node<T>> pFast = pFirst;
		shared_ptr<Node<T>> pSlow = pFirst;

		bool keepChecking = true;
		bool hasCycle = false;
		
		while (keepChecking) {
			if (pFast == nullptr || pFast->next == nullptr || pSlow == nullptr) {
				keepChecking = false;
			} else {
				pSlow = pSlow->next;
				pFast = pFast->next->next;
				if (pFast == pSlow) {
					hasCycle = true;
					keepChecking = false;
				}
			}
			
		}
		
		if (hasCycle) {
		
			int c = 0;
			do {
				pFast = pFast->next;
				c++;
			} while (pFast != pSlow);
			
			
			pFast = pFirst;
			pSlow = pFirst;
			while (c > 0) {
				pFast = pFast->next;
				c--;
			}

			while(pFast != pSlow) {
				pFast = pFast->next;
				pSlow = pSlow->next;
			}
			
			pCycleStart = pFast;
			
		}
			
		return pCycleStart;
	
		
	}
	
	void checkForCyclesAndPrint(void) {
		shared_ptr<Node<int>> pCycleStart = this->checkForCycles();
	
		if (pCycleStart == nullptr) {
			cout << "no cycle found" << endl;
		} else {
			cout << "cycle was found starting at: " << pCycleStart->data << endl;		
		}
	}
	
	void createCycle(int n) {
		shared_ptr<Node<T>> pNode = pFirst;
		int i = 0;
		while (i < n && pNode != nullptr){
			i++;
			pNode = pNode->next;
		}

		this->pLast->next = pNode;
	}
	
private:
	shared_ptr<Node<T>> pFirst;
	shared_ptr<Node<T>> pLast;
};


int main() {
		
	
	cout << "test a list without a cycle" << endl;
	List<int> list;
	list.append(0);
	list.append(1);
	list.append(2);
	list.append(3);
	list.append(4);
	list.append(5);
	list.append(6);
	list.print();	
	list.checkForCyclesAndPrint();
	
	
	cout << "test a list with a cycle" << endl;
	list.createCycle(4);
	list.checkForCyclesAndPrint();


	cout << "test a list with the first node looped" << endl;
	List<int> list2;
	list2.append(0);
	list2.createCycle(0);
	list2.checkForCyclesAndPrint();

		
	cout << "test an empty list" << endl;
	List<int> list1;
	list1.checkForCyclesAndPrint();
	
	return 0;
}