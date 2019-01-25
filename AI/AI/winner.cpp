#include "cell.h"
#include "wide_search.h"
#include <vector>
#include <iostream>

using namespace std;
extern int row;
extern vector<vector<int>> maps, closed;
extern vector<int> points;


void resetmap(int first, int second) {
	vector<int> temp;
	temp.assign(10, 0);
	for (int i = first; i <=  second; ++i) {
		temp[i] = 2;
	}
	maps[row - 1] = temp;
}

int getscore(cell &p) {
	shortest_path(p);
	return points[p.b - 2] - closed[p.a][p.b];
}

int ingame(int score_a, int score_b, int first, int second, int player, int deep) {
	if (second < first) {
		return (score_a >=  score_b) ? 1 : 2;
	}
	resetmap(first, second);
	int score = getscore(cell(9, first));
	int flag = ingame((player == 1) ? score_a + score : score_a, (player == 2) ? score_b + score : score_b, first + 1, second, ~player & 3, deep + 1);
	if (player==1 && flag == 1) {
		return 1;
	}
	if (player == 2 && flag == 2) {
		return 2;
	}
	resetmap(first, second);
	score = getscore(cell(9, second));
	int flags = ingame((player == 1) ? score_a + score : score_a, (player == 2) ? score_b + score : score_b, first, second - 1, ~player & 3, deep + 1);
	if (player == 2 && flag == flags == 1) {
		return 1;
	}
	return (player == 1) ? flags : 2;
}

int winner() {
	vector<int> store = maps[row - 1];
	int ans = ingame(0, 0, 2, 8, 1, 1);
	maps[row - 1] = store;
	return ans;
}