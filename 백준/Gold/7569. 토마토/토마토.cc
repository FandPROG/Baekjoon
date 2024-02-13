#include <stdio.h>
#include <queue>

using namespace std;

int xs, ys, zs;
int map[110][110][110];
int time[110][110][110];
int dx[10] = { 0, 0, 1, -1, 0, 0 };
int dy[10] = { 1, -1, 0, 0, 0, 0 };
int dz[10] = { 0, 0, 0, 0, 1, -1 };

void BFS(int x, int y, int z)
{
	int i, j;
	queue <int> qx, qy, qz;
	qx.push(x);
	qy.push(y);
	qz.push(z);
	while (!qx.empty()) {
		int nx = qx.front(), ny = qy.front(), nz = qz.front();
		for (i = 0; i < 6; i++) {
			int sx = nx + dx[i], sy = ny + dy[i], sz = nz + dz[i];
			if (sx >= 0 && sx < xs && sy < ys && sz < zs && sy >= 0 && sz >= 0) {
				if (map[sx][sy][sz] == 0 && time[sx][sy][sz] > time[nx][ny][nz] + 1) {
					time[sx][sy][sz] = time[nx][ny][nz] + 1;
					qx.push(sx);
					qy.push(sy);
					qz.push(sz);
				}
			}
		}
		qx.pop();
		qy.pop();
		qz.pop();
	}
}

int main()
{
	int i, j;
	scanf("%d %d %d", &ys, &xs, &zs);
	for (int k = 0; k < zs; k++) {
		for (i = 0; i < xs; i++) {
			for (j = 0; j < ys; j++) {
				scanf("%d", &map[i][j][k]);
				time[i][j][k] = 2e9;
			}
		}
	}
	for (int k = 0; k < zs; k++) {
		for (i = 0; i < xs; i++) {
			for (j = 0; j < ys; j++) {
				if (map[i][j][k] == 1 && time[i][j][k] == 2e9) {
					time[i][j][k] = 0;
					BFS(i, j, k);
				}
			}
		}
	}
	int mx = -2e9;
	for (int k = 0; k < zs; k++) {
		for (i = 0; i < xs; i++) {
			for (j = 0; j < ys; j++) {
				if (map[i][j][k] == 0 && time[i][j][k] == 2e9) {
					printf("-1");
					return 0;
				}
				if (mx < time[i][j][k] && time[i][j][k] != 2e9) mx = time[i][j][k];
			}
		}
	}
	printf("%d", mx);
	return 0;
}