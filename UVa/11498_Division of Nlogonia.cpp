#include<iostream>
using namespace std;

int main() {
	int n,x,y,a,b;
	cin >> n;
	while (n) {
		cin >> x >> y;
		while (n--) {
			cin >> a >> b;
			if (a > x&&b > y)
				cout << "NE" << endl;
			if (a < x&&b > y)
				cout << "NO" << endl;
			if (a > x&&b < y)
				cout << "SE" << endl;
			if (a < x&&b < y)
				cout << "SO" << endl;
			if (a == x || b == y)
				cout << "divisa" << endl;
		}
		cin >> n;
	}
	return 0;
}