#include <stdio.h>
#include <queue>

using namespace std;

int n, m;
int map[110][110];
int cnt[110][110];
int dx[5] = { 0, 0, -1, 1 };
int dy[6] = { 1, -1, 0, 0 };

void BFS(int x, int y)
{
	int i, j;
	queue <pair<int, int>> q;
	q.push({ x, y });
	cnt[x][y] = 0;
	while (!q.empty()) {
		int n_x = q.front().first, n_y = q.front().second;
		q.pop();
		for (i = 0; i < 4; i++) {
			int nx = n_x + dx[i], ny = n_y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (cnt[n_x][n_y] + 1 < cnt[nx][ny] && map[nx][ny] == 1) {
				cnt[nx][ny] = cnt[n_x][n_y] + 1;
				q.push({ nx, ny });
			}
		}
	}
	return;
}

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
			cnt[i][j] = 2e9;
		}
	}
	BFS(0, 0);
	printf("%d\n", cnt[n - 1][m - 1] + 1);
	return 0;
}