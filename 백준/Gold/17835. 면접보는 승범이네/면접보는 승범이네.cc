#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

long long n, m, k;
vector <pair<long long, long long>> vec[100010];
priority_queue <pair<long long, long long>> pq;
long long dis[100010];

void Dijkstra()
{
	long long i, j;
	while (!pq.empty()) {
		long long nidx = pq.top().second, nval = -pq.top().first;
		pq.pop();
		if (dis[nidx] < nval) continue;
		for (i = 0; i < vec[nidx].size(); i++) {
			long long idx = vec[nidx][i].first, val = nval + vec[nidx][i].second;
			if (dis[idx] > val) {
				dis[idx] = val;
				pq.push({ -val, idx });
			}
		}
	}
}

int main()
{
	long long i, j;
	scanf("%lld %lld %lld", &n, &m, &k);
	for (i = 1; i <= n; i++) dis[i] = 2e19;
	for (i = 0; i < m; i++) {
		long long x, y, z;
		scanf("%lld %lld %lld", &x, &y, &z);
		vec[y].push_back({ x, z });
	}
	for (i = 0; i < k; i++) {
		long long x;
		scanf("%lld", &x);
		dis[x] = 0;
		pq.push({ 0, x });
	}
	Dijkstra();
	long long mx = -1, ans = 0;
	for (i = 1; i <= n; i++) if (mx < dis[i]) mx = dis[i], ans = i;
	printf("%lld\n%lld", ans, mx);
	return 0;
}