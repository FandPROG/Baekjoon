#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, p;
vector <int> vec[410];
int E[410][410], F[410][410]; // empty, fill
int d[410];
int res;

void MaxFlow(int s, int e)
{
	int i, j;
	while (1) {
		for (i = 0; i <= n; i++) d[i] = -1;
		queue <int> q;
		q.push(s);
		while (!q.empty()) {
			int nw = q.front();
			q.pop();
			for (i = 0; i < vec[nw].size(); i++) {
				int now = vec[nw][i];
				if (E[nw][now] - F[nw][now] > 0 && d[now] == -1) {
					q.push(now);
					d[now] = nw;
					if (now == e) break;
				}
			}
		}
		if (d[e] == -1) break;
		int flow = 2e9;
		for (i = e; i != s; i = d[i]) {
			flow = min(flow, E[d[i]][i] - F[d[i]][i]);
		}
		for (i = e; i != s; i = d[i]) {
			F[d[i]][i] += flow;
			F[i][d[i]] -= flow;
		}
		res += flow;
	}
}

int main()
{
	int i, j;
	scanf("%d %d", &n, &p);
	for (i = 0; i < p; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		vec[x].push_back(y);
		vec[y].push_back(x);
		E[x][y] = 1;
	}
	MaxFlow(1, 2);
	printf("%d", res);
	return 0;
}