#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include "wide_search.h"
#include "cell.h"

using namespace std;

extern int n, row, col, inf;
extern vector<vector<int>> maps, closed;
extern vector<int> points;
extern vector<vector<cell>> path;
cell target; // the target cell


void resetdis() {
	for (int i = 0; i < row; ++i) {
		closed[i].assign(col, inf);
	}
}

bool achieve(cell &point) {
	if (maps[point.a][point.b] == 2) {
		return point == target;
	}
	return maps[point.a][point.b] != 1 && closed[point.a][point.b] == inf;
}

vector<cell> getneighbour(cell &point) {
	vector<cell> neighour;
	if (point.a - 1 >= 0 && maps[point.a - 1][point.b] != 1 && achieve(cell(point.a - 1, point.b))) {
		neighour.push_back(cell(point.a - 1, point.b));
	}
	if (point.a + 1 < row && maps[point.a + 1][point.b] != 1 && achieve(cell(point.a + 1, point.b))) {
		neighour.push_back(cell(point.a + 1, point.b));
	}
	if (point.b - 1 >= 0 && maps[point.a][point.b - 1] != 1 && achieve(cell(point.a, point.b - 1))) {
		neighour.push_back(cell(point.a, point.b - 1));
	}
	if (point.b + 1 < col && maps[point.a][point.b + 1] != 1 && achieve(cell(point.a, point.b + 1))) {
		neighour.push_back(cell(point.a, point.b + 1));
	}
	return neighour;
}

void shortest_path(cell &p) {
	target = p;
	queue<cell> open; //points wait to search
	open.push(cell(0, 0));
	resetdis();
	closed[0][0] = 0;
	while (!open.empty()) {
		cell curr = open.front();
		open.pop();
		for (cell i : getneighbour(curr)) {
			closed[i.a][i.b] = closed[curr.a][curr.b] + 1;
			path[i.a][i.b] = curr;
			if (i == target) {
				return;
			}
			open.push(i);
		}
	}
}

void correctpath(vector<vector<int>> &p) {
	cell curr = path[target.a][target.b];
	p[0][0] = 3;
	while (curr != path[curr.a][curr.b]) {
		p[curr.a][curr.b] = 3;
		curr = path[curr.a][curr.b];
	}
}

void printmap() {
	ofstream fout("ansmap.txt");
	vector<vector<int>> ans=maps;

	correctpath(ans); //add the path from start to target

	// output the map
	for (int i = 0; i < row; ++i) {
		for (int k = 0; k < col; ++k) {
			fout << ans[i][k] << " ";
		}
		fout << endl;
	}
}

void wide_search(cell &p) {
	shortest_path(p);
	printmap();
	return;
}
