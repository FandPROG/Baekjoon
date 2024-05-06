#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int ch[10010][510];
char map[10010][510];
int r, c, ans;
int end_ch = 0;

int dy[4] = { 1, 1, 1 }, dx[4] = { -1, 0, 1 };

void dfs(int x, int y)
{
	int i;
    ch[x][y] = 1;
	if (end_ch == 1) return;
	if (y == c - 1) {
		ans++;
		end_ch = 1;
		return;
	}
	for (i = 0; i < 3; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
		if (ch[nx][ny] == 1) continue;
		if (map[nx][ny] == 'x') continue;
		dfs(nx, ny);
		if (end_ch == 1) return;
		//ch[nx][ny] = 0;
	}
	return;
}

int main()
{
	int i, j;
	scanf("%d %d", &r, &c);
	for (i = 0; i < r; i++) {
		scanf("%s", map[i]);
	}
	for (i = 0; i < r; i++) {
		dfs(i, 0);
		end_ch = 0;
	}
	printf("%d", ans);
}