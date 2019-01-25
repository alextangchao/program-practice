#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<string>

using namespace std;

struct cell {
	int a;
	int b;

	cell(int a = 0, int b = 0) {
		this->a = a;
		this->b = b;
	}

	friend ostream &operator << (ostream &out, const cell &p) {
		out << "(" << p.a << " " << p.b << ")";
		return out;
	}

	bool operator < (const cell &p) const {
		return p.a > this->a;
	}

	bool operator == (const cell &p) const {
		return this->a == p.a && this->b == p.b;
	}
}target;

struct weight {
	int all, dis, cost;

	weight(int a = 0, int b = 0) {
		this->all = a + b;
		this->dis = a;
		this->cost = b;
	}

	bool operator < (const weight &p) const {
		if (this->all == p.all) {
			if (this->dis == p.dis) {
				return this->cost < p.cost;
			}
			return this->dis < p.dis;
		}
		return this->all < p.all;
	}


};


const int row = 10, col = 10;
int target_x = 0, target_y = 0;
vector<vector<int>> maps(row);
vector<int> points(7);
map<cell, weight> open;
vector<vector<cell>> closed(row);



void inputmap() {
	ifstream fin("map.txt");
	for (int i = 0; i < row; ++i) {
		maps[i].resize(col);
		closed[i].resize(col);
		for (int k = 0; k < col; ++k) {
			fin >> maps[i][k];
			closed[i][k] = cell(i, k);
		}
	}
}

void inputpoint() {
	ifstream fin("point.txt");
	for (int i = 0; i < 7; ++i) {
		fin >> points[i];
	}
}

bool achieve(cell &point) {
	return point == closed[point.a][point.b];
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

int getdis(int a, int b, int c, int d) {
	return abs(a - c) + abs(b - d);
}

cell findsmall() {
	cell ans;
	decltype(open.begin()) small = open.begin();
	for (auto i = open.begin(); i != open.end(); ++i) {
		if (i->second < small->second) {
			small = i;
		}
	}
	ans = small->first;
	open.erase(small);
	return ans;
}

void shortest_path() {
	open[cell()] = weight();
	cell curr;
	weight path;
	while (!open.empty()) {
		curr = findsmall();
		if (curr == target) {
			return;
		}
		for (cell point : getneighbour(curr)) {
			path = weight(getdis(point.a, point.b, target.a, target.b), getdis(point.a, point.b, 0, 0));
			if ((open.find(point) == open.end() || path < open[point]) && (maps[point.a][point.b] != 2 || (maps[point.a][point.b] == 2 && point == target))) {
				open[point] = path;
				closed[point.a][point.b] = curr;
			}
		}
	}
}

void print(vector<vector<int>> &p);

void correctpath(vector<vector<int>> &p) {
	cell curr = closed[target.a][target.b];
	closed[0][0] = cell();
	while (true) {
		if (curr == closed[curr.a][curr.b]) {
			break;
		}
		cerr << curr << endl;
		p[curr.a][curr.b] = 3;
		curr = closed[curr.a][curr.b];
	}
}

void printmap() {
	ofstream fout("ansmap.txt");
	vector<vector<int>> ans(maps);
	vector<vector<string>> direction(row);
	for (int i = 0; i < row; ++i) {
		direction[i].resize(col);
		for (int k = 0; k < col; ++k) {
			direction[i][k] = "";
			if (closed[i][k] == cell(i, k)) {
				continue;
			}
			ans[i][k] = -1;
		}
	}
	for (auto i = open.begin(); i != open.end(); ++i) {
		ans[i->first.a][i->first.b] = 3;
	}
	correctpath(ans);
	for (int i = 0; i < row; ++i) {
		for (int k = 0; k < col; ++k) {
			fout << ans[i][k] << " ";
		}
		fout << endl;
	}
	print(ans);
}

void print(vector<vector<int>> &p) {
	for (auto i : p) {
		for (auto k : i) {
			cerr << k;
		}
		cerr << endl;
	}
	cerr << endl;
}

void print(vector<vector<cell>> &p) {
	for (auto i : p) {
		for (auto k : i) {
			cerr << k;
		}
		cerr << endl;
	}
}

void print(vector<cell> &p) {
	for (auto i : p) {
		cerr << i;
	}
	cerr << endl;
}

int main() {
	inputmap();
	inputpoint();
	target = cell(9, 2);
	shortest_path();
	//print(getneighbour(cell(1,8)));
	printmap();
	print(closed);
	system("Pause");
	return 1;
}
