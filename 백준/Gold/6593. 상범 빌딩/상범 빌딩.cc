#include <stdio.h>
#include <queue>

using namespace std;

struct dat
{
	int x, y, z;
};

int l, r, c;
char map[35][35][35];
int dis[35][35][35];
queue <dat> q;

int dx[10] = { 0, 0, 1, -1, 0, 0 };
int dy[10] = { 1, -1, 0, 0, 0, 0 };
int dz[10] = { 0, 0, 0, 0, 1, -1 };

void BFS()
{
	while (!q.empty()) {
		int n_x = q.front().x, n_y = q.front().y, n_z = q.front().z;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = n_x + dx[i];
			int ny = n_y + dy[i];
			int nz = n_z + dz[i];
			if (nx < 0 || ny < 0 || nz < 0 || nx >= l || ny >= r || nz >= c) continue;
			if (map[nx][ny][nz] != '#' && dis[nx][ny][nz] > dis[n_x][n_y][n_z] + 1) {
				dis[nx][ny][nz] = dis[n_x][n_y][n_z] + 1;
				q.push({ nx, ny, nz });
			}
		}
	}
}

int main()
{
	int i, j, k;
	while (1) {
		scanf("%d %d %d", &l, &r, &c);
		if (l == 0 && r == 0 && c == 0) return 0;
		for (i = 0; i < l; i++) {
			for (j = 0; j < r; j++) {
				scanf("%s", map[i][j]);
			}
		}
		int endx, endy, endz;
		for (i = 0; i < l; i++) {
			for (j = 0; j < r; j++) {
				for (k = 0; k < c; k++) {
					dis[i][j][k] = 2e9;
					if (map[i][j][k] == 'S') {
						dis[i][j][k] = 0;
						q.push({ i, j, k });
					}
					if (map[i][j][k] == 'E') endx = i, endy = j, endz = k;
				}
			}
		}
		BFS();
		if (dis[endx][endy][endz] == 2e9) printf("Trapped!\n");
		else printf("Escaped in %d minute(s).\n", dis[endx][endy][endz]);
		while (!q.empty()) q.pop();
	}
	return 0;
}