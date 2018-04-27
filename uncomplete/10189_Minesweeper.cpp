#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
vector<int> temp;
char place[110][110];
int num[110][110],n,m,order=1;

void add(int y, int x) {
	temp.push_back(y);
	temp.push_back(x);
	for (int i = -1; i < 2; i++) {
		if (y + i >= 0 && y + i < n) {
			for (int k = -1; k < 2; k++) {
				if (x + k >= 0 && x + k < m) {
					num[y + i][x + k] += 1;
				}
			}
		}
	}
}

int main() {
	while (cin >> n >> m) {
		if (n + m == 0)
			break;
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < m; k++) {
				cin >> place[i][k];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < m; k++) {
				if (place[i][k] == 42) {
					add(i, k);
				}
			}
		}	
		int i=0;
		while (i < temp.size()) {
			num[temp[i]][temp[i+1]] = 42;
			i += 2;
		}
		cout << "Field #" << order <<":"<< endl;
		order++;
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < m; k++) {
				if (num[i][k] == 42)
					cout << (char)num[i][k];
				else
					cout << num[i][k];
			}
			cout << endl;
		}
		cout << endl;
		for (int i = 0; i < n + 5; i++) {
			for (int k = 0; k < m + 5; k++) {
				num[i][k] = 0;
			}
		}
	}
	return 0;
}