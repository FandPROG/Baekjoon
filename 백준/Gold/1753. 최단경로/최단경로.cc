#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

#define max_n 20001
int n, m, k, mni[max_n];

vector< pair<int, int> > adj[max_n];
priority_queue <pair<int, int>> q;

void dijk()
{
	for(int i = 1;i <= n;i++) {
		mni[i] = 987654321;
	}
	mni[k] = 0;
	q.push({ 0,k });

	while(!q.empty()) {
		int u = q.top().second;
		int value = -q.top().first;
		q.pop();
		if(value > mni[u]) continue;
		for(auto i : adj[u]) {
			int v = i.first;
			int d = i.second;
			if (value + d < mni[v]) {
				mni[v] = value + d;
				q.push({ -mni[v],v });
			}
		}
	}
}
int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	scanf("%d", &k);
	for(i=1;i<=m;i++) {
		int a, b, p;
		scanf("%d %d %d", &a, &b, &p);
		adj[a].push_back({ b,p });
	}
	dijk();
	for(i=1;i<=n;i++) {
		if(mni[i] == 987654321) {
			printf("INF\n");
		}
		else {
			printf("%d\n", mni[i]);
		}
	}
	return 0;
}