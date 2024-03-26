#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, m;
vector <int> vec[1010];
int ent[1010], ans[1010];

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		vec[x].push_back(y);
		ent[y]++;
	}
	queue <int> q;
	for (i = 1; i <= n; i++) {
		ans[i] = 1;
		if (ent[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (i = 0; i < vec[now].size(); i++) {
			int nw = vec[now][i];
			ent[nw]--;
			ans[nw] = max(ans[nw], ans[now]);
			if (ent[nw] == 0) {
				q.push(nw);
				ans[nw]++;
			}
		}
	}
	for (i = 1; i <= n; i++) printf("%d ", ans[i]);
	return 0;
}