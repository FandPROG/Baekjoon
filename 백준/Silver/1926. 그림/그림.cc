#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int map[510][510];
int ch[510][510];
int ans = 0;
int dx[5] = { 0, 0, 1, -1 };
int dy[5] = { 1, -1, 0, 0 };
int cnt[250010];

int BFS(int x, int y)
{
	int i;
	queue <pair<int, int>> q;
	q.push({ x, y });
	ch[x][y] = ans;
	while (!q.empty()) {
		int n_x = q.front().first, n_y = q.front().second;
		q.pop();
		for (i = 0; i < 4; i++) {
			int nx = n_x + dx[i], ny = n_y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (ch[nx][ny] == 0 && map[nx][ny] == 1) {
				ch[nx][ny] = ans;
				q.push({ nx, ny });
			}
		}
	}
	return 0;
}

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (i = 0; i < n; i++) { 
		for (j = 0; j < m; j++) {
			if (ch[i][j] == 0 && map[i][j] == 1) {
				ans++;
				BFS(i, j);
			}
		}
	}
	printf("%d\n", ans);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cnt[ch[i][j]]++;
		}
	}
	int mx = -2e9;
	for (i = 1; i <= n * m; i++) if (mx < cnt[i]) mx = cnt[i];
	printf("%d", mx);
	return 0;
}