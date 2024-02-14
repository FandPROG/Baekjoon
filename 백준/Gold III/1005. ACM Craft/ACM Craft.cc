#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int t;
int n, m;
int inDe[1010];
int time[1010];
int dis[1010];

int main()
{
	int i, j;
	scanf("%d", &t);
	while (t--) {
		vector<int> vec[1010];
		queue <int> q;
		scanf("%d %d", &n, &m);
		for (i = 1; i <= n; i++) scanf("%d", &time[i]);
		for (i = 0; i < m; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			vec[x].push_back(y);
			inDe[y]++;
		}
		int w;
		scanf("%d", &w);
		for (i = 1; i <= n; i++) {
			dis[i] = -2e9;
			if (inDe[i] == 0) {
				q.push(i);
				dis[i] = time[i];
			}
		}
		while (!q.empty()) {
			int idx = q.front();
			q.pop();
			for (i = 0; i < vec[idx].size(); i++) {
				int nxt = vec[idx][i];
				inDe[nxt]--;
				if (dis[nxt] < dis[idx] + time[nxt]) dis[nxt] = dis[idx] + time[nxt];
				if (inDe[nxt] == 0) {
					q.push(nxt);
				}
			}
		}
		printf("%d\n", dis[w]);
	}
	return 0;
}