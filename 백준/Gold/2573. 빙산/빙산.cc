#include <stdio.h>
#include <queue>

using namespace std;

int n, m;
int map[310][310], ct[310][310];
int cnt, ans;
int ch[310][310];
int dx[5] = { 0, 0, 1, -1 };
int dy[5] = { 1, -1, 0, 0 };

void BFS_1(int x, int y)
{
	int i;
	queue <pair<int, int>> q;
	q.push({ x, y });
	ch[x][y] = cnt;
	while (!q.empty()) {
		int n_x = q.front().first, n_y = q.front().second;
		q.pop();
		for (i = 0; i < 4; i++) {
			int nx = n_x + dx[i], ny = n_y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (ch[nx][ny] == 0 && map[nx][ny] != 0) {
				ch[nx][ny] = cnt;
				q.push({ nx, ny });
			}
		}
	}
}

void BFS_2(int x, int y)
{
	int i, j;
	queue<pair<int, int>> q;
	ch[x][y] = 1;
	q.push({ x, y });
	while (!q.empty()) {
		int n_x = q.front().first, n_y = q.front().second;
		q.pop();
		for (i = 0; i < 4; i++) {
			if (map[n_x + dx[i]][n_y + dy[i]] == 0) ct[n_x][n_y]++;
		}
		for (i = 0; i < 4; i++) {
			int nx = n_x + dx[i], ny = n_y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (ch[nx][ny] == 0 && map[nx][ny] != 0) {
				ch[nx][ny] = 1;
				q.push({ nx, ny });
			}
		}
	}
}

int main()
{
	int i, j;
	int x, y;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	while (1) {
		cnt = 0;
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				if (map[i][j] != 0 && ch[i][j] == 0) {
					cnt++;
					BFS_1(i, j);
					x = i, y = j;
				}
			}
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				ch[i][j] = 0;
			}
		}
		if (cnt == 0) {
			printf("0");
			break;
		}
		else if (cnt >= 2) {
			printf("%d", ans);
			break;
		}
		else {
			ans++;
			BFS_2(x, y);
			for (i = 0; i < n; i++) {
				for (j = 0; j < m; j++) {
					if (map[i][j] == 0) continue;
					if (map[i][j] > ct[i][j]) map[i][j] -= ct[i][j];
					else map[i][j] = 0;
				}
			}
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				ch[i][j] = 0;
				ct[i][j] = 0;
			}
		}
	}
	return 0;
}