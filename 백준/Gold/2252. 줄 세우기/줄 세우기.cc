#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int in[35000];
vector<int> v[35000];
queue<int> q;

int main()
{
	int i, j, n, m, a, b;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		in[b]++;
		v[a].push_back(b);
	}
	for (i = 1; i <= n; i++) {
		if (in[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		i = q.front();
		q.pop();
		printf("%d ", i);
		for (j = 0; j < v[i].size(); j++) {
			if (--in[v[i][j]] == 0) q.push(v[i][j]);
		}
	}
	return 0;
}