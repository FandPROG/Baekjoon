#include <stdio.h>
#include <queue>

using namespace std;

int n, m, kase, t;
int map[55][55];
int ct[55][55];
int cnt = 0;
int dx[5] = { 0, 0, 1, -1 };
int dy[5] = { 1, -1, 0, 0 };

void BFS(int sx, int sy)
{
    int i, j;
    queue <pair<int, int>> q;
    q.push({ sx, sy });
    ct[sx][sy] = cnt;
    while (!q.empty()) {
        int nx = q.front().first, ny = q.front().second;
        q.pop();
        for (i = 0; i < 4; i++) {
            int n_x = nx + dx[i], n_y = ny + dy[i];
            if (n_x < 0 || n_y < 0 || n_x >= n || n_y >= m) continue;
            if (map[n_x][n_y] == 0 || ct[n_x][n_y] > 0) continue;
            ct[n_x][n_y] = cnt;
            q.push({ n_x, n_y });
        }
    }
    return;
}

int main()
{
    int i, j;
    scanf("%d", &t);
    for (int k = 0; k < t; k++) {
        scanf("%d %d %d", &n, &m, &kase);
        for (i = 0; i < kase; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            map[x][y] = 1;
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (ct[i][j] == 0 && map[i][j] == 1) {
                    cnt++;
                    BFS(i, j);
                }
            }
        }
        printf("%d\n", cnt);
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                ct[i][j] = 0;
                map[i][j] = 0;
            }
        }
        cnt = 0;
    }
    return 0;
}