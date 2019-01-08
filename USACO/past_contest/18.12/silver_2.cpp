#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

struct cell {
	int a, b, c;

	cell(int aa=0, int bb=0, int cc=0) {
		a = aa;
		b = bb;
		c = cc;
	}

	bool operator < (const cell &p) const {
		if (this->b == p.b) {
			if (this->a == p.a) {
				return this->c < p.c;
			}
			return this->a < p.a;
		}
		return this->b > p.b;
	}
};

int n, a, b, c,upper,lower,maxnum,index;
vector<cell> store;

bool cmp(cell a, cell b) {
	if (a.a == b.a) {
		return a.b < b.b;
	}
	return a.a < b.a;
}

void cal() {
	cell curr;
	priority_queue<cell> temp;
	temp.push(store[index]);
	++index;
	lower = temp.top().a;
	upper = lower + temp.top().c;
	int flag = 1;
	while (!temp.empty()) {
		if (flag) {
			flag = 0;
			temp.pop();
		}
		while (index<n && store[index].a <= upper ) {
			temp.push(store[index]);
			index++;
		}
		if (temp.empty()) {
			return;
		}
		curr = temp.top();
		temp.pop();
		maxnum = max(maxnum, abs(upper - curr.a));
		upper += curr.c;
		
	}
}

int main() {
	ifstream fin("convention2.in");
	ofstream fout("convention2.out");
	fin >> n;
	store.resize(n);
	for (int i = 0; i < n; ++i) {
		fin >> a >> b;
		store[i] = cell(a, i, b);
	}
	maxnum = 0;
	sort(store.begin(), store.end(), cmp);
	index = 0;
	while (index < n) {
		cal();
	}
	fout << maxnum << endl;
	fout.close();
	return 0;
}