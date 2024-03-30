#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

vector <pair<int, int>> vec1[510], vec2[510];
int dis[510], check[510][510], ans[510];
int ch[510];

void Dijkstra(int s)
{
	int i, j;
	priority_queue <pair<int, int>> q;
	q.push({ 0, s });
	dis[s] = 0;
	while (!q.empty()) {
		int nidx = q.top().second, nval = -q.top().first;
		q.pop();
		if (dis[nidx] < nval) continue;
		for (i = 0; i < vec1[nidx].size(); i++) {
			int idx = vec1[nidx][i].first, val = nval + vec1[nidx][i].second;
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
	while (1) {
		int n, m;
		int s, e;
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) break;
		scanf("%d %d", &s, &e);
		for (i = 0; i < m; i++) {
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			vec1[x].push_back({ y, z });
			vec2[y].push_back({ x, z });
		}
		for (i = 0; i < n; i++) ans[i] = 2e9, dis[i] = 2e9;
		Dijkstra(s);
		queue <int> q;
		q.push(e);
		ch[e] = 1;
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (i = 0; i < vec2[now].size(); i++) {
				int idx = vec2[now][i].first, val = vec2[now][i].second;
				if (dis[idx] + val == dis[now]) {
					if (ch[idx] == 0) {
						ch[idx] = 1;
						q.push(idx);
					}
					check[idx][now] = 1;
				}
			}
		}
		priority_queue <pair<int, int>> pq;
		pq.push({ 0, s });
		ans[s] = 0;
		while (!pq.empty()) {
			int nidx = pq.top().second, nval = -pq.top().first;
			pq.pop();
			if (ans[nidx] < nval) continue;
			for (i = 0; i < vec1[nidx].size(); i++) {
				int idx = vec1[nidx][i].first, val = nval + vec1[nidx][i].second;
				if (check[nidx][idx] == 1) continue;
				if (ans[idx] > val) {
					ans[idx] = val;
					pq.push({ -val, idx });
				}
			}
		}
		if (ans[e] == 2e9) printf("-1\n");
		else printf("%d\n", ans[e]);
		for (i = 0; i <= n; i++) ch[i] = 0, vec1[i].clear(), vec2[i].clear();
		for (i = 0; i <= n; i++) {
			for (j = 0; j <= n; j++) {
				check[i][j] = 0;
			}
		}
	}
	return 0;
}