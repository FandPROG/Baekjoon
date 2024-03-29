#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int ent[10010], ans[10010];
vector <pair<int, int>> vec[10010];

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		vec[x].push_back({ y, z });
		ent[y]++;
	}
	queue <int> q;
	for (i = 1; i <= n; i++) {
		if (ent[i] == 0) q.push(i), ans[i] = 1;
	}
	int res = -2e9;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		res = max(res, ans[now]);
		for (i = 0; i < vec[now].size(); i++) {
			int nw = vec[now][i].first, nval = ans[now] + vec[now][i].second;
			if (vec[now][i].second >= 7) nval++;
			ans[nw] = max(ans[nw], nval);
			ent[nw]--;
			if (ent[nw] == 0) {
				q.push(nw);
			}
		}
	}
	printf("%d", res);
	return 0;
}