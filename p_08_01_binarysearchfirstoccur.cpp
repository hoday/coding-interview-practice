#include <iostream>
#include <vector>

using namespace std;

template <typename T>
int find(const vector<T> &arr, T k) {
	int nLeft = 0;
	int nRight = arr.size();
	int nK = -1;
	while (nK == -1 && nRight > nLeft) {
		int n = nLeft + (nRight - nLeft) / 2;
		if (arr[n] == k && (n == 0 || arr[n-1] != k)) {
			nK = n;
		} else {
			if (k > arr[n]) {
				nLeft = n + 1;
			} else {
				nRight = n;
			}
		}
	}
	return nK;
}

int main() { 

	vector<int> arr({-14, -10, 2, 108, 108, 243, 285, 285, 285, 401});
	
	cout << "expected: 3, actual: " << find(arr, 108) << endl;
	
	cout << "expected: 6, actual: " << find(arr, 285) << endl;
	
	cout << "expected: 0, actual: " << find(arr, -14) << endl;
	cout << "expected: 9, actual: " << find(arr, 401) << endl;

	cout << "expected: -1, actual: " << find(arr, -15) << endl;
	cout << "expected: -1, actual: " << find(arr, 406) << endl;
	cout << "expected: -1, actual: " << find(arr, 77) << endl;
	
	return 0;
}