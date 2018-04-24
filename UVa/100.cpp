#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

long long cal(long long a, long long b) {
	long long max = 0;
	for (long long i = a; i < b + 1; i++) {
		long long num = i, count = 1;
		while (num != 1) {
			count++;
			if (num % 2 == 0)
				num /= 2;
			else
				num = 3 * num + 1;
		}
		if (max < count)
			max = count;
	}
	return max;
}


int main() {
	long long begin, end;
	while (cin >> begin >> end) {
		cout << begin << " " << end << " " << cal(min(begin,end),max(begin,end)) << endl;
	}
	return 0;
}