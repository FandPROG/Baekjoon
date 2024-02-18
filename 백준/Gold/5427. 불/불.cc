#include <stdio.h>
#include <queue>

using namespace std;

char map[1010][1010];
queue<pair<int, int>> q;
queue<pair<int, int>> fq;
int fire_dis[1010][1010];
int dis[1010][1010], n, m;
int dx[5] = { 0, 0, 1, -1 };
int dy[5] = { 1, -1, 0, 0 };

void FBFS()
{
	while (!fq.empty()) {
		int n_x = fq.front().first;
		int n_y = fq.front().second;
		fq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = n_x + dx[i];
			int ny = n_y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (map[nx][ny] != '#' && fire_dis[nx][ny] > fire_dis[n_x][n_y] + 1) {
				fire_dis[nx][ny] = fire_dis[n_x][n_y] + 1;
				fq.push({ nx, ny });
			}
		}
	}
	return;
}

void BFS()
{
	while (!q.empty()) {
		int n_x = q.front().first;
		int n_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = n_x + dx[i];
			int ny = n_y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (map[nx][ny] != '#' && dis[nx][ny] > dis[n_x][n_y] + 1 && fire_dis[nx][ny] > dis[n_x][n_y] + 1) {
				dis[nx][ny] = dis[n_x][n_y] + 1;
				q.push({ nx, ny });
			}
		}
	}
	return;
}

int main()
{
	int i, j;
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &m, &n);
		for (i = 0; i < n; i++) scanf("%s", map[i]);
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				dis[i][j] = 2e9;
				fire_dis[i][j] = 2e9;
			}
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				if (map[i][j] == '*') {
					fq.push({ i, j });
					fire_dis[i][j] = 0;
				}
				if (map[i][j] == '@') {
					q.push({ i, j });
					dis[i][j] = 0;
				}
			}
		}
		FBFS();
		BFS();
		int ans = 2e9;
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				if (i <= 0 || j <= 0 || i >= n - 1 || j >= m - 1) {
					if (dis[i][j] < ans) ans = dis[i][j];
				}
			}
		}
		if (ans == 2e9) printf("IMPOSSIBLE\n");
		else printf("%d\n", ans + 1);
		while (!q.empty()) q.pop();
		while (!fq.empty()) fq.pop();
	}
	return 0;
}