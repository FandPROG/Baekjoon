#include <stdio.h>
#include <queue>

using namespace std;

int n;
int map[110][110];
int cnt[110][110];
int island;
int dx[5] = { 0, 0, 1, -1 };
int dy[5] = { 1, -1, 0, 0 };
int cn[110][110];
queue <pair<int, int>> q_b;

void BFS(int x, int y)
{
	int i, j;
	queue<pair<int, int>> q;
	q.push({ x, y });
	cnt[x][y] = island;
	while (!q.empty()) {
		int n_x = q.front().first, n_y = q.front().second;
		q.pop();
		for (i = 0; i < 4; i++) {
			int nx = n_x + dx[i], ny = n_y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (map[nx][ny] == 1 && cnt[nx][ny] == 0) {
				cnt[nx][ny] = island;
				q.push({ nx, ny });
			}
		}
	}
}

void BFS_bridge()
{
	while (!q_b.empty()) {
		int n_x = q_b.front().first, n_y = q_b.front().second;
		q_b.pop();
		for (int i = 0; i < 4; i++) {
			int nx = n_x + dx[i], ny = n_y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (cn[nx][ny] > cn[n_x][n_y] + 1) {
				cn[nx][ny] = cn[n_x][n_y] + 1;
				q_b.push({ nx, ny });
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
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (cnt[i][j] == 0 && map[i][j] == 1) {
				island++;
				BFS(i, j);
			}
		}
	}
	int ans = 2e9;
	for (int k = 1; k <= island; k++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (cnt[i][j] == k) {
					cn[i][j] = 0;
					q_b.push({ i, j });
				}
				else cn[i][j] = 2e9;
			}
		}
		BFS_bridge();
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (map[i][j] == 1 && cnt[i][j] != k) {
					if (cn[i][j] < ans) ans = cn[i][j];
				}
			}
		}
		while (!q_b.empty()) q_b.pop();
	}
	printf("%d", ans - 1);
	return 0;
}