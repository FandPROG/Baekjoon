#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector <pair<int, int>> vec[110][110];
int vis[110][110], light[110][110];
int res;
int dx[5] = { 0, 0, 1, -1 };
int dy[5] = { 1, -1, 0, 0 };

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		int x, y, a, b;
		scanf("%d %d %d %d", &x, &y, &a, &b);
		vec[x][y].push_back({ a, b });
	}
	queue <pair<int, int>> q;
	q.push({ 1, 1 });
	vis[1][1] = 1;
	light[1][1] = 1;
	res++;
	while (!q.empty()) {
		int n_x = q.front().first, n_y = q.front().second;
		q.pop();
		for (i = 0; i < vec[n_x][n_y].size(); i++) {
			int nx = vec[n_x][n_y][i].first;
			int ny = vec[n_x][n_y][i].second;
			if (light[nx][ny] == 1) continue;
			light[nx][ny] = 1;
			res++;
			for (j = 0; j < 4; j++) {
				int nox = nx + dx[j], noy = ny + dy[j];
				if (nox < 1 || noy < 1 || nox > n || noy > n) continue;
				if (vis[nox][noy] == 1) {
					vis[nx][ny] = 1;
					q.push({ nx, ny });
					break;
				}
			}
		}
		for (i = 0; i < 4; i++) {
			int nx = n_x + dx[i], ny = n_y + dy[i];
			if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
			if (light[nx][ny] == 0 || vis[nx][ny] == 1) continue;
			vis[nx][ny] = 1;
			q.push({ nx, ny });
		}
	}
	printf("%d", res);
	return 0;
}