#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int week[7] = {0,0,0,0,0,0,0};

int cal(int begin,int month) {
	week[(13+begin) % 7] += 1;
	int last=(month+begin+1) % 7-1;
	if (last == -1)
		return 6;
	return last;
}

int main() {
	ofstream fout("friday.out");
	ifstream fin("friday.in");
	int n, begin = 0, month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	fin >> n;
	for (int i = 1900; i < 1900 + n; i++) {
		if (i % 100 == 0) {
			if (i % 400==0)
				month[1] = 29;
			else
				month[1] = 28;
		}
		else {
			if (i % 4 == 0)
				month[1] = 29;
			else
				month[1] = 28;
		}
		for (int k = 0; k < 12; k++) {
			begin=cal(begin,month[k]);
		}
	}
	fout << week[6] << " " << week[0] << " " << week[1] << " " << week[2] << " " << week[3] << " " << week[4] << " " << week[5] << endl;
	return 0;
}