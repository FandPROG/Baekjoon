#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int map[1010][1010];
int dis[1010][1010][3];
int dx[5] = { 0, 0, 1, -1 };
int dy[5] = { 1, -1, 0, 0 };

struct dat {
	int x, y, br;
};

void BFS(int x, int y)
{
	int i, j;
	queue <dat> q;
	q.push({ x, y, 0 });
	dis[x][y][0] = 0;
	while (!q.empty()) {
		int n_x = q.front().x, n_y = q.front().y, br = q.front().br;
		q.pop();
		for (i = 0; i < 4; i++) {
			int nx = n_x + dx[i], ny = n_y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (map[nx][ny] == 0 && dis[nx][ny][br] > dis[n_x][n_y][br] + 1) {
				dis[nx][ny][br] = dis[n_x][n_y][br] + 1;
				q.push({ nx, ny, br });
			}
			if (map[nx][ny] == 1 && br == 0 && dis[nx][ny][br + 1] > dis[n_x][n_y][br] + 1) {
				dis[nx][ny][br + 1] = dis[n_x][n_y][br] + 1;
				q.push({ nx, ny, br + 1 });
			}
		}
	}
	return;
}

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	int sx, sy, ex, ey;
	scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			dis[i][j][0] = 2e9, dis[i][j][1] = 2e9;
		}
	}
	BFS(sx - 1, sy - 1);
	int ans = min(dis[ex - 1][ey - 1][0], dis[ex - 1][ey - 1][1]);
	if (ans == 2e9) printf("-1");
	else printf("%d", ans);
	return 0;
}