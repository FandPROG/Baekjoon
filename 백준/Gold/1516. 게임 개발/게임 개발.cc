#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int dis[510], time[510];
int ent[510];
vector<int> vec[510];

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &time[i]);
		while (1) {
			int x;
			scanf("%d", &x);
			if (x == -1) break;
			vec[x].push_back(i);
			ent[i]++;
		}
	}
	queue<int> q;
	for (i = 1; i <= n; i++) {
		dis[i] = time[i];
		if (ent[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (i = 0; i < vec[now].size(); i++) {
			int nw = vec[now][i];
			ent[nw]--;
			if (ent[nw] == 0) {
				q.push(nw);
			}
			dis[nw] = max(dis[now] + time[nw], dis[nw]);
		}
	}
	for (i = 1; i <= n; i++) printf("%d\n", dis[i]);
	return 0;
}