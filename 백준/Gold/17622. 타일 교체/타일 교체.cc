#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, k, nm;
int omap[55][55], map[55][55];
int dis[55][55], ch[55][55];
int dx[5] = { 0, 0, 1, -1 };
int dy[5] = { 1, -1, 0, 0 };
int pd[10][5];

struct dat {
	int x, y, chx, chy;
};

void BFS(int x, int y)
{
	int i, j;
	queue <dat> q;
	q.push({ x, y, 1, 0});
	ch[x][y] = nm;
	dis[x][y] = 1;
	while (!q.empty()) {
		int n_x = q.front().x, n_y = q.front().y;
		int nw = map[n_x][n_y], chx = q.front().chx, chy = q.front().chy;
		q.pop();
		int ct = 0, cf = 0;
		int kx, ky;
		for (i = 0; i < 2; i++) {
			int nx = n_x + dx[pd[nw][i]], ny = n_y + dy[pd[nw][i]];
			if (map[nx][ny] == -1) continue;
			if (nx == chx && ny == chy) cf++;
			else {
				ct++;
				kx = nx, ky = ny;
			}
		}
		if (cf == 1 && ct == 1) {
			dis[kx][ky] = dis[n_x][n_y] + 1;
			q.push({ kx, ky, n_x, n_y});
			ch[kx][ky] = nm;
		}
	}
}

int main()
{
	int i, j;
	pd[0][0] = 0, pd[0][1] = 2;
	pd[1][0] = 1, pd[1][1] = 2;
	pd[2][0] = 0, pd[2][1] = 3;
	pd[3][0] = 1, pd[3][1] = 3;
	pd[4][0] = 3, pd[4][1] = 2;
	pd[5][0] = 0, pd[5][1] = 1;
	scanf("%d %d", &n, &k);
	for (i = 0; i <= n + 1; i++) {
		for (j = 0; j <= n + 1; j++) {
			map[i][j] = -1;
			omap[i][j] = -1;
		}
	}
	map[1][0] = 0;
	omap[1][0] = 0;
	map[n][n + 1] = 5;
	omap[n][n + 1] = 5;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &omap[i][j]);
			map[i][j] = omap[i][j];
		}
	}
	int ans;
	if (k == 0) {
		nm = 1;
		BFS(1, 1);
		if (ch[n][n + 1] == 0) ans = 2e9;
		else ans = dis[n][n];
	}
	else {
		ans = 2e9;
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				for (int L = 0; L < 6; L++) {
					if (omap[i][j] == L) continue;
					map[i][j] = L;
					nm++;
					BFS(1, 1);
					if (ch[n][n + 1] == nm) ans = min(ans, dis[n][n]);
				}
				map[i][j] = omap[i][j];
			}
		}
	}
	if (ans == 2e9) printf("-1");
	else printf("%d", ans);
	return 0;
}