#include<iostream>
#include<fstream>
#include<string>

using namespace std;
int main() {
	ofstream fout("ride.out");
	ifstream fin("ride.in");
	char name[2][6];
	string a, b;
	getline(fin,a);
	getline(fin,b);
	int one=1,two=1;
	for (int i = 0; i < a.size(); i++) {
		one *= (int)a[i] - 64;
	}
	for (int i = 0; i < b.size(); i++) {
		two *= (int)b[i] - 64;
	}
	one %= 47;
	two %= 47;
	if (one == two) {
		fout << "GO" << endl;
	}
	else {
		fout << "STAY" << endl;
	}
	return 0;
}
