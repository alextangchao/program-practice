#define _CRT_SECURE_NO_DEPRECATE

#include<vector>
#include<queue>
#include<tuple>
#include<functional>
#include<algorithm>

using namespace std;
const int inf=2000000000;
typedef tuple<int, int> text;
priority_queue<text, vector<text>, greater<text>> heap;
vector<int> ans;
vector<bool> decide;
vector<int> dis;

void reset(int n);
void getnum(int m);
int dijk(int n, int m);
void findadj(int point, int next);
int getright(int a, int n, int m);
int getdown(int a, int n, int m);
int getup(int a, int n, int m);
int getleft(int a, int n, int m);

int main() {
	freopen("data.in", "r", stdin);
	int ns;
	scanf("%d", &ns);
	for (int p = 0; p < ns; p++) {
		int n, m;
		scanf("%d %d", &n, &m);
		reset(n*m);
		getnum(n*m);
		ans[0] = dis[0];
		int ans = dijk(n, m);
		printf("%d\n", ans);
	}
	return 0;
}

void reset(int n) {
	dis.clear();
	dis.resize(n);
	while (!heap.empty())
		heap.pop();
	ans.assign(n, inf);
	decide.assign(n, false);
	heap.push(make_tuple(0, 0));
}

void getnum(int n) {
	int a;
	for (int i = 0; i < n; i++) {
		scanf("%d", &dis[i]);
	}
}

int dijk(int n, int m) {
	while (heap.size() > 0) {
		int way = get<0>(heap.top());
		int point = get<1>(heap.top());
		if (point == n*m - 1) {
			return ans[n*m - 1];
		}
		heap.pop();
		decide[point] = true;
		findadj(point, getright(point,n,m));
		findadj(point, getdown(point, n, m));
		findadj(point, getup(point, n, m));
		findadj(point, getleft(point, n, m));
	}
	return ans[n*m-1];
}

void findadj(int point,int next) {
	if (next && !decide[next] && ans[point] + dis[next] < ans[next]) {
		ans[next] = ans[point] + dis[next];
		heap.push(make_tuple(ans[next], next));
	}
}

int getright(int a, int n, int m) {
	++a;
	return (a%m) ? a : 0;
}

int getdown(int a, int n, int m) {
	a += m;
	return (a < m*n) ? a : 0;
}

int getup(int a, int n, int m) {
	return max(0, a - m);
	
}
int getleft(int a, int n, int m) {
	return (a%m) ? a - 1 : 0;
}