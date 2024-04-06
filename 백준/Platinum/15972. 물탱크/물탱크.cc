#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m, h;
int map[1010][1010];
int arr[1010][1010][5];
int dx[5] = { 0, 0, 0, 1, -1 };
int dy[5] = { 0, 1, -1, 0, 0 };

struct dat {
	int x, y, h;
};

bool operator <(const dat& a, const dat& b) {
	if (a.h == b.h) {
		if (a.x == b.x) {
			return a.y > b.y;
		}
		return a.x > b.x;
	}
	return a.h > b.h;
}

priority_queue <dat> pq;

int main()
{
	int i, j;
	scanf("%d %d %d", &n, &m, &h);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			map[i][j] = h;
			for (int k = 1; k <= 4; k++) {
				arr[i][j][k] = -1;
			}
		}
	}
	for (j = 0; j < m; j++) {
		int x;
		scanf("%d", &x);
		if (x == -1) continue;
		map[0][j] = min(map[0][j], x);
		pq.push({ 0, j, x });
	}
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < m; j++) {
			int x;
			scanf("%d", &x);
			arr[i][j][3] = x;
			arr[i+ 1][j][4] = x;
		}
	}
	for (j = 0; j < m; j++) {
		int x;
		scanf("%d", &x);
		if (x == -1) continue;
		map[n - 1][j] = min(map[n - 1][j], x);
		pq.push({ n - 1, j, x });
	}
	for (i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (x != -1) {
			map[i][0] = min(map[i][0], x);
			pq.push({ i, 0, x });
		}
		for (j = 0; j < m - 1; j++) {
			scanf("%d", &x);
			arr[i][j][1] = x;
			arr[i][j + 1][2] = x;
		}
		scanf("%d", &x);
		if (x != -1) {
			map[i][m - 1] = min(map[i][m - 1], x);
			pq.push({ i, m - 1, x });
		}
	}
	while (!pq.empty()) {
		int n_x = pq.top().x, n_y = pq.top().y, n_h = pq.top().h;
		pq.pop();
		for (i = 1; i <= 4; i++) {
			if (arr[n_x][n_y][i] == -1) continue;
			int nx = n_x + dx[i], ny = n_y + dy[i];
			if (n_h >= map[nx][ny]) continue;
			if (n_h < arr[n_x][n_y][i] && arr[n_x][n_y][i] >= map[nx][ny]) continue;
			int nh;
			if (n_h < arr[n_x][n_y][i]) nh = arr[n_x][n_y][i];
			else nh = n_h;
			map[nx][ny] = nh;
			pq.push({ nx, ny, nh });
		}
	}
	int ans = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			//printf("%d ", map[i][j]);
			ans += map[i][j];
		}
		//printf("\n");
	}
	printf("%d", ans);
	return 0;
}