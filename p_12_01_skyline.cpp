#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool compareCoords (pair<int, int> coords1, pair<int, int> coords2) { return (coords1.first < coords2.first); }

void printSkyline(const vector<int> &leftCoords, const vector<int> &rightCoords, const vector<int> &heights) {
	
	vector<pair<int, int>> coords;
	
	for (int i = 0; i < leftCoords.size(); i++) {
		pair<int, int> coordsLeft = make_pair(leftCoords[i], heights[i]);
		pair<int, int> coordsRight = make_pair(rightCoords[i], -heights[i]);
		coords.push_back(coordsLeft);
		coords.push_back(coordsRight);
		
	}
	sort(coords.begin(), coords.end(), compareCoords);

	
    vector<int> sortedHeights;
    make_heap(sortedHeights.begin(), sortedHeights.end());
	
	int heightPrev = 0;
	
	for (int i = 0; i < coords.size(); i++) {
		pair<int, int> coord = coords[i];
		int x = coord.first;
		int height = coord.second;
		if (height > 0) {
			// a new building starting
			sortedHeights.push_back(height);
			push_heap(sortedHeights.begin(), sortedHeights.end());
		} else {
			// a building ending
			height = - height;
			std::vector<int>::iterator it = find(sortedHeights.begin(), sortedHeights.end(), height);
			// remove
			sortedHeights.erase(it);
			pop_heap(sortedHeights.begin(), sortedHeights.end());
		}
		
		int heightHighestBuilding = sortedHeights.size() > 0 ? sortedHeights.front() : 0;
		if (heightHighestBuilding != heightPrev) {
			heightPrev = heightHighestBuilding;
			cout << "coordinate: " << x << " height: " << heightHighestBuilding << endl;
		}
	}
}

int testCase1() {
	vector<int> leftCoords({1, 2});

	vector<int> rightCoords({3, 4});
	
	vector<int> heights({10, 11});
	
		
	printSkyline(leftCoords, rightCoords, heights);		
	cout << "expected: 10 11 11 0" << endl;
}

int testCase2() {
	vector<int> leftCoords({1, 2});

	vector<int> rightCoords({4, 3});
	
	vector<int> heights({10, 11});
	
		
	printSkyline(leftCoords, rightCoords, heights);	
	cout << "expected: 10 11 10 0" << endl;
	
}

int testCase3() {
	vector<int> leftCoords({1, 2});

	vector<int> rightCoords({4, 3});
	
	vector<int> heights({11, 10});
	
		
	printSkyline(leftCoords, rightCoords, heights);	
	cout << "expected: 11 11 11 0" << endl;
	
}


int main() { 

	testCase1();
	testCase2();
	testCase3();

		
	return 0;
}
