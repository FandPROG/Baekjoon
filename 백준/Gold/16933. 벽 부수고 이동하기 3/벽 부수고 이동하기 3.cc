#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k;
int map[1010][1010];
int dis[1010][1010][15][5];
int dx[5] = { 0, 0, 1, -1 };
int dy[5] = { 1, -1, 0, 0 };

struct dat {
	int x, y, br, time;
};

void BFS(int x, int y)
{
	int i, j;
	queue<dat> q;
	q.push({ x, y, 0, 1 });
	dis[x][y][0][1] = 0;
	while (!q.empty()) {
		int n_x = q.front().x, n_y = q.front().y, nb = q.front().br, nt = q.front().time;
		q.pop();
		for (i = 0; i < 4; i++) {
			int nx = n_x + dx[i], ny = n_y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (nt == 1) {
				if (dis[nx][ny][nb][0] > dis[n_x][n_y][nb][nt] + 1 && map[nx][ny] == 0) {
					dis[nx][ny][nb][0] = dis[n_x][n_y][nb][nt] + 1;
					q.push({ nx, ny, nb, 0 });
				}
				if (dis[n_x][n_y][nb][0] > dis[n_x][n_y][nb][nt] + 1) {
					dis[n_x][n_y][nb][0] = dis[n_x][n_y][nb][nt] + 1;
					q.push({ n_x, n_y, nb, 0 });
				}
				if (map[nx][ny] == 1 && nb + 1 <= k && dis[nx][ny][nb + 1][0] > dis[n_x][n_y][nb][nt] + 1) {
					dis[nx][ny][nb + 1][0] = dis[n_x][n_y][nb][nt] + 1;
					q.push({ nx, ny, nb + 1, 0 });
				}
			}
			else {
				if (dis[nx][ny][nb][1] > dis[n_x][n_y][nb][nt] + 1 && map[nx][ny] == 0) {
					dis[nx][ny][nb][1] = dis[n_x][n_y][nb][nt] + 1;
					q.push({ nx, ny, nb, 1 });
				}
				if (dis[n_x][n_y][nb][1] > dis[n_x][n_y][nb][nt] + 1) {
					dis[n_x][n_y][nb][1] = dis[n_x][n_y][nb][nt] + 1;
					q.push({ n_x, n_y, nb, 1 });
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
			for (int l = 0; l <= k; l++) dis[i][j][l][0] = 2e9, dis[i][j][l][1] = 2e9;
		}
	}
	BFS(0, 0);
	int ans = 2e9;
	for (i = 0; i <= k; i++) ans = min(ans, min(dis[n - 1][m - 1][i][0], dis[n - 1][m - 1][i][1]));
	if (ans == 2e9) printf("-1");
	else printf("%d", ans + 1);
	return 0;
}