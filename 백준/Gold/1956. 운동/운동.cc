#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int dis[410], v, e;
vector <pair<int, int>> vec[410];
int arr[410][410];

void Dijkstra(int s)
{
	int i, j;
	for (i = 1; i <= v; i++) dis[i] = 2e9;
	priority_queue<pair<int, int>> q;
	q.push({ 0, s });
	dis[s] = 2e9;
	while (!q.empty()) {
		int nidx = q.top().second, nval = -q.top().first;
		q.pop();
		if (dis[nidx] < nval) continue;
		for (i = 0; i < vec[nidx].size(); i++) {
			int idx = vec[nidx][i].first, val = nval + vec[nidx][i].second;
			if (dis[idx] > val) {
				dis[idx] = val;
				q.push({ -val, idx });
			}
		}
	}
}

int main()
{
	int i, j;
	scanf("%d %d", &v, &e);
	for (i = 0; i <= v; i++) {
		for (j = 0; j <= v; j++) {
			arr[i][j] = 2e9;
		}
	}
	for (i = 0; i < e; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		arr[x][y] = min(arr[x][y], z);
	}
	for (i = 1; i <= v; i++) {
		for (j = 1; j <= v; j++) {
			if (arr[i][j] == 2e9) continue;
			vec[i].push_back({ j, arr[i][j]});
		}
	}
	int ans = 2e9;
	for (i = 1; i <= v; i++) {
		Dijkstra(i);
		ans = min(ans, dis[i]);
	}
	if (ans == 2e9) printf("-1");
	else printf("%d", ans);
	return 0;
}