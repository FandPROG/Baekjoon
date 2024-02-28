#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int R, C;
char s[1510][1510];
int ch[1510][1510], ch2[1510][1510];
queue <pair<int, int>> q, q1, q2, q3;
int dx[5] = { 0, 0, 1, -1 };
int dy[5] = { 1, -1, 0, 0 };

int main()
{
	int i, j;
	scanf("%d %d", &R, &C);
	for (i = 0; i < R; i++) scanf("%s", s[i]);
	int sx, sy;
	for (i = 0; i < R; i++) {
		for (j = 0; j < C; j++) {
			if (s[i][j] == 'L') sx = i, sy = j;
			if (s[i][j] != 'X') q.push({ i, j });
		}
	}
	int day = 0;
	q2.push({ sx, sy });
	ch2[sx][sy] = 1;
	while (1)
	{
		while (!q.empty()) {
			int n_x = q.front().first, n_y = q.front().second;
            ch[n_x][n_y] = 1;
			q.pop();
			for (i = 0; i < 4; i++) {
				int nx = n_x + dx[i], ny = n_y + dy[i];
				if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
				if (ch[nx][ny] == 1) continue;
				if(s[nx][ny] == 'X') q1.push({nx, ny});
			    ch[nx][ny] = 1;
			}
		}
		while (!q1.empty()) {
			int nx = q1.front().first, ny = q1.front().second;
			q1.pop();
			s[nx][ny] = '.';
			q.push({ nx, ny });
		}
		day++;
		while (!q2.empty()) {
			int n_x = q2.front().first, n_y = q2.front().second;
			q2.pop();
			for (i = 0; i < 4; i++) {
				int nx = n_x + dx[i], ny = n_y + dy[i];
				if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
				if (ch2[nx][ny] == 1) continue;
				ch2[nx][ny] = 1;
				if (s[nx][ny] == 'X') {
					q3.push({ nx, ny });
					continue;
				}
				if (s[nx][ny] == 'L') {
					printf("%d", day);
					return 0;
				}
				q2.push({ nx, ny });
			}
		}
		while (!q3.empty()) {
			q2.push(q3.front());
			q3.pop();
		}
	}
	return 0;
}