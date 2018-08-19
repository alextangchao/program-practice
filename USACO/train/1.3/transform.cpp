#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
int n, same = 0;
vector<vector<char>> before, after, temp, ans;

void init() {
	before.resize(n);
	after.resize(n);
	temp.resize(n);
	ans.resize(n);
	for (int i = 0; i < n; ++i) {
		before[i].resize(n);
		after[i].resize(n);
		temp[i].resize(n);
		ans[i].resize(n);
	}
	return;
}

void turn() {
	for (int i = 0; i < n; ++i) {
		for (int k = 0; k < n; ++k) {
			ans[i][k] = temp[k][i];
		}
	}
	return;
}

void turnright() {
	temp = before;
	reverse(temp.begin(), temp.end());
	turn();
}

void turnover() {
	temp = ans;
	reverse(temp.begin(), temp.end());
	turn();
}

void turnleft() {
	temp = before;
	turn();
	reverse(ans.begin(), ans.end());
}

void reflection() {
	ans = before;
	for (int i = 0; i < n; ++i) {
		for (int k = 0; k < n / 2; ++k) {
			ans[i][k] = before[i][n - k - 1];
			ans[i][n - k - 1] = before[i][k];
		}
	}
}

bool judge() {
	return ans == after;
}

int main() {
	ifstream fin("transform.in");
	ofstream fout("transform.out");

	fin >> n;
	init();
	for (int i = 0; i < n; ++i) {
		for (int k = 0; k < n; ++k) {
			fin >> before[i][k];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int k = 0; k < n; ++k) {
			fin >> after[i][k];
		}
	}
	if (before == after) {
		same = 1;
	}
	turnright();
	if (judge()) {
		fout << 1 << endl;
		return 0;
	}
	turnover();
	if (judge()) {
		fout << 2 << endl;
		return 0;
	}
	turnleft();
	if (judge()) {
		fout << 3 << endl;
		return 0;
	}
	reflection();
	if (judge()) {
		fout << 4 << endl;
		return 0;
	}
	before = ans;
	turnright();
	if (judge()) {
		fout << 5 << endl;
		return 0;
	}
	turnover();
	if (judge()) {
		fout << 5 << endl;
		return 0;
	}
	turnleft();
	if (judge()) {
		fout << 5 << endl;
		return 0;
	}
	if (same) {
		fout << 6 << endl;
	}
	else {
		fout << 7 << endl;
	}
	return 0;
}