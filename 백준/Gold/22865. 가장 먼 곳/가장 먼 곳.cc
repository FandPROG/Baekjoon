#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;
priority_queue <pair<int, int>> pq;
int dis[100010];
vector <pair<int, int>> vec[100010];

void Dijkstra()
{
	int i, j;
	while (!pq.empty()) {
		int nidx = pq.top().second, nval = -pq.top().first;
		pq.pop();
		if (dis[nidx] < nval) continue;
		for (i = 0; i < vec[nidx].size(); i++) {
			int idx = vec[nidx][i].first, val = nval + vec[nidx][i].second;
			if (dis[idx] > val) {
				dis[idx] = val;
				pq.push({ -val, idx });
			}
		}
	}
}

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) dis[i] = 2e9;
	for (i = 0; i < 3; i++) {
		int x;
		scanf("%d", &x);
		pq.push({ 0, x });
		dis[x] = 0;
	}
	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		vec[x].push_back({ y, z });
		vec[y].push_back({ x, z });
	}
	Dijkstra();
	int ans, mx = -2e9;
	for (i = 1; i <= n; i++) {
		if (mx < dis[i]) {
			mx = dis[i];
			ans = i;
		}
	}
	printf("%d", ans);
	return 0;
}