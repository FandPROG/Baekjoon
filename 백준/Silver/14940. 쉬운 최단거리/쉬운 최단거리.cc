#include <stdio.h>
#include <queue>

using namespace std;

int n, m;
int map[1010][1010];
int ct[1010][1010];
int dx[5] = { 0, 0, 1, -1 };
int dy[5] = { 1, -1, 0, 0 };

void BFS(int sx, int sy)
{
    int i, j;
    queue<pair<int, int>> q;
    q.push({ sx, sy });
    ct[sx][sy] = 0;
    while (!q.empty()) {
        int n_x = q.front().first, n_y = q.front().second;
        q.pop();
        for (i = 0; i < 4; i++) {
            int nx = n_x + dx[i], ny = n_y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (map[nx][ny] != 0 && ct[nx][ny] > ct[n_x][n_y] + 1) {
                ct[nx][ny] = ct[n_x][n_y] + 1;
                q.push({ nx, ny });
            }
        }
    }
}

int main()
{
    int i, j, sx, sy;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 2) sx = i, sy = j;
            ct[i][j] = 2e9;
        }
    }
    BFS(sx, sy);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (ct[i][j] == 2e9 && map[i][j] == 1) printf("-1 ");
            else if (map[i][j] == 0) printf("0 ");
            else printf("%d ", ct[i][j]);
        }
        printf("\n");
    }
    return 0;
}