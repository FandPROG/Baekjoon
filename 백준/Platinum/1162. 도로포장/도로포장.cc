#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

long long n, m, k;
long long dis[10010][25];
vector <pair<long long, long long>> vec[10010];

struct dat {
	long long x, y, brk;
};

bool operator <(const dat& a, const dat& b) {
	return a.x > b.x;
}

void Dijkstra(long long s)
{
	long long i, j;
	priority_queue <dat> pq;
	dis[s][0] = 0;
	pq.push({ 0, s, 0 });
	while (!pq.empty()) {
		long long nidx = pq.top().y, nval = pq.top().x, nbrk = pq.top().brk;
		pq.pop();
		if (dis[nidx][nbrk] < nval) continue;
		for (i = 0; i < vec[nidx].size(); i++) {
			long long idx = vec[nidx][i].first, val = vec[nidx][i].second + nval;
			if (nbrk + 1 <= k && dis[idx][nbrk + 1] > nval) {
				dis[idx][nbrk + 1] = nval;
				pq.push({ nval, idx, nbrk + 1 });
			}
			if (dis[idx][nbrk] > val) {
				dis[idx][nbrk] = val;
				pq.push({ val, idx, nbrk });
			}
		}
	}
}

int main()
{
	long long i, j;
	scanf("%lld %lld %lld", &n, &m, &k);
	for (i = 0; i < m; i++) {
		long long x, y, z;
		scanf("%lld %lld %lld", &x, &y, &z);
		vec[x].push_back({ y, z });
		vec[y].push_back({ x, z });
	}
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= k; j++) {
			dis[i][j] = 2e19;
		}
	}
	Dijkstra(1);
	long long ans = 2e19;
	for (i = 0; i <= k; i++) ans = min(ans, dis[n][i]);
	printf("%lld", ans);
	return 0;
}