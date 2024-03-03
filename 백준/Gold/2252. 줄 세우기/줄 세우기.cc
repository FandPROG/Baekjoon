#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int ent[32010];
vector <int> vec[32010];

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
		if (ent[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		printf("%d ", now);
		for (i = 0; i < vec[now].size(); i++) {
			int idx = vec[now][i];
			ent[idx]--;
			if (ent[idx] <= 0) {
				q.push(idx);
			}
		}
	}
	return 0;
}