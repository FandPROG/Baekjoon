#include <stdio.h>
#include <queue>

using namespace std;

int n;
int dx[10] = { 2, 2, -2, -2, 1, -1, 1, -1 };
int dy[10] = { -1, 1, 1, -1 , 2, 2, -2, -2};

int BFS(int sx, int sy, int ex, int ey)
{
	int i, dis[310][310];
	queue<pair<int, int>> q;
	q.push({ sx, sy });
	for (i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			dis[i][j] = 2e9;
		}
	}
	dis[sx][sy] = 0;
	while (!q.empty()) {
		int n_x = q.front().first, n_y = q.front().second;
		q.pop();
		for (i = 0; i < 8; i++) {
			int nx = n_x + dx[i], ny = n_y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (dis[nx][ny] > dis[n_x][n_y] + 1) {
				dis[nx][ny] = dis[n_x][n_y] + 1;
				q.push({ nx, ny });
			}
		}
	}
	return dis[ex][ey];
}

int main()
{
	int i, j;
	int t;
	scanf("%d", &t);
	while (t--) {
		int sx, sy, ex, ey;
		scanf("%d %d %d %d %d", &n, &sx, &sy, &ex, &ey);
		printf("%d\n", BFS(sx, sy, ex, ey));
	}
}