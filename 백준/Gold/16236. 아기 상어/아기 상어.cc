#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int dx[5] = { -1, 0, 1, 0 };
int dy[5] = { 0, -1, 0, 1 };
int dis[25][25][410], ch[25][25][410];
int map[25][25], now_size[410];
int n, cnt;
int ansdis = 0;

struct dat {
	int x, y, cnt;
};

queue <dat> q;

void BFS()
{
	int i, j;
	while (!q.empty()) {
		int n_x = q.front().x, n_y = q.front().y, ncnt = q.front().cnt;
		q.pop();
		for (i = 0; i < 4; i++) {
			int nx = n_x + dx[i], ny = n_y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (!ch[nx][ny][ncnt] && map[nx][ny] != 0 && map[nx][ny] < now_size[cnt]) {
				ch[nx][ny][ncnt] = -1;
				dis[nx][ny][ncnt] = dis[n_x][n_y][ncnt] + 1;
				q.push({ nx, ny, ncnt });
			}
			else if (!ch[nx][ny][ncnt] && map[nx][ny] <= now_size[cnt]) {
				ch[nx][ny][ncnt] = 1;
				dis[nx][ny][ncnt] = dis[n_x][n_y][ncnt] + 1;
				q.push({ nx, ny, ncnt });
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
			for (int k = 0; k <= 400; k++) {
				dis[i][j][k] = 2e9;
			}
		}
	}
	int ct = 0, sz = 2;
	now_size[0] = 2;
	for (i = 1; i <= n * n; i++) {
		ct++;
		if (ct == sz) sz++, ct = 0;
		now_size[i] = sz;
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9) dis[i][j][0] = 0, ch[i][j][0] = 1, map[i][j] = 0, q.push({i, j, 0});
		}
	}
	while (1) {
		BFS();
		int mindis = 2e9;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (ch[i][j][cnt] == -1) mindis = min(mindis, dis[i][j][cnt]);
			}
		}
		int check = 0;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (ch[i][j][cnt] == -1 && dis[i][j][cnt] == mindis) {
					ansdis = dis[i][j][cnt];
					dis[i][j][cnt + 1] = dis[i][j][cnt];
					ch[i][j][cnt + 1] = 1;
					map[i][j] = 0;
					q.push({ i, j, cnt + 1 });
					check = 1;
					break;
				}
			}
			if (check == 1) break;
		}
		if (q.empty()) break;
		cnt++;
	}
/*	for (i = 0; i <= cnt; i++) {
		printf("\n\n\n\n<물고기를 %d번 잡아먹음>\n", i);
		for (j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (dis[j][k][i] >= 2e9) printf("INF ");
				else printf("%d ", ch[j][k][i]);
			}
			printf("\n");
		}
	}*/
	printf("%d", ansdis);
	return 0;
}