#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, m;
vector <pair<int, int>> vec1[10010], vec2[10010];
int ent1[10010];
int dis[10010];
int ch[10010];
int s, e;

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		vec1[x].push_back({ y, z });
		ent1[y]++;
		vec2[y].push_back({ x, z });
	}
	scanf("%d %d", &s, &e);
	queue <int> q;
	q.push(s);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (i = 0; i < vec1[now].size(); i++) {
			int nw = vec1[now][i].first, nval = dis[now] + vec1[now][i].second;
			dis[nw] = max(dis[nw], nval);
			ent1[nw]--;
			if (ent1[nw] == 0) {
				q.push(nw);
			}
		}
	}
	int ans = 0;
	while (!q.empty()) q.pop();
	q.push(e);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (i = 0; i < vec2[now].size(); i++) {
			int nw = vec2[now][i].first, vl = vec2[now][i].second;
			if (dis[nw] + vl == dis[now]) {
				if(ch[nw] == 0) q.push(nw);
				ch[nw] = 1;
				ans++;
			}
		}
	}
	printf("%d\n%d", dis[e], ans);
	return 0;
}