#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, k;
int civil, ans;
int civ[2010][2010];
int par[100010], ch[2010][2010];
int dx[5] = { 0, 0, 1, -1 };
int dy[5] = { 1, -1, 0, 0 };

struct dat {
	int x, y, c;
};

queue <pair<int, int>> q;
queue <dat> q1;

int ffind(int x)
{
	if (par[x] == x) return x;
	else return par[x] = ffind(par[x]);
}

void funion(int x, int y)
{
	int a = ffind(x), b = ffind(y);
	if (a < b) par[b] = a;
	else par[a] = b;
	return;
}

void BFS()
{
	int i, j;
	while (1) {
		if (q.empty() && q1.empty()) break;
		while (!q.empty()) {
			int n_x = q.front().first, n_y = q.front().second;
			q.pop();
			for (i = 0; i < 4; i++) {
				int nx = n_x + dx[i], ny = n_y + dy[i];
				if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
				if (ch[nx][ny] == 0 && civ[nx][ny] == 0) {
					ch[nx][ny] = 1;
					q1.push({ nx, ny, civ[n_x][n_y]});
				}
				else if (civ[nx][ny] != 0) {
					int a = ffind(civ[n_x][n_y]), b = ffind(civ[nx][ny]);
					if (a != b) {
						funion(a, b);
						/*printf("%d %d\n", a, b);
						for (j = 1; j <= k; j++) printf("%d ", ffind(par[j]));
						printf("\n\n\n");*/
						civil--;
						if (civil == 1) return;
					}
				}
			}
		}
		while (!q1.empty()) {
			int nx = q1.front().x, ny = q1.front().y;
			civ[nx][ny] = q1.front().c;
			q.push({ q1.front().x, q1.front().y });
			q1.pop();
		}
		ans++;
	}
}

int main()
{
	int i, j;
	scanf("%d %d", &n, &k);
	for (i = 0; i < k; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		civ[x][y] = ++civil;
		ch[x][y] = 1;
		q.push({ x, y });
	}
	for (i = 1; i <= k; i++) par[i] = i;
	BFS();
	printf("%d", ans);
	return 0;
}