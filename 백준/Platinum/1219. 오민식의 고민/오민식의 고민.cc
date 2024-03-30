#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 2e15

using namespace std;

int n, m, s, e;
long long pr[55], dis[55];
struct dat {
	int a, b;
	long long c;
};
vector <dat> vec;
vector <int> vc[55];
int ch[55];

int main()
{
	int i, j;
	scanf("%d %d %d %d", &n, &s, &e, &m);
	for (i = 0; i < m; i++) {
		int x, y;
		long long z;
		scanf("%d %d %lld", &x, &y, &z);
		vec.push_back({ x, y, z });
		vc[x].push_back(y);
	}
	for (i = 0; i < n; i++) scanf("%lld", &pr[i]);
	for (i = 0; i < n; i++) dis[i] = INF;
	dis[s] = -pr[s];
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			int x = vec[j].a, y = vec[j].b;
			long long val = vec[j].c;
			if (dis[x] == INF) continue;
			if (dis[x] + val - pr[y] < dis[y]) dis[y] = dis[x] + val - pr[y];
		}
	}
	if (dis[e] == INF) {
		printf("gg");
		return 0;
	}
	for (i = 0; i < m; i++) {
		int x = vec[i].a, y = vec[i].b, val = vec[i].c;
		if (dis[x] == INF) continue;
		if (dis[x] + val - pr[y] < dis[y]) {
			queue <int> q;
			q.push(x);
			ch[x] = 1;
			while (!q.empty()) {
				int now = q.front();
				q.pop();
				for (j = 0; j < vc[now].size(); j++) {
					int nw = vc[now][j];
					if (ch[nw] == 0) ch[nw] = 1, q.push(nw);
				}
			}
			if (ch[e] == 1) {
				printf("Gee");
				return 0;
			}
		}
	}
	printf("%lld", -dis[e]);
	return 0;
}