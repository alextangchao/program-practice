#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int base;
string change[20] = { "0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F","G","H","I","J" };

string convert(int n) {
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
	ifstream fin("palsquare.in");
	ofstream fout("palsquare.out");
	fin >> base;
	char str[100];
	string temp;
	for (int i = 1; i <= 300; ++i) {
		temp = convert(i*i);
		if (cal(temp)) {
			fout << convert(i) << " " << temp << endl;
		}
	}
	return 0;
}