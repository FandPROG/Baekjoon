#include <stdio.h>
#include <queue>

using namespace std;

int n, m;
char s[610][610];
int ch[610][610], ans;
int dx[5] = { 0, 0, 1, -1 };
int dy[5] = { 1, -1, 0, 0 };

void BFS(int x, int y)
{
    int i, j;
    queue<pair<int, int>> q;
    q.push({ x, y });
    ch[x][y] = 1;
    while (!q.empty()) {
        int n_x = q.front().first, n_y = q.front().second;
        q.pop();
        for (i = 0; i < 4; i++) {
            int nx = n_x + dx[i], ny = n_y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (s[nx][ny] != 'X' && ch[nx][ny] == 0) {
                if (s[nx][ny] == 'P') ans++;
                ch[nx][ny] = 1;
                q.push({ nx, ny });
            }
        }
    }
    return;
}

int main()
{
    int i, j;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (s[i][j] == 'I') BFS(i, j);
        }
    }
    if (ans == 0) printf("TT");
    else printf("%d", ans);
    return 0;
}