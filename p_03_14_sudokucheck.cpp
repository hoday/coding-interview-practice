#include <iostream>
#include <vector>

using namespace std;

bool checkSudoku(const vector<vector<int> > &board) {
	int n = 9;
	for (int check = 0; check < 3; check++) {

		for (int i = 0; i < n; i++) {
			unsigned int flags = 0;
			for (int j = 0; j < n; j++) {
				int x;
				switch (check) {
					case 0:
						x = (board[i][j]);
						break;
					case 1:
						x = (board[j][i]);
						break;
					default:
						int row = 3*(i/3) + j/3;
						int col = i%3     + j % 3;
						x = (board[row][col]);
						break;
				}
				if (flags & (1 << x)) {
					return false;
				}
				flags |= (1 << x);
			}
		}
	}
	return true;
}


int main() {
	
	vector<vector<int>> invalidBoard = vector<vector<int>>({
		vector<int>({1,2,3,4,5,6,7,8,9}),
		vector<int>({1,2,3,4,5,6,7,8,9}),
		vector<int>({1,2,3,4,5,6,7,8,9}),
		vector<int>({1,2,3,4,5,6,7,8,9}),
		vector<int>({1,2,3,4,5,6,7,8,9}),
		vector<int>({1,2,3,4,5,6,7,8,9}),
		vector<int>({1,2,3,4,5,6,7,8,9}),
		vector<int>({1,2,3,4,5,6,7,8,9}),
		vector<int>({1,2,3,4,5,6,7,8,9})
	});
	
		vector<vector<int>> validBoard = vector<vector<int>>({
		vector<int>({1,2,3,4,5,6,7,8,9}),
		vector<int>({4,5,6,7,8,9,1,2,3}),
		vector<int>({7,8,9,1,2,3,4,5,6}),
		vector<int>({9,1,2,3,4,5,6,7,8}),
		vector<int>({3,4,5,6,7,8,9,1,2}),
		vector<int>({6,7,8,9,1,2,3,4,5}),
		vector<int>({8,9,1,2,3,4,5,6,7}),
		vector<int>({2,3,4,5,6,7,8,9,1}),
		vector<int>({5,6,7,8,9,1,2,3,4})
	});
		
	bool result1 = checkSudoku(invalidBoard);
	bool result2 = checkSudoku(validBoard);
	
	cout << result1 << endl;
	cout << result2 << endl;
	
	return 0;
}