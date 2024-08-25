#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

int sx, sy;
int ex, ey;

int n = 10;
int m = 9;

int dis[10][10];

int dx[10] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[10] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int dia[10][5] = {
	{2, 4, 4},
	{2, 5, 5},
	{0, 6, 6},
	{0, 5, 5},
	{1, 7, 7},
	{1, 4, 4},
	{3, 6, 6},
	{3, 7, 7}
};

int main()
{
	int i, j;
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= m; j++) {
			dis[i][j] = 2e9;
		}
	}
	scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
	queue <pair<int, int>> q;
	q.push({ sx, sy });
	dis[sx][sy] = 0;
	while (!q.empty())
	{
		int n_x = q.front().first, n_y = q.front().second;
		q.pop();
		for (i = 0; i < 8; i++) {
			int nx = n_x, ny = n_y;
			int ch = 0;
			for (j = 0; j < 3; j++) {
				nx += dx[dia[i][j]];
				ny += dy[dia[i][j]];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m ) {
					ch = 1;
					break;
				}
				if (ex == nx && ey == ny && j < 2) {
					ch = 1;
					break;
				}
				
			}
			if (ch == 0) {
				if (dis[nx][ny] > dis[n_x][n_y] + 1) {
					dis[nx][ny] = dis[n_x][n_y] + 1;
					q.push({ nx, ny });
				}
			}
		}
	}
	if (dis[ex][ey] == 2e9) printf("-1");
	else printf("%d", dis[ex][ey]);
	return 0;
}