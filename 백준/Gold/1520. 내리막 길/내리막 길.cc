#include <stdio.h>

int map[510][510], dp[510][510], n, m;

int dx[5] = { 1, 0, -1, 0 };
int dy[5] = { 0, 1, 0, -1 };

int dfs(int y, int x) {
	int k, nx, ny;
	if (y == m && x == n) return 1;
	else if (dp[y][x] == -1) {
		dp[y][x] = 0;
		for (k = 0; k < 4; k++) {
			ny = y + dy[k];
			nx = x + dx[k];
			if (nx > 0 && nx <= n && ny > 0 && ny <= m && map[y][x] > map[ny][nx]) {
				dp[y][x] += dfs(ny, nx);
			}
		}
	}
	return dp[y][x];
}

int main()
{
	int i, j;
	scanf("%d %d", &m, &n);
	for (i = 0; i <= m; i++) {
		for (j = 0; j <= n; j++) {
			dp[i][j] = -1;
		}
	}
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	printf("%d", dfs(1, 1));
	return 0;
}