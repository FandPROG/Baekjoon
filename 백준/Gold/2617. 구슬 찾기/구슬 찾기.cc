#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int n, m;
vector <int> vec1[100], vec2[100];
int dis1[100], dis2[100];
int ch[100];

void BFS1(int x)
{
	int i;
	queue<int> q;
	q.push(x);
	ch[x] = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (auto i : vec1[now]) {
			if (ch[i] == 0) {
				ch[i] = 1;
				q.push(i);
			}
		}
	}
}

void BFS2(int x)
{
	int i;
	queue<int> q;
	q.push(x);
	ch[x] = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (auto i : vec2[now]) {
			if (ch[i] == 0) {
				ch[i] = 1;
				q.push(i);
			}
		}
	}
}

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		vec1[x].push_back(y);
		vec2[y].push_back(x);
	}
	for (i = 1; i <= n; i++) {
		BFS1(i);
		int cnt = 0;
		for (j = 1; j <= n; j++) if (i != j && ch[j] == 1) cnt++;
		dis1[i] = cnt;
		for (j = 1; j <= n; j++) ch[j] = 0;
	}
	for (i = 1; i <= n; i++) {
		BFS2(i);
		int cnt = 0;
		for (j = 1; j <= n; j++) if (i != j && ch[j] == 1) cnt++;
		dis2[i] = cnt;
		for (j = 1; j <= n; j++) ch[j] = 0;
	}
	int ans = 0;
	int mid = (n + 1) / 2;
	for (i = 1; i <= n; i++) {
		if (mid <= dis1[i] || mid <= dis2[i]) ans++;
	}
	printf("%d", ans);
	return 0;
}