#include <iostream>
#include <memory>

using namespace std;

template <typename T>
class Node {
	
};


int main(void) {
	const shared_ptr<Node<int>> &pNodeA = make_shared<Node<int>>();
	const shared_ptr<Node<int>> &pNodeB = make_shared<Node<int>>();

	
	/*
	The second line below will produce this error:
	error: passing 'const std::shared_ptr<Node<int> >' 
	as 'this' argument of 
	'std::shared_ptr<_Tp>& std::shared_ptr<_Tp>::operator=(const std::shared_ptr<_Tp>&)
	[with _Tp = Node<int>]' 
	discards qualifiers [-fpermissive]
	*/
	//const shared_ptr<Node<int>> &pNode = pNodeA;
	//pNode = pNodeB;

	
	/*
	The following does NOT produce an error
	*/
	//shared_ptr<Node<int>> pNode = pNodeA;
	//pNode = pNodeB;
	
	/*
	The following DOES produce an error
	error: passing 'const std::shared_ptr<Node<int> >' 
	as 'this' argument of 
	'std::shared_ptr<_Tp>& std::shared_ptr<_Tp>::operator=(const std::shared_ptr<_Tp>&)
	[with _Tp = Node<int>]' 
	discards qualifiers [-fpermissive]
	*/
	//const shared_ptr<Node<int>> pNode = pNodeA;
	//pNode = pNodeB;
	
	/*
	The following DOES produce an error:
	invalid initialization of reference of type 'std::shared_ptr<Node<int> >&' 
	from expression of type 'const std::shared_ptr<Node<int> >'
	*/
	//shared_ptr<Node<int>> &pNode = pNodeA;
	//pNode = pNodeB;
	
	
	/*
	However the following does NOT produce the above error:
	(The definition of pNodeA2 and pNodeB2 is different)
	(Actually the below will work both for 
	pNode = pNodeB and pNode = pNodeB2. Only the first assignment makes a different as to whether an error is thrown).
	*/
	
	shared_ptr<Node<int>> pNodeA2 = make_shared<Node<int>>();
	shared_ptr<Node<int>> pNodeB2 = make_shared<Node<int>>();
	
	shared_ptr<Node<int>> &pNode = pNodeA2;
	pNode = pNodeB;	 // ok
	pNode = pNodeB2; // ok
	
	return 0;
}