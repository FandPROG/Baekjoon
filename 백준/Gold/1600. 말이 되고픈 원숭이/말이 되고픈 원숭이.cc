#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, k;
int dis[210][210][35];
int map[210][210];
int dx[5] = { 0, 0, 1, -1 };
int dy[5] = { 1, -1, 0, 0 };
int kx[10] = { 2, 2, 1, 1, -1 ,-1, -2, -2 };
int ky[10] = { 1, -1, 2, -2, 2, -2, 1, -1 };

struct dat {
	int x, y, jump;
};

void BFS(int x, int y)
{
	int i;
	queue<dat> q;
	q.push({ x, y, 0 });
	dis[x][y][0] = 0;
	while (!q.empty()) {
		int n_x = q.front().x, n_y = q.front().y, n_jump = q.front().jump;
		q.pop();
		for (i = 0; i < 4; i++) {
			int nx = n_x + dx[i], ny = n_y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (map[nx][ny] == 0 && dis[nx][ny][n_jump] > dis[n_x][n_y][n_jump] + 1) {
				dis[nx][ny][n_jump] = dis[n_x][n_y][n_jump] + 1;
				q.push({ nx, ny, n_jump });
			}
		}
		if (n_jump + 1 <= k) {
			for (i = 0; i < 8; i++) {
				int nx = n_x + kx[i], ny = n_y + ky[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (map[nx][ny] == 0 && dis[nx][ny][n_jump + 1] > dis[n_x][n_y][n_jump] + 1) {
					dis[nx][ny][n_jump + 1] = dis[n_x][n_y][n_jump] + 1;
					q.push({ nx, ny, n_jump + 1 });
				}
			}
		}
	}
}

int main()
{
	int i, j;
	scanf("%d %d %d", &k, &m, &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			for (int l = 0; l <= k; l++) dis[i][j][l] = 2e9;
		}
	}
	BFS(0, 0);
	int ans = 2e9;
	for (i = 0; i <= k; i++) ans = min(ans, dis[n - 1][m - 1][i]);
	if (ans == 2e9) printf("-1");
	else printf("%d", ans);
	return 0;
}