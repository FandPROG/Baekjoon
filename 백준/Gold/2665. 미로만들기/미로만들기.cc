#include <bits/stdc++.h>

using namespace std;

int n;
int mp[55][55];
int dx[5] = {0, 0, 1, -1};
int dy[5] = {1, -1, 0, 0};
int ch[55][55];

int bfs(int x, int y)
{
    deque <pair<int, int>> dq;
    dq.push_back({x, y});
    ch[x][y] = 0;
    while(!dq.empty()) {
        int n_x = dq.front().first, n_y = dq.front().second;
        dq.pop_front();
        for(int i=0;i<4;i++) {
            int nx = n_x + dx[i], ny = n_y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            int cost = (mp[nx][ny] == 0) ? 1 : 0;
            if(ch[nx][ny] <= ch[n_x][n_y] + cost) continue;
            ch[nx][ny] = ch[n_x][n_y] + cost;
            if(cost)dq.push_back({nx, ny});
            else dq.push_front({nx, ny});
        }
    }
    return ch[n-1][n-1];
}

int main()
{
    int i, j;
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            scanf("%1d", &mp[i][j]);
            ch[i][j] = 2e9;
        }
    }
    printf("%d", bfs(0, 0));
    return 0;
}