#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

long long n, m, k;
long long s, d;
long long dis[1010][1010];
vector <pair<long long, long long>> vec[1010];

struct dat {
	long long idx, val, nw;
};

bool operator<(const dat& x, const dat& y) {
	return x.val > y.val;
}

void Dijkstra()
{
	long long i, j;
	priority_queue <dat> pq;
	dis[s][0] = 0;
	pq.push({ s, 0, 0 });
	while (!pq.empty()) {
		long long nidx = pq.top().idx, nval = pq.top().val, nw = pq.top().nw;
		pq.pop();
		if (dis[nidx][nw] < nval) continue;
		for (i = 0; i < vec[nidx].size(); i++) {
			long long idx = vec[nidx][i].first, val = vec[nidx][i].second + nval;
			if (val < dis[idx][nw + 1] && nw + 1 < n) {
				dis[idx][nw + 1] = val;
				pq.push({ idx, val, nw + 1});
			}
		}
	}
}

int main()
{
	long long i, j;
	scanf("%lld %lld %lld %lld %lld", &n, &m, &k, &s, &d);
	for (i = 0; i < m; i++) {
		long long x, y, z;
		scanf("%lld %lld %lld", &x, &y, &z);
		vec[x].push_back({ y, z });
		vec[y].push_back({ x, z });
	}
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= n; j++) {
			dis[i][j] = 2e15;
		}
	}
	Dijkstra();
	long long res = 2e15;
	for (j = 1; j < n; j++) res = min(res, dis[d][j]);
	printf("%lld\n", res);
	for (i = 0; i < k; i++) {
		long long x;
		long long ans = 2e15;
		scanf("%lld", &x);
		for (j = 1; j < n; j++) {
			if (dis[d][j] == 2e15) continue;
			dis[d][j] += (x * j);
			ans = min(dis[d][j], ans);
		}
		printf("%lld\n", ans);
	}
	return 0;
}