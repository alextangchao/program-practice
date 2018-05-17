#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>

using namespace std;
int n;

int cal(string a) {
	int num = 0, k = 1, i;
	char last = a[0];
	while (last == 119) {
		last = a[k];
		k++;
	}
	for (i = 0; i < n; i++) {
		if (a[i] == last || a[i] == 119)
			num++;
		else
			break;
	}
	last = a[n - 1];
	k = n - 2;
	while (last == 119) {
		last = a[k];
		k--;
	}
	for (int j = n - 1; j >= i; j--) {
		if (a[j] == last || a[j] == 119)
			num++;
		else
			break;
	}
	return num;
}

int main() {
	ifstream fin("beads.in");
	ofstream fout("beads.out");
	string word, words;
	fin >> n >> word;
	int count = 0;
	for (int i = 0; i < n; i++) {
		words = word.substr(i) + word.substr(0, i);
		count = max(count, cal(words));
	}
	fout << count << endl;
	return 0;
}