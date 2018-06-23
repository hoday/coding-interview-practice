#include <iostream>
#include <memory>
#include <vector>

using namespace std;




class GroupChecker {
public:
	GroupChecker(const vector<vector<int>> & board, int i) : i(i), j(0), board(board) {} 
	virtual int getSquare() = 0;
	int getNextSquare(void) { int square = getSquare(); updateSquare(); return square;}
	bool updateSquare(void) {j++; }
	bool hasNextSquare(void) {return j < 9;}
	
	bool isValid(void) {
		unsigned int flags = 0;

		while (hasNextSquare()) {
			int x = getNextSquare();
				if (flags & (1 << x)) {
					return false;
				}
				flags |= (1 << x);
		}
		return true;
	}
protected:
	int i;
	int j;
	const vector<vector<int>> & board;
};

class RowChecker : public GroupChecker {
public:
	using GroupChecker::GroupChecker;
	//RowChecker(const vector<vector<int>> & board, int i) : BaseChecker(board, i) {}
	virtual int getSquare(void) override { return board[i][j]; }
};

class ColChecker : public GroupChecker {
public:
	using GroupChecker::GroupChecker;
	virtual int getSquare(void) override { return board[j][i]; }
	
};

class SqrChecker : public GroupChecker {
public:
	using GroupChecker::GroupChecker;
	virtual int getSquare(void) override { return board[3*(i/3) + j/3][i%3     + j % 3]; }
};


class GroupGenerator {
public:
	GroupGenerator(const vector<vector<int> > &board) : i(0), type(0), board(board) {}

	bool hasNextGroup(void) {
		if (type == 2 && !hasNextSubgroup()) {
			return false;
		}
		return true;
	}
	unique_ptr<GroupChecker> getNextGroup(void){
		if (!hasNextSubgroup()) {
			type++;
			i = 0;
		}
		return getNextSubgroup();

	}
	
protected:
	bool hasNextSubgroup(void) {
		return i < 9;
	}
	
	unique_ptr<GroupChecker> getNextSubgroup(void) {
		GroupChecker *pChecker;
		if (type == 0) {
			pChecker = new RowChecker(board, i);
		} else if (type == 1) {
			pChecker = new ColChecker(board, i);			
		} else {
			pChecker = new SqrChecker(board, i);
		}
		i++;
		return unique_ptr<GroupChecker>(pChecker);		
	}

	int type;
	int i;
	const vector<vector<int> > &board;
};

class SudokuChecker {
public:

	SudokuChecker(const vector<vector<int> > &board);
	bool check(void);
	
protected:
	vector<vector<int> > board;
};

SudokuChecker::SudokuChecker(const vector<vector<int> > &board) {
	this->board = board;
}

bool SudokuChecker::check(void) {

	GroupGenerator groupGenerator(board);

	while (groupGenerator.hasNextGroup()) {
		
		std::unique_ptr<GroupChecker> pGroup = groupGenerator.getNextGroup();
		if (!pGroup->isValid()) {
			return false;
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
		
	bool result1 = SudokuChecker(invalidBoard).check();
	bool result2 = SudokuChecker(validBoard).check();
	
	cout << result1 << endl;
	cout << result2 << endl;
	
	return 0;
}