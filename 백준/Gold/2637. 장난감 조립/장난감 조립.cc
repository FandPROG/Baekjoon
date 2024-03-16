#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int ans[110][110];
int ent[110];
vector <pair<int, int>> vec[110];

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		vec[y].push_back({ x, z });
		ent[x]++;
	}
	queue <int> q;
	for (i = 1; i <= n; i++) {
		if (ent[i] == 0) {
			q.push(i);
			ans[i][i] = 1;
		}
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (i = 0; i < vec[now].size(); i++) {
			int nw = vec[now][i].first;
			ent[nw]--;
			for (j = 1; j <= n; j++) ans[nw][j] += (ans[now][j] * vec[now][i].second);
			if (ent[nw] == 0) {
				q.push(nw);
			}
		}
	}
	for (i = 1; i <= n; i++) if(ans[n][i] > 0) printf("%d %d\n", i, ans[n][i]);
	return 0;
}