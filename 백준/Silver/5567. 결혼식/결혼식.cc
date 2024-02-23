#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> vec[510];
int dis[510];

void BFS(int x)
{
	queue<int> q;
	q.push(x);
	dis[x] = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < vec[now].size(); i++) {
			int nw = vec[now][i];
			if (dis[nw] > dis[now] + 1) {
				dis[nw] = dis[now] + 1;
				q.push(nw);
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
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	for (i = 0; i <= n; i++) dis[i] = 2e9;
	BFS(1);
	int ans = 0;
	for (i = 1; i <= n; i++) if (dis[i] <= 2) ans++;
	printf("%d", ans - 1);
	return 0;
}