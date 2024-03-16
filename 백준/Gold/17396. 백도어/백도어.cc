#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

long long n, m;
long long ward[100010];
long long dis[100010];
vector <pair<long long, long long>> vec[100010];

void Dijkstra(long long s)
{
	long long i, j;
	priority_queue <pair<long long, long long>> pq;
	dis[s] = 0;
	pq.push({ 0, s });
	while (!pq.empty()) {
		long long nidx = pq.top().second, nval = -pq.top().first;
		pq.pop();
		if (dis[nidx] < nval) continue;
		for (i = 0; i < vec[nidx].size(); i++) {
			long long idx = vec[nidx][i].first, val = nval + vec[nidx][i].second;
			if (ward[idx] == 0 && dis[idx] > val) {
				dis[idx] = val;
				pq.push({ -val, idx });
			}
		}
	}
}

int main()
{
	long long i, j;
	scanf("%lld %lld", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%lld", &ward[i]);
		dis[i] = 2e15;
	}
	ward[n - 1] = 0;
	for (i = 0; i < m; i++) { 
		long long x, y, z;
		scanf("%lld %lld %lld", &x, &y, &z);
		vec[x].push_back({ y, z });
		vec[y].push_back({ x, z });
	}
	Dijkstra(0);
	if (dis[n - 1] == 2e15) printf("-1");
	else printf("%lld", dis[n - 1]);
	return 0;
}