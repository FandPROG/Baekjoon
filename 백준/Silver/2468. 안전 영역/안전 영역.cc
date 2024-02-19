#include <stdio.h>
#include <queue>

using namespace std;

int n;
int map[110][110];
int ch[110][110];
int dx[5] = { 0, 0, 1, -1 };
int dy[5] = { 1, -1, 0, 0 };
int max_n_w_h = -2e9, now_water_high;
int ans;

void BFS(int x, int y)
{
	int i, j;
	queue <pair<int, int>> q;
	q.push({ x, y });
	ch[x][y] = 1;
	while (!q.empty()) {
		int n_x = q.front().first, n_y = q.front().second;
		q.pop();
		for (i = 0; i < 4; i++) {
			int nx = n_x + dx[i];
			int ny = n_y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (map[nx][ny] > now_water_high && ch[nx][ny] == 0) {
				ch[nx][ny] = 1;
				q.push({ nx, ny });
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
			scanf("%d", &map[i][j]);
			if (map[i][j] > max_n_w_h) max_n_w_h = map[i][j];
		}
	}
	for (now_water_high = 0; now_water_high <= max_n_w_h; now_water_high++) {
		int cnt = 0;
		for (j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (map[j][k] > now_water_high && ch[j][k] == 0) {
					BFS(j, k);
					cnt++;
				}
			}
		}
		if (cnt > ans) ans = cnt;
		for (j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				ch[j][k] = 0;
			}
		}
	}
	printf("%d", ans);
	return 0;
}