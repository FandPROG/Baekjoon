#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
char map[110][110];
bool ch[110][110][5];
int safe[110][110];
int dx[5] = { 0, 0, 1, -1 };
int dy[5] = { 1, -1, 0, 0 };

struct dat {
	int x, y, loc;
};

void BFS(int x, int y)
{
	int i;
	queue <dat> q;
	q.push({ x, y, 0 });
	while (!q.empty()) {
		int n_x = q.front().x, n_y = q.front().y;
		int n_lo = q.front().loc;
		q.pop();
		if (map[n_x][n_y] == '+') {
			int nx = n_x + dx[n_lo], ny = n_y + dy[n_lo];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m || ch[nx][ny][n_lo] == 1) continue;
			else {
				if (map[nx][ny] == '#') {
					for (i = 0; i < 4; i++) {
						int fx = n_x + dx[i], fy = n_y + dy[i];
						if (fx < 0 || fy < 0 || fx >= n || fy >= m || ch[fx][fy][i] == 1 || map[fx][fy] == '#') continue;
						else {
							safe[fx][fy] = 1;
							ch[fx][fy][i] = 1;
							q.push({ fx, fy, i });
						}
					}
				}
				else {
					safe[nx][ny] = 1;
					ch[nx][ny][n_lo] = 1;
					q.push({ nx, ny, n_lo });
				}
			}
		}
		else {
			for (i = 0; i < 4; i++) {
				int nx = n_x + dx[i], ny = n_y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m || ch[nx][ny][i] == 1 || map[nx][ny] == '#') continue;
				else {
					ch[nx][ny][i] = 1;
					safe[nx][ny] = 1;
					q.push({ nx, ny, i });
				}
			}
		}
	}
}

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%s", map[i]);
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (map[i][j] == 'W') {
				safe[i][j] = 1;
				BFS(i, j);
			}
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (safe[i][j] == 0 && map[i][j] == '.') printf("P");
			else printf("%c", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}