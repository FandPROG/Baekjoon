#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>

using namespace std;

int n, m;
int ch[200010];
vector <int> ent[200010];
vector <pair<int, int>> vec[200010];

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		int x, y;
		vector <int> v;
		scanf("%d", &x);
		for (j = 0; j < x; j++) {
			int z;
			scanf("%d", &z);
			v.push_back(z);
		}
		scanf("%d", &y);
		ent[y].push_back(0);
		int sz = ent[y].size() - 1;
		for (j = 0; j < x; j++) {
			vec[v[j]].push_back({ y, sz });
			ent[y][sz]++;
		}
	}
	int x;
	scanf("%d", &x);
	queue <int> q;
	for (i = 0; i < x; i++) {
		int y;
		scanf("%d", &y);
		ch[y] = 1;
		q.push(y);
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (i = 0; i < vec[now].size(); i++) {
			int nw = vec[now][i].first;
			int rec = vec[now][i].second;
			ent[nw][rec]--;
			if (ent[nw][rec] == 0 && ch[nw] == 0) {
				ch[nw] = 1;
				q.push(nw);
			}
		}
	}
	int ans = 0;
	for (i = 1; i <= n; i++) {
		if (ch[i] == 1) ans++;
	}
	printf("%d\n", ans);
	for (i = 1; i <= n; i++) {
		if (ch[i] == 1) printf("%d ", i);
	}
	return 0;
}