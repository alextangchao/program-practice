	#include<iostream>
	#include<fstream>
	#include<string>
	using namespace std;
	
	struct people {
		string name;
		int money;

	}a[12];
	
	int main() {
		ofstream fout("gift1.out");
		ifstream fin("gift1.in");
		int n,place,money,num;
		string current,giver;
		fin >> n;
		for (int i = 0; i < n; i++) {
			fin >> a[i].name;
		}
		for (int i = 0; i < n; i++) {
			fin >> current>>money>>num;
			for (int i = 0; i < n; i++) {
				if (current == a[i].name) {
					place = i;
				}
			}
			for (int i = 0; i < num; i++) {
				fin >> giver;
				for (int i = 0; i < n; i++) {
					if (giver == a[i].name) {
						a[i].money += money / num;
						a[place].money -= money / num;
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			fout << a[i].name << " " << a[i].money << endl;
		}
		return 0;
	}
