#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int counts = 0, start = 0;
string n, temp, ans[20];
bool judge = true;
vector<string> names(5000);
ofstream fout("namenum.out");
vector<string> letter = { "A","B","C" ,"D","E","F" , "G","H","I" ,"J","K","L" , "M","N","O" , "P","R","S" , "T","U","V" ,"W","X","Y" };

bool cmp(string a) {
	for (int i = start; i < counts; ++i) {
		if (names[i] == a) {
			start = i;
			return true;
		}
		if (names[i] > a) {
			start = i;
			return false;
		}
	}
	return false;
}

void cal(int time) {
	if (time == n.size()) {
		temp = "";
		for (auto i : ans) {
			temp += i;
		}
		if (cmp(temp)) {
			judge = false;
			fout << temp << endl;
		}
		return;
	}
	int place = n[time] - '0' - 2;
	for (int i = place * 3; i < place * 3 + 3; ++i) {
		ans[time] = letter[i];
		cal(time + 1);
	}
}

int main() {
	ifstream fin("namenum.in");
	ifstream fins("dict.txt");

	fin >> n;
	fin.close();
	while (fins >> names[counts]) {
		++counts;
	}
	fins.close();
	cal(0);
	if (judge) {
		fout << "NONE" << endl;
	}
	fout.close();
	return 0;
}