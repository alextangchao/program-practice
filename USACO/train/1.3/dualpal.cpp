#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
int num, start;
vector<int> ans;
string change[10] = { "0","1","2","3","4","5","6","7","8","9" };

string convert(int n, int base) {
	string a = "";
	while (n > 0) {
		a = change[n%base] + a;
		n /= base;
	}
	return a;
}

bool cal(string a) {
	int n = a.size();
	for (int i = 0; i < n / 2; ++i) {
		if (a[i] != a[n - i - 1]) {
			return false;
		}
	}
	return true;
}

int main() {
	ifstream fin("dualpal.in");
	ofstream fout("dualpal.out");
	fin >> num >> start;
	int counts;
	for (int i = start + 1; ans.size() < num; ++i) {
		counts = 0;
		for (int k = 2; k <= 10; ++k) {
			if (cal(convert(i, k))) {
				++counts;
			}
			if (counts >= 2) {
				ans.push_back(i);
				break;
			}
		}
	}
	for (int i : ans) {
		fout << i << endl;
	}
	return 0;
}