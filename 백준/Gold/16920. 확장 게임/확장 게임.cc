#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct dat {
	int x, y, dis;
};

int n, m, p;
char map[1010][1010];
int cnt[1010][1010];
queue <dat> q[10], q2[10];
int dx[5] = { 0, 0, 1, -1 };
int dy[5] = { 1, -1, 0, 0 };
int ans[10], arr[10];

int main()
{
	int i, j;
	scanf("%d %d %d", &n, &m, &p);
	for (i = 1; i <= p; i++) scanf("%d", &arr[i]);
	for (i = 0; i < n; i++) {
		scanf("%s", map[i]);
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (map[i][j] == '.' || map[i][j] == '#') continue;
			int x = map[i][j] - '0';
			cnt[i][j] = x;
			q[x].push({ i, j, 0 });
		}
	}
	while (1) {
		int ct = 0;
		for (i = 1; i <= p; i++) {
			if (!q[i].empty()) ct = 1;
		}
		if (ct == 0) break;
		for (i = 1; i <= p; i++) {
			while (!q[i].empty()) {
				int n_x = q[i].front().x, n_y = q[i].front().y;
				int ndis = q[i].front().dis;
				q[i].pop();
				for (int k = 0; k < 4; k++) {
					int nx = n_x + dx[k], ny = n_y + dy[k];
					if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
					if (map[nx][ny] == '#' || cnt[nx][ny] > 0) continue;
					if (ndis + 1 >= arr[i]) q2[i].push({ nx, ny, 0 });
					else q[i].push({ nx, ny, ndis + 1 });
					cnt[nx][ny] = i;
				}
			}
			while (!q2[i].empty()) {
				q[i].push(q2[i].front());
				q2[i].pop();
			}
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
//			printf("%d ", cnt[i][j]);
			ans[cnt[i][j]]++;
		}
//		printf("\n");
	}
	for (i = 1; i <= p; i++) printf("%d ", ans[i]);
	return 0;
}