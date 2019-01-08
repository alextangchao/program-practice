#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<queue>
#include<map>
#include<algorithm>


using namespace std;
int n, k, base, col, flag, endflag;
char maps[100][100];
vector<vector<int>> clean(10);

void test() {
	for (int i = 0; i < n; ++i) {
		for (int k = 0; k < 10; ++k) {
			cerr << maps[i][k] << " ";
		}
		cerr << endl;
	}
}

void tests(vector<int> &a) {
	for (int i : a) {
		cerr << i << " ";
	}
	cerr << endl;
}

struct cell {
	int a;
	int b;
	
	cell(int c, int d) {
		a = c;
		b = d;
	}

	bool operator < (const cell &p) const {
		if (this->a == p.a) {
			return this->b < p.b;
		}
		return this->a < p.a;
	}

};

vector<cell> neigh(cell &p) {
	vector<cell> temp;
	//cerr << p.b + 1 << n << endl;
	if (p.b + 1 < 10) {
		//cerr << "in" << endl;
		temp.push_back(cell(p.a, p.b + 1));
	}
	if (p.b > 0) {
		temp.push_back(cell(p.a, p.b - 1));
	}
	if (p.a + 1 < n) {
		temp.push_back(cell(p.a + 1, p.b));
	}
	if (p.a > 0) {
		temp.push_back(cell(p.a - 1, p.b));
	}
	return temp;
}

void throwall(vector<cell> &a) {
	for (cell i : a) {
		clean[i.b].push_back(i.a);
	}
}

void findgrass(int a, int b) {
	map < cell, int > visit;
	queue<cell> temp;
	temp.push(cell(a, b));
	cell curr = cell(0, 0);
	vector<cell> back;
	char color = maps[a][b];
	while (!temp.empty()) {	
		curr = temp.front();
		temp.pop();
		visit[curr] = 1;
		back.push_back(curr);	
		for (cell i : neigh(curr)) {
			if (maps[i.a][i.b] == color && visit[i]==0) {
				temp.push(cell(i.a, i.b));
				visit[i] = 1;
			}
		}
	}
	if (back.size() >= k) {
		endflag = 1;
		throwall(back);
	}
	return;
}

bool cmp(int a, int b) {
	return b < a;
}

void movedown() {
	int place;
	for (int i = 0; i < 10; ++i) {
		if (clean[i].size() == 0) {
			continue;
		}
		sort(clean[i].begin(), clean[i].end(),cmp);
		place = clean[i][0];
		for (int k = clean[i][0]; k >= 0; --k) {
			while (find(clean[i].begin(), clean[i].end(), k) != clean[i].end()) {
				--k;
			}
			if (maps[k][i] == '0') {
				break;
			}
			maps[place][i] = maps[k][i];
			--place;
		}
		// need speed up
		for (int k = place; k >= 0; --k) {
			maps[k][i] = '0';
		}
	}
}



int main() {
	ifstream fin("mooyomooyo.in");
	ofstream fout("mooyomooyo.out");
	fin >> n >> k;
	for (int i = 0; i < n; ++i) {
		for (int k = 0; k < 10; ++k) {
			fin >> maps[i][k];
		}
	}
	endflag = 1;
	int aaa = 0;
	while (endflag) {
		++aaa;
		clean.clear();
		clean.resize(10);
		base = 0;
		endflag = 0;
		for (int i = base; i < n; ++i) {
			flag = 1;
			for (int k = 0; k < 10; ++k) {
				if (maps[i][k] != '0') {
					findgrass(i, k);
					flag = 0;
				}
			}
			if (flag) {
				++base;
			}
		}
		movedown();
	}
	

	for (int i = 0; i <n; ++i) {
		for (int k = 0; k < 10; ++k) {
			fout << maps[i][k];
		}
		fout << endl;
	}
	fout.close();
	return 0;
}