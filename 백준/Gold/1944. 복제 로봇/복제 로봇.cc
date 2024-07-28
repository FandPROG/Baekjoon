#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct dat {
	int x, y, val;
};

bool comp(dat a, dat b) {
	return a.val < b.val;
}

char s[55][55];
int map[55][55];
int par[255];
int n, m;
int dx[5] = { 0, 0, 1, -1 };
int dy[5] = { 1, -1, 0, 0 };
int check[255][255], ch[55][55];
vector <dat> vec;

int ffind(int x) {
	if (x == par[x]) return x;
	else return par[x] = ffind(par[x]);
}

void funion(int x, int y) {
	int a = ffind(x), b = ffind(y);
	if (a < b) par[b] = a;
	else par[a] = b;
	return;
}

void BFS(int x, int y, int L) {
	queue<dat> q;
	q.push({ x, y, 0 });
	ch[x][y] = L;
	int i, j;
	while (!q.empty()) {
		int n_x = q.front().x, n_y = q.front().y;
		int nval = q.front().val;
		q.pop();
		for (i = 0; i < 4; i++) {
			int nx = n_x + dx[i], ny = n_y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (ch[nx][ny] == L || map[nx][ny] == -1) continue;
			if (map[nx][ny] > 0) {
				if (check[L][map[nx][ny]] == 0) {
					check[L][map[nx][ny]] = 1;
					check[map[nx][ny]][L] = 1;
					vec.push_back({ L, map[nx][ny], nval + 1 });
				}
			}
			ch[nx][ny] = L;
			q.push({ nx, ny, nval + 1 });
		}
	}
}

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) scanf("%s", s[i]);
	int num = 2;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (s[i][j] == '1') map[i][j] = -1;
			if (s[i][j] == '0') map[i][j] = 0;
			if (s[i][j] == 'S') map[i][j] = 1;
			if (s[i][j] == 'K') map[i][j] = num++;
		}
	}
	m++;
	for (i = 1; i <= m; i++) par[i] = i;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (map[i][j] > 0) {
				BFS(i, j, map[i][j]);
			}
		}
	}
	int ans = 0;
	int vsz = vec.size();
	sort(vec.begin(), vec.end(), comp);
	for (i = 0; i < vsz; i++) {
		int x = vec[i].x, y = vec[i].y, nval = vec[i].val;
		int a = ffind(x), b = ffind(y);
		if (a == b) continue;
		funion(a, b);
		ans += nval;
	}
	for (i = 1; i <= m; i++) ffind(i);
	for (i = 1; i < m; i++) {
		if (par[i] != par[i + 1]) {
			printf("-1");
			return 0;
		}
	}
	printf("%d", ans);
	return 0;
}