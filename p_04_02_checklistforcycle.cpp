#include <iostream>
#include <memory>
#include <map>

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
		shared_ptr<Node<T>> pNode = pFirst;
		shared_ptr<Node<T>> pCycleStart;
		map<shared_ptr<Node<T>>, bool> visited;
		while (pNode != nullptr && pCycleStart == nullptr) {
			if (visited[pNode]) {
				pCycleStart = pNode;
			} else {
				visited[pNode] = true;			
				pNode = pNode->next;
			}
		}
		return pCycleStart;
	
		
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
		
	List<int> list;
	list.append(0);
	list.append(1);
	list.append(2);
	list.append(3);
	list.append(4);
	list.append(5);
	list.append(6);
	
	list.print();
	
	shared_ptr<Node<int>> pCycleStart = list.checkForCycles();
	
	if (pCycleStart == nullptr) {
		cout << "no cycle found" << endl;
	} else {
		cout << "cycle was found starting at: " << pCycleStart->data << endl;		
	}
	
	// create a cycle
	list.createCycle(4);

	pCycleStart = list.checkForCycles();

	
	if (pCycleStart == nullptr) {
		cout << "no cycle found" << endl;
	} else {
		cout << "cycle was found starting at: " << pCycleStart->data << endl;		
	}

	
	return 0;
}