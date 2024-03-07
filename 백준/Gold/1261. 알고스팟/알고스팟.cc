#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int map[110][110];
int dis[110][110];
int dx[5] = {0, 0, 1, -1};
int dy[5] = {1, -1, 0, 0};

int BFS(int x, int y)
{
    queue<pair<int, int>> q;
    int i, j;
    q.push({x, y});
    dis[x][y] = 0;
    while(!q.empty()) {
        int n_x = q.front().first, n_y = q.front().second;
        q.pop();
        for(i=0;i<4;i++) {
            int nx = n_x + dx[i], ny = n_y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(dis[nx][ny] > dis[n_x][n_y] + map[nx][ny]) {
                dis[nx][ny] = dis[n_x][n_y] + map[nx][ny];
                q.push({nx, ny});
            }
        }
    }
    return 0;
}

int main()
{
    int i, j;
    scanf("%d %d", &m, &n);
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            scanf("%1d", &map[i][j]);
            dis[i][j] = 2e9;
        }
    }
    BFS(0, 0);
    /*for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            printf("%d ", dis[i][j]);
        }
        printf("\n");
    }*/
    printf("%d", dis[n-1][m-1]);
    return 0;
}