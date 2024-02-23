#include <stdio.h>
#include <algorithm> 
#include <queue>
#include <vector>

using namespace std;

vector <pair<int, int>> vec[20010];
int dis[20010];
int n, m;

void Dijkstra(int s)
{
	int i, j;
	priority_queue<pair<int, int>> pq;
	for (i = 0; i <= n; i++) dis[i] = 2e9;
	pq.push({ 0, s });
	dis[s] = 0;
	while (!pq.empty()) {
		int ds = -pq.top().first;
		int pt = pq.top().second;
		pq.pop();
		if (dis[pt] < ds) continue;
		for (i = 0; i < vec[pt].size(); i++) {
			int n_ds = ds + vec[pt][i].second;
			int n_pt = vec[pt][i].first;
			if (dis[n_pt] > n_ds) {
				dis[n_pt] = n_ds;
				pq.push({ -n_ds, n_pt });
			}
		}
	}
}

int main()
{
	int i, j;
	int s;
	scanf("%d %d %d", &n, &m, &s);
	for (i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		vec[x].push_back({ y, z });
	}
	Dijkstra(s);
	for (i = 1; i <= n; i++) {
		if (dis[i] == 2e9) printf("INF\n");
		else printf("%d\n", dis[i]);
	}
	return 0;
}