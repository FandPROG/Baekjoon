#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, v, c;
vector <pair<int, int>> vec[110];
int dis[110][110];

void Dijkstra(int s, int x)
{
	int i, j;
	priority_queue < pair<int, int>> pq;
	for (i = 0; i <= v; i++) dis[x][i] = 2e9;
	dis[x][s] = 0;
	pq.push({ 0, s });
	while (!pq.empty()) {
		int nw = pq.top().second, val = -pq.top().first;
		pq.pop();
		if (dis[x][nw] < val) continue;
		for (i = 0; i < vec[nw].size(); i++) {
			int n_nw = vec[nw][i].first, n_val = val + vec[nw][i].second;
			if (dis[x][n_nw] > n_val) {
				dis[x][n_nw] = n_val;
				pq.push({ -n_val, n_nw });
			}
		}
	}
}

int main()
{
	int i, j, t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &v, &c);
		for (i = 0; i < c; i++) {
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			vec[x].push_back({ y, z });
			vec[y].push_back({ x, z });
		}
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			Dijkstra(x, i);
		}
		int ans, mn = 2e9;
		for (i = 1; i <= v; i++) {
			int sum = 0;
			for (j = 0; j < n; j++) sum += dis[j][i];
			if (mn > sum) {
				mn = sum;
				ans = i;
			}
		}
		printf("%d\n", ans);
		for (i = 1; i <= v; i++) vec[i].clear();
	}
	return 0;
}