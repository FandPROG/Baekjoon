#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector <pair<int, int>> vec[50010];
int dis[50010];

void Dijkstra(int s)
{
	priority_queue <pair<int, int>> pq;
	pq.push({ 0, s });
	dis[s] = 0;
	while (!pq.empty()) {
		int nidx = pq.top().second, nval = -pq.top().first;
		pq.pop();
		if (dis[nidx] < nval) continue;
		for (int i = 0; i < vec[nidx].size(); i++) {
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
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) dis[i] = 2e9;
	for (i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		vec[x].push_back({ y, z });
		vec[y].push_back({ x, z });
	}
	Dijkstra(1);
	printf("%d", dis[n]);
	return 0;
}