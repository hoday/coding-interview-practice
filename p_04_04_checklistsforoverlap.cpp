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
	
	shared_ptr<Node<T>> checkForOverlap(List<T> &list1) {
		
		cout << "before create cycle" << endl;
		list1.print();
		
		list1.pLast->next = list1.pFirst; 
		cout << "after create cycle: list1" << endl;
		
		//list1.print();
		
		cout << "after create cycle: list0" << endl;
		
		//this->print();

		
		shared_ptr<Node<T>> pOverlapStart = this->checkForCycles();
		return pOverlapStart;
	}
	
	void createOverlap(int n, List<T> &l) {
		shared_ptr<Node<T>> pNode = pFirst;
		int i = 0;
		while (i < n && pNode != nullptr){
			i++;
			pNode = pNode->next;
		}

		l.pLast->next = pNode;
		l.pLast = this->pLast;
	}
	
private:
	shared_ptr<Node<T>> pFirst;
	shared_ptr<Node<T>> pLast;
};


int main() {
		
	
	cout << "test a list without a cycle" << endl;
	List<int> list0;
	list0.append(0);
	list0.append(1);
	list0.append(2);
	list0.append(3);
	list0.append(4);
	list0.append(5);
	list0.append(6);
	list0.print();	
	
	List<int> list1;
	list1.append(30);
	list1.print();	
	
	list0.createOverlap(4, list1);
	
	cout << "list 0: " << endl;
	list0.print();
	cout << "list 1: " << endl;
	list1.print();
	
	shared_ptr<Node<int>> pOverlapStart = list0.checkForOverlap(list1);
	
		if (pOverlapStart == nullptr) {
			cout << "no overlap found" << endl;
		} else {
			cout << "overlap was found starting at: " << pOverlapStart->data << endl;		
		}
	return 0;
}