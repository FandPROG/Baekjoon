#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, k;
int dis[110][100010];
vector <pair<int, int>> a, b;

int main()
{
	int i, j;
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++) {
		int q, w, e, r;
		scanf("%d %d %d %d", &q, &w, &e, &r);
		a.push_back({ q, w });
		b.push_back({ e, r });
	}
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= k; j++) {
			dis[i][j] = -2e9;
		}
	}
	queue <pair<int, int>> q;
	q.push({ 0, 0 });
	dis[0][0] = 0;
	while (!q.empty()) {
		int nidx = q.front().first, nval = q.front().second;
		q.pop();
		if (nidx == n) continue;
		if (nval + a[nidx].first <= k) {
			if (dis[nidx][nval] + a[nidx].second > dis[nidx + 1][nval + a[nidx].first]) {
				dis[nidx + 1][nval + a[nidx].first] = dis[nidx][nval] + a[nidx].second;
				q.push({ nidx + 1, nval + a[nidx].first });
			}
		}
		if (nval + b[nidx].first <= k) {
			if (dis[nidx][nval] + b[nidx].second > dis[nidx + 1][nval + b[nidx].first]) {
				dis[nidx + 1][nval + b[nidx].first] = dis[nidx][nval] + b[nidx].second;
				q.push({ nidx + 1, nval + b[nidx].first });
			}
		}
	}
	int ans = -2e9;
	for (i = 0; i <= k; i++) ans = max(ans, dis[n][i]);
	printf("%d", ans);
	return 0;
}