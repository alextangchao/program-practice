#include<iostream>
#include<vector>

using namespace std;

// Weighted quick-union with path compression
class UFDS {
private:
	vector<int> index, size;
	int num;

	int root(int a) {
		while (index[a] != a) {
			index[a] = index[index[a]]; // path compression
			a = index[a];
		}
		return a;
	}

public:
	UFDS(int n) {
		index.assign(n, 0);
		size.assign(n, 1);
		num = n;
		for (int i = 0; i < n; i++)
			index[i] = i;
	}

	bool find(int a, int b) {
		return root(a) == root(b);
	}

	void unite(int a, int b) {
		a = root(a);
		b = root(b);
		if (a == b)
			return;
		if (size[a] < size[b]) {
			index[a] = b;
			size[b] += size[a];
		}
		else {
			index[b] = a;
			size[a] += size[b];
		}
	}
};

int main() {
	auto a = UFDS{ 10 };
	a.unite(3, 4);
	a.unite(4, 9);
	a.unite(8, 0);
	a.unite(2, 3);
	a.unite(5, 6);
	a.unite(5, 9);
	a.unite(7, 3);
	a.unite(8, 4);
	a.unite(6, 1);
	cout << a.find(0, 9) << endl;
}