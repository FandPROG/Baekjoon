#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int time[10010], ans[10010], ent[10010];
vector <int> vec[10010];
int n;

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		time[i] = x;
		for (j = 0; j < y; j++) {
			int t;
			scanf("%d", &t);
			vec[i].push_back(t);
			ent[t]++;
		}
	}
	queue <int> q;
	for (i = 1; i <= n; i++) {
		if (ent[i] == 0) {
			q.push(i);
			ans[i] = time[i];
		}
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
			ans[nw] = max(ans[nw], ans[now] + time[nw]);
		}
	}
	int res = -2e9;
	for (i = 1; i <= n; i++) res = max(res, ans[i]);
	printf("%d", res);
	return 0;
}