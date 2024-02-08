#include <stdio.h>
#include <queue>

using namespace std;

int n, g;
int map[110][110];
int ans[110][110];

void BFS(int x) {
	int i, j;
	queue <int> q;
	q.push(x);
//	ans[x][x] = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (i = 0; i < n; i++) {
			if (map[now][i] == 1 && ans[x][i] == 0) {
				q.push(i);
				ans[x][i] = 1;
			}
		}
	}
}

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (i = 0; i < n; i++) BFS(i);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}