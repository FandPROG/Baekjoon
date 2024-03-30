#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

long long v, e;
long long dis[2][10010];
vector <pair<long long, long long>> vec[10010];
long long max_m, max_s;
long long ch[10010];
priority_queue <pair<long long, long long>> pq;

void Dijkstra(long long pan)
{
	long long i, j;
	while (!pq.empty()) {
		long long nidx = pq.top().second, nval = -pq.top().first;
		pq.pop();
		if (dis[pan][nidx] < nval) continue;
		for (i = 0; i < vec[nidx].size(); i++) {
			long long idx = vec[nidx][i].first, val = nval + vec[nidx][i].second;
			if (dis[pan][idx] > val) {
				dis[pan][idx] = val;
				pq.push({ -val, idx });
			}
		}
	}
}

int main()
{
	long long i, j;
	scanf("%lld %lld", &v, &e);
	for (i = 0; i < e; i++) {
		long long x, y, z;
		scanf("%lld %lld %lld", &x, &y, &z);
		vec[x].push_back({ y, z });
		vec[y].push_back({ x, z });
	}

	long long mn, sn;
	for (i = 0; i <= 1; i++) {
		for (j = 1; j <= v; j++) {
			dis[i][j] = 2e15;
		}
	}

	scanf("%lld %lld", &mn, &max_m);
	for (i = 0; i < mn; i++) {
		long long x;
		scanf("%lld", &x);
		ch[x] = 1;
		dis[1][x] = 0;
		pq.push({ 0, x });
	}
	Dijkstra(1);

	scanf("%lld %lld", &sn, &max_s);
	for (i = 0; i < sn; i++) {
		long long x;
		scanf("%lld", &x);
		ch[x] = 1;
		dis[0][x] = 0;
		pq.push({ 0, x });
	}
	Dijkstra(0);
	
	long long ans = 2e15;
	for (i = 1; i <= v; i++) {
		if (dis[0][i] > max_s || dis[1][i] > max_m) continue;
		if (ch[i] == 1) continue;
		ans = min(ans, dis[0][i] + dis[1][i]);
	}
	if (ans == 2e15) printf("-1");
	else printf("%lld", ans);
	return 0;
}