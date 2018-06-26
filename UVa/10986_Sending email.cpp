#define _CRT_SECURE_NO_DEPRECATE

#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<map>
#include<functional>
#include<algorithm>

using namespace std;
const int inf=1000000000;
typedef tuple<int, int> text;
priority_queue<text,vector<text>,greater<text>> heap;
vector<int> ans;
vector<bool> decide;
map<int,map<int,int>> dis;
map<text, int> minroad;

void clearall(int n, int s) {
	dis.clear();
	minroad.clear();
	while (!heap.empty())
		heap.pop();
	ans.assign(n, inf);
	ans[s] = 0;
	decide.assign(n, false);
	heap.push(make_tuple(0, s));
}

void getnum(int m) {
	int a, b, c;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (dis[a][b] == 0 && minroad[make_tuple(min(a, b), max(a, b))] == 0) {
			dis[a][b] = c;
			dis[b][a] = c;
		}
		else if (c < dis[a][b]) {
			dis[a][b] = c;
			dis[b][a] = c;
		}
	}
}

void findadj(int point) {
	for (auto i = dis[point].begin(); i != dis[point].end(); i++) {
		if (decide[i->first] == false && ans[point] + i->second < ans[i->first]) {
			ans[i->first] = ans[point] + i->second;
			heap.push(make_tuple(ans[i->first], i->first));
		}
	}
}

int dijk(int t) {
	while (heap.size() > 0) {
		int way = get<0>(heap.top());
		int point = get<1>(heap.top());
		if (point == t) {
			return way;
		}
		heap.pop();
		decide[point] = true;
		findadj(point);
	}
	return ans[t];
}

int main() {
	freopen("data.in", "r", stdin);
	int ns;
	scanf("%d", &ns);
	
	for (int p = 0; p < ns; p++) {
		int n, m, s, t;
		scanf("%d %d %d %d", &n, &m, &s, &t);
		clearall(n, s);
		getnum(m);
		int ans = dijk(t);
		if (ans == inf)
			printf("Case #%d: unreachable\n", p + 1);
		else
			printf("Case #%d: %d\n", p + 1 , ans);
	}
	return 0;
}
