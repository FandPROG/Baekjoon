#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int k;
vector <pair<int, int>> vec[1010];
priority_queue <int> dis[1010];

void Dijkstra(int s)
{
	int i, j;
	priority_queue <pair<int, int>> q;
	q.push({ 0, s });
	dis[s].push(0);
	while (!q.empty()) {
		int nidx = q.top().second, nval = -q.top().first;
		q.pop();
		for (i = 0; i < vec[nidx].size(); i++) {
			int idx = vec[nidx][i].first, val = nval + vec[nidx][i].second;
			if (dis[idx].size() >= k) {
				int nw = dis[idx].top();
				if (nw > val) {
					dis[idx].pop();
					dis[idx].push(val);
					q.push({ -val, idx });
				}
			}
			else {
				dis[idx].push(val);
				q.push({ -val, idx });
			}
		}
	}
}

int main()
{
	int i, j;
	scanf("%d %d %d", &n, &m, &k);
	for (i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		vec[x].push_back({ y, z });
	}
	Dijkstra(1);
	for (i = 1; i <= n; i++) {
		if (dis[i].size() < k) printf("-1\n");
		else printf("%d\n", dis[i].top());
	}
	return 0;
}