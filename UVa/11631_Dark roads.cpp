#define _CRT_SECURE_NO_DEPRECATE
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;
int allcost;
vector<vector<int>> dis;

class ufds {
public:
	vector<int> index, sizes;

	ufds(int n){
		sizes.assign(n, 1);
		index.resize(n);
		for (int i = 0; i < n; ++i)
			index[i] = i;
	}

	int root(int a) {
		while (index[a] != a) {
			index[a] = index[index[a]];
			a = index[a];
		}
		return a;
	}

	bool find(int a, int b) {
		return root(a) == root(b);
	}

	void unite(int a, int b) {
		a = root(a);
		b = root(b);
		if (a == b)
			return;
		if (sizes[a] < sizes[b]) {
			index[a] = b;
			sizes[b] += sizes[a];
		}
		else {
			index[b] = a;
			sizes[a] += sizes[b];
		}
	}
};

void clearall(int m) {
	allcost = 0;
	dis.clear();
}

void getnum(int n) {
	int a, b, c;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		allcost += c;
		dis.push_back({ c,a,b });
	}
	sort(dis.begin(), dis.end());
}

void cal(ufds store) {
	for (auto i : dis) {
		if (!store.find(i[1], i[2])) {
			store.unite(i[1], i[2]);
			allcost -= i[0];
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
#endif 
	int m, n;
	while (true) {
		scanf("%d%d", &m, &n);
		if (m == 0 && m == 0)
			return 0;
		ufds store = { m };
		clearall(m);
		getnum(n);
		cal(store);
		printf("%d\n", allcost);
	}
}