#include <iostream>
#include <vector>

using namespace std;

/**
 *  Rearranges the elements in A such that elements smaller than A[i]
 *  appear first, then elements equal to A[i], then elements greater than A[i].
 *  Time complexity is N where N is the length of the array.
 *  Space complexity is 1.
 */
template <typename T>
void dutchFlagSort1(vector<T> &a, int i) {
	int ai = a[i];
	
	int n = a.size();
	
	int k1 = 0;
	int k2 = 0;

	for (int j = k2; j < n; j++) {
		if (a[j] < ai) {
			swap(a[j], a[k1]);
			swap(a[j], a[k2]);
			k1++;
			k2++;			
		} else if (a[j] > ai) {
		} else {
			swap(a[j], a[k2]);
			k2++;			
		}
	}
}


/**
 *  Rearranges the elements in A such that elements smaller than A[i]
 *  appear first, then elements equal to A[i], then elements greater than A[i].
 *  Time complexity is N where N is the length of the array.
 *  Space complexity is 1.
 */
template <typename T>
void dutchFlagSort2(vector<T> &a, int i) {
	int ai = a[i];
	
	int n = a.size();

	                           // [0,                 kEqualToBegin)          contains elements less than
	int kEqualToBegin = 0;     // [kEqualToBegin,     kUnsortedBegin) contains elements equal to
	int kUnsortedBegin = 0;    // [kUnsortedBegin,    kGreaterThanBegin) contains unsorted
	int kGreaterThanBegin = n; // [kGreaterThanBegin, n)  contains elements greater than

	while (kUnsortedBegin < kGreaterThanBegin) {
		if (a[kUnsortedBegin] == ai) {
			kUnsortedBegin++;	
		} else if (a[kUnsortedBegin] < ai) {
			swap(a[kUnsortedBegin++], a[kEqualToBegin++]);		
		} else {
			swap(a[kUnsortedBegin], a[--kGreaterThanBegin]);
		}
	}
}

template <typename T>
void printArray(vector<T> &a) {
	int n = a.size();
	for (int k = 0; k < n; k++) {
		cout << a[k] << " ";
	}
	cout << endl;
}


int main() {
	vector<int> a = vector<int>({2, 3, 1, 3, 5, 3, 3, 4, 6, 3, 0});
	dutchFlagSort2(a, 1);
	printArray(a);
	
	return 0;
}