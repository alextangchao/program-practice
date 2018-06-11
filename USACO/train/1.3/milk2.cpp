#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

struct aaa {
	int a;
	int b;
};

vector<aaa> store, num;

bool compare(aaa one, aaa two) {
	if (one.a != two.a)
		return one.a < two.a;
	return one.b > two.b;
}

void interval() {
	int aaa = 0;
	num.push_back(store[0]);
	for (auto &i : store) {
		int size = num.size();
		for (int k = 0; k < size; k++) {
			if (i.a <= num[k].b && i.b > num[k].b) {
				num[k].b = i.b;
				break;
			}
			else if (k == num.size() - 1 && i.a > num[k].b) {
				num.push_back({ i.a,i.b });
				break;
			}
		}
	}
}

int longestTime() {
	int ans = 0;
	for (auto i : num) {
		if ((i.b - i.a) > ans)
			ans = i.b - i.a;
	}
	return ans;
}

int longestIdle() {
	int ans = 0;
	for (int i = 0; i < num.size() - 1; i++) {
		if ((num[i + 1].a - num[i].b) > ans)
			ans = num[i + 1].a - num[i].b;
	}
	return ans;
}

int main() {
	ifstream fin("milk2.in");
	ofstream fout("milk2.out");
	int n, a, b;
	fin >> n;
	for (int i = 0; i < n; i++) {
		fin >> a >> b;
		store.push_back({ a,b });
	}
	sort(store.begin(), store.end(), compare);
	interval();
	cout << longestTime() << " " << longestIdle() << endl;
}