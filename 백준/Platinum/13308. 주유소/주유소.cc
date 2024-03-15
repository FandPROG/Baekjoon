#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

long long n, m;
long long arr[2510];
vector <pair<long long, long long>> vec[2510];
long long dis[2510][2510];

struct dat {
	long long val, idx, cost;
};

bool operator<(const dat& a, const dat& b) {
	return a.val > b.val;
}

void Dijkstra(long long s)
{
	long long i, j;
	priority_queue <dat> pq;
	dis[s][arr[s]] = 0;
	pq.push({ 0, s, arr[s] });
	while (!pq.empty()) {
		long long nidx = pq.top().idx, nval = pq.top().val, ncos = pq.top().cost;
		pq.pop();
		if (dis[nidx][ncos] < nval) continue;
		for (i = 0; i < vec[nidx].size(); i++) {
			long long idx = vec[nidx][i].first, val = nval + vec[nidx][i].second * ncos;
			long long cos = min(ncos, arr[idx]);
			if (dis[idx][cos] > val) {
				dis[idx][cos] = val;
				pq.push({ val, idx, cos });
			}
		}
	}
}

int main()
{
	long long i, j, mx = -2e19;
	scanf("%lld %lld", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%lld", &arr[i]);
		if (mx < arr[i]) mx = arr[i];
	}
	for (i = 0; i < m; i++) {
		long long x, y, z;
		scanf("%lld %lld %lld", &x, &y, &z);
		vec[x].push_back({ y, z });
		vec[y].push_back({ x, z });
	}
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= mx; j++) {
			dis[i][j] = 2e19;
		}
	}
	Dijkstra(1);
	long long ans = 2e19;
	for (i = 1; i <= mx; i++) {
		ans = min(ans, dis[n][i]);
	}
	printf("%lld", ans);
	return 0;
}