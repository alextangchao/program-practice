#include "wide_search.h"
#include "cell.h"
#include "winner.h"
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;
int n = 7, row = 10, col = 10, inf = 1000000000;
// 0 represent blank cell
// 1 represent barrier
// 2 represent point cell
// 3 repersent the cell is in shortest path
vector<vector<int>> maps(row); // store the map
vector<vector<int>> closed(row); // cost from start point
vector<int> points(n); // store the points
vector<vector<cell>> path(row); // store the last cell position



void inputmap() {
	ifstream fin("map.txt");
	for (int i = 0; i < row; ++i) {
		maps[i].resize(col);
		path[i].resize(col);
		closed[i].assign(col, inf);
		for (int k = 0; k < col; ++k) {
			fin >> maps[i][k];
			path[i][k] = cell(i, k);
		}
	}
}

void inputpoint() {
	ifstream fin("point.txt");
	for (int i = 0; i < 7; ++i) {
		fin >> points[i];
	}
}


int main() {
	inputmap();
	inputpoint();

	// cal the winner of game
	// 1 represent robot 1 win
	// 2 represent robot 2 win
	int a = winner();
	cout << "the winner is robot " << a << endl;

	// cal and ouput the shortest path to target point
	// cell(9,2) represent leftmost point cell
	// cell(9,8) represent rightmost point cell
	cell target = cell(9, 8);
	wide_search(target);
	cout << "the shortest distance to " << target << " is " << closed[target.a][target.b] << endl;
	system("python ui.py"); // visualize the shortest path by python,the map is "shortest_path.jpg"
	system("pause");
}