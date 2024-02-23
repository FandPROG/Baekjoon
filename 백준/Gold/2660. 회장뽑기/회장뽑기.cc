#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
vector <int> vec[55];
int dis[55];
vector<pair<int, int>> ans;

void BFS(int x)
{
	int i, j;
	queue<int> q;
	q.push(x);
	dis[x] = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (i = 0; i < vec[now].size(); i++) {
			if (dis[now] + 1 < dis[vec[now][i]]) {
				dis[vec[now][i]] = dis[now] + 1;
				q.push(vec[now][i]);
			}
		}
	}
}

int main()
{
	int i, j;
	scanf("%d", &n);
	while (1) {
		int x, y;
		scanf("%d %d", &x, &y);
		if (x == -1 && y == -1) break;
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	for (i = 1; i <= n; i++) {
		int mx = -2e9;
		for (j = 1; j <= n; j++) dis[j] = 2e9;
		BFS(i);
		for (j = 1; j <= n; j++) if (mx < dis[j]) mx = dis[j];
		ans.push_back({ mx, i });
	}
	sort(ans.begin(), ans.end());
	int cnt = 0;
	for (i = 0; i < ans.size(); i++) if (ans[i].first == ans[0].first) cnt++;
	printf("%d %d\n", ans[0].first, cnt);
	for (i = 0; i < ans.size(); i++) if (ans[i].first == ans[0].first) printf("%d ", ans[i].second);
	return 0;
}