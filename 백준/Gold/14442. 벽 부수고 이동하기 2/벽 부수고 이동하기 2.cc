#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

struct dat {
	int x, y, br;
};

int n, m, k;
int map[1010][1010];
int dis[1010][1010][15];
int dx[5] = { 0, 0, 1, -1 };
int dy[5] = { 1, -1, 0, 0 };

void BFS(int x, int y)
{
	int i;
	queue <dat> q;
	q.push({ x, y, 0 });
	dis[x][y][0] = 0;
	while (!q.empty()) {
		int n_x = q.front().x, n_y = q.front().y, n_br = q.front().br;
		q.pop();
		for (i = 0; i < 4; i++) {
			int nx = n_x + dx[i], ny = n_y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (map[nx][ny] == 0 && dis[nx][ny][n_br] > dis[n_x][n_y][n_br] + 1) {
				dis[nx][ny][n_br] = dis[n_x][n_y][n_br] + 1;
				q.push({ nx, ny, n_br });
			}
			if (n_br + 1 <= k) {
				if (map[nx][ny] == 1 && dis[nx][ny][n_br + 1] > dis[n_x][n_y][n_br] + 1) {
					dis[nx][ny][n_br + 1] = dis[n_x][n_y][n_br] + 1;
					q.push({ nx, ny, n_br + 1 });
				}
			}
		}
	}
}

int main()
{
	int i, j;
	scanf("%d %d %d", &n, &m, &k);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
			for (int l = 0; l <= k; l++) dis[i][j][l] = 2e9;
		}
	}
	BFS(0, 0);
	int ans = 2e9;
	for (i = 0; i <= k; i++) ans = min(ans, dis[n - 1][m - 1][i]);
	if (ans == 2e9) printf("-1");
	else printf("%d", ans + 1);
	return 0;
}