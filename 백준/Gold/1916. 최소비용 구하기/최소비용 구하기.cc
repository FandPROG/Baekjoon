#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

long long n, m;
vector <pair<long long, long long>> vec[1010];
long long dis[1010];

void Dijkstra(long long s)
{
	long long i, j;
	priority_queue<pair<long long, long long>> pq;
	pq.push({ 0, s });
	dis[s] = 0;
	while (!pq.empty()) {
		long long n_idx = pq.top().second, n_val = -pq.top().first;
		pq.pop();
		if (n_val > dis[n_idx]) continue;
		for (i = 0; i < vec[n_idx].size(); i++) {
			long long idx = vec[n_idx][i].first, val = n_val + vec[n_idx][i].second;
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
	scanf("%lld %lld", &n, &m);
	for (i = 0; i < m; i++) {
		long long x, y, dis;
		scanf("%lld %lld %lld", &x, &y, &dis);
		vec[x].push_back({ y, dis });
	}
	long long s, e;
	for (i = 0; i <= n; i++) dis[i] = 2e19;
	scanf("%lld %lld", &s, &e);
	Dijkstra(s);
	printf("%lld", dis[e]);
	return 0;
}