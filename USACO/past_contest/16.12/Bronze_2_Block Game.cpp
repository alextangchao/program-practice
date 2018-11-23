#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>

using namespace std;
int n;
vector<int> num(26, 0), x(26, 0), y(26, 0);
string a, b;

void cal(string a, vector<int> &temp) {
	temp.assign(26, 0);
	int m = a.size();
	for (int i = 0; i < m; ++i) {
		++temp[a[i] - 'a'];
	}
}

int main() {
	ifstream fin("blocks.in");
	ofstream fout("blocks.out");
	fin >> n;
	for (int i = 0; i < n; ++i) {
		fin >> a >> b;
		cal(a, x);
		cal(b, y);
		for (int k = 0; k < 26; ++k) {
			num[k] += max(x[k], y[k]);
		}
	}
	for (int k = 0; k < 26; ++k) {
		fout << num[k] << endl;
	}
	return 0;
}