#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int map[1010][1010];
int cnt[1010][1010], num, nm;
int ans[1010][1010], ch[1010][1010];
int dx[5] = { 0, 0, 1, -1 };
int dy[5] = { 1, -1, 0, 0 };

int BFS(int x, int y)
{
	int i, j;
	queue <pair<int, int>> q;
	q.push({ x, y });
	int ct = 1;
	ch[x][y] = nm;
	while (!q.empty()) {
		int n_x = q.front().first, n_y = q.front().second;
		q.pop();
		for (i = 0; i < 4; i++) {
			int nx = n_x + dx[i], ny = n_y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (ch[nx][ny] != nm && map[nx][ny] == 0) {
				ct++;
				ch[nx][ny] = nm;
				q.push({ nx, ny });
			}
		}
	}
	return ct;
}

void BFS1(int x, int y)
{
	int i, j;
	queue <pair<int, int>> q;
	q.push({ x, y });
	cnt[x][y] = num;
	while (!q.empty()) {
		int n_x = q.front().first, n_y = q.front().second;
		q.pop();
		for (i = 0; i < 4; i++) {
			int nx = n_x + dx[i], ny = n_y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (cnt[nx][ny] != num && map[nx][ny] == 0) {
				cnt[nx][ny] = num;
				q.push({ nx, ny });
			}
			if (map[nx][ny] == 1 && ch[nx][ny] != nm) {
				ans[nx][ny] += num;
				ch[nx][ny] = nm;
			}
		}
	}
}


int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (map[i][j] == 0 && cnt[i][j] == 0) {
				nm++;
				num = BFS(i, j);
				BFS1(i, j);
			}
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (map[i][j] == 1) {
				ans[i][j]++;
			}
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%d", ans[i][j]%10);
		}
		printf("\n");
	}
	return 0;
}