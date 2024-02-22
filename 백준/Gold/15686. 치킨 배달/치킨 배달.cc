#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int map[55][55];
vector <pair<int, int>> vec, qx;
int che[15];
queue <pair<int, int>> q;
int ans = 2e9;
int dis[55][55];
int dx[5] = { 0, 0, 1, -1 };
int dy[5] = { 1, -1, 0, 0 };

void BFS()
{
	while (!q.empty()) {
		int n_x = q.front().first, n_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = n_x + dx[i], ny = n_y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (dis[n_x][n_y] + 1 < dis[nx][ny]) {
				dis[nx][ny] = dis[n_x][n_y] + 1;
				q.push({ nx, ny });
			}
		}
	}
}

void DFS(int idx, int x)
{
	int i, j;
	int l = vec.size();
	if (x >= m) {
		for (i = 0; i < qx.size(); i++) {
			q.push(qx[i]);
			dis[qx[i].first][qx[i].second] = 0;
		}
		BFS();
		int sum = 0;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (map[i][j] == 1) sum += dis[i][j];
			}
		}
		if (sum < ans) ans = sum;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				dis[i][j] = 2e9;
			}
		}
		while (!q.empty()) q.pop();
		return;
	}
	for (i = idx; i < l; i++) {
		qx.push_back(vec[i]);
		DFS(i + 1, x + 1);
		qx.pop_back();
	}
}

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) vec.push_back({ i, j });
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			dis[i][j] = 2e9;
		}
	}
	DFS(0, 0);
	printf("%d", ans);
	return 0;
}