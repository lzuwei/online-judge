#include <algorithm>
#include <math.h>
#include <vector>
#include <iostream>
using namespace std;


/*
 * Complete the function below.
 */

int distanceFromLocker(int gridPosX, int gridPosY, int lockerX, int lockerY) {
	int distance = 0;
	distance += abs(lockerX - gridPosX);
	distance += abs(lockerY - gridPosY);
	return distance;
}

void printGrid(const vector< vector<int> >& grid) {
	for(size_t i = 0; i < grid.size(); ++i) {
		for(size_t j = 0; j < grid[i].size(); ++j) {
			cout << grid[i][j];
		}
		cout << endl;
	}
}

vector < vector < int > > getLockerDistanceGrid(int cityLength, int cityWidth, vector < int > lockerXCoordinates, vector < int > lockerYCoordinates) {

	vector< vector<int> > grid;

	//construct grid
	for (int i = 0; i < cityWidth; ++i)
		grid.push_back(vector<int>(cityLength));

	// for each entry on the grid, iterate through the locker coordinates and find the min distance
	for (size_t i = 0; i < grid.size(); ++i) {
		for(size_t j = 0; j < grid[i].size(); ++j) {
			int min = 100;
			for (size_t k = 0; k < lockerXCoordinates.size(); ++k) {
				int d = distanceFromLocker(j, i, lockerXCoordinates[k] - 1, lockerYCoordinates[k] - 1);
				if (d < min)
					min = d;
			}
			grid[i][j] = min;
		}
	}
	return grid;
}

int main() {
	vector<int> lockerX;
	vector<int> lockerY;
	lockerX.push_back(2);
	lockerX.push_back(4);
	lockerY.push_back(3);
	lockerY.push_back(7);
	vector < vector < int > > grid = getLockerDistanceGrid(5, 7, lockerX, lockerY);
	printGrid(grid);

	cout << endl;

	lockerX.clear();
	lockerY.clear();
	lockerX.push_back(1);
	lockerY.push_back(1);
	grid = getLockerDistanceGrid(3, 5, lockerX, lockerY);
	printGrid(grid);
}
