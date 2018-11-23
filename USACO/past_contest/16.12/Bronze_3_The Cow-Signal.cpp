#include<fstream>
#include<vector>
#include<iostream>

using namespace std;
int m, n, k;
vector<vector<char>> line;

int main() {
	ifstream fin("cowsignal.in");
	ofstream fout("cowsignal.out");
	fin >> m >> n >> k;
	line.resize(m*k);
	for (int i = 0; i < m; ++i) {
		line[i*k].resize(n*k);
		for (int j = 0; j < n; ++j) {
			fin >> line[i*k][j*k];
			for (int l = 1; l < k; ++l) {
				line[i*k][j*k + l] = line[i*k][j*k];
			}
		}
		for (int p = 1; p < k; ++p) {
			line[i*k + p] = line[i*k];
		}
	}
	for (auto i : line) {
		for (auto j : i) {
			fout << j;
		}
		fout << endl;
	}
	return 0;
}