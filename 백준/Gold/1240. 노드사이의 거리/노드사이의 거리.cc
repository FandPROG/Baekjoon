#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector <pair<int, int>> vec[1010];

int Dijkstra(int s, int e)
{
	int i, j;
	int dis[1010];
	priority_queue <pair<int, int>> pq;
	pq.push({ 0, s });
	for (i = 0; i <= n; i++) dis[i] = 2e9;
	dis[s] = 0;
	while (!pq.empty()) {
		int now_idx = pq.top().second, now_val = -pq.top().first;
		pq.pop();
		if (dis[now_idx] < now_val) continue;
		for (i = 0; i < vec[now_idx].size(); i++) {
			int idx = vec[now_idx][i].first, val = now_val + vec[now_idx][i].second;
			if (dis[idx] > val) {
				dis[idx] = val;
				pq.push({ -val, idx });
			}
		}
	}
	return dis[e];
}


int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n - 1; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		vec[x].push_back({ y, z });
		vec[y].push_back({ x, z });
	}
	for (i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%d\n", Dijkstra(x, y));
	}
	return 0;	
}