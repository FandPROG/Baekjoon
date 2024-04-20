#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int s, e;
vector <pair<int, int>> vec[200010];
int dis[200010], dise[2000010], ch[200010];
int dis2[200010];
int ans = 0;

void SDijkstra()
{
	int i, j;
	priority_queue <pair<int, int>> pq;
	pq.push({ 0, s });
	dis[s] = 0;
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

void EDijkstra()
{
	int i, j;
	priority_queue <pair<int, int>> pq;
	pq.push({ 0, e });
	dise[e] = 0;
	while (!pq.empty()) {
		int nidx = pq.top().second, nval = -pq.top().first;
		pq.pop();
		if (dise[nidx] < nval) continue;
		for (i = 0; i < vec[nidx].size(); i++) {
			int idx = vec[nidx][i].first, val = nval + vec[nidx][i].second;
			if (dise[idx] > val) {
				dise[idx] = val;
				pq.push({ -val, idx });
			}
		}
	}
}

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		vec[x].push_back({ y, z });
		vec[y].push_back({ x, z });
	}
	for (i = 1; i <= n; i++) {
		dis[i] = 2e9, dis2[i] = 2e9, dise[i] = 2e9;
	}
	scanf("%d %d", &s, &e);
	SDijkstra();
	EDijkstra();
	int x = s;
	ans += dis[e];
	vector <int> widx;
	while (x != e) {
		int mn = 2e9;
		for (i = 0; i < vec[x].size(); i++) {
			int idx = vec[x][i].first, val = vec[x][i].second;
			if (dis[e] == dis[x] + val + dise[idx]) {
				mn = min(mn, idx);
			}
		}
		x = mn;
		widx.push_back(x);
	}
	for (i = 0; i < widx.size() - 1; i++) ch[widx[i]] = 1;
	priority_queue <pair<int, int>> pq;
	pq.push({ 0, e });
	dis2[e] = 0;
	while (!pq.empty()) {
		int nidx = pq.top().second, nval = -pq.top().first;
		pq.pop();
		if (dis2[nidx] < nval) continue;
		for (i = 0; i < vec[nidx].size(); i++) {
			int idx = vec[nidx][i].first, val = nval + vec[nidx][i].second;
			if (ch[idx] == 1) continue;
			if (dis2[idx] > val) {
				dis2[idx] = val;
				pq.push({ -val, idx });
			}
		}
	}
	ans += dis2[s];
	printf("%d", ans);
	return 0;
}