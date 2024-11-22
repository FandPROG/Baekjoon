#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

int n, m;
char map[255][255];
int ch[255][255];

int dx[5] = {0, 0, 1, -1};
int dy[5] = {1, -1, 0, 0};

int vcnt[63000];
int ocnt[63000];

int cnt = 0;

void BFS(int x, int y, int now_area_num)
{
    int i, j;
    queue <pair<int, int>> q;
    q.push({x, y});
    ch[x][y] = 1;
    if(map[x][y] == 'v') vcnt[now_area_num]++;
    else if(map[x][y] == 'o') ocnt[now_area_num]++;
    while(!q.empty()) {
        int n_x = q.front().first, n_y = q.front().second;
        q.pop();
        for(i=0;i<4;i++) {
            int nx = n_x + dx[i], ny = n_y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(map[nx][ny] == '#' || ch[nx][ny] == 1) continue;
            if(map[nx][ny] == 'v') vcnt[now_area_num]++;
            if(map[nx][ny] == 'o') ocnt[now_area_num]++;
            ch[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
}

int main()
{
    int i, j;
    scanf("%d %d", &n, &m);
    for(i=0;i<n;i++) {
        scanf("%s", map[i]);
    }
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            if(ch[i][j] == 0 && map[i][j] != '#') {
                BFS(i, j, ++cnt);
            }
        }
    }
    int oans = 0, vans = 0;
    for(i=1;i<=cnt;i++) {
        if(ocnt[i] > vcnt[i]) oans += ocnt[i];
        else vans += vcnt[i];
    }
//    printf("%d\n", cnt);
//    for(i=1;i<=cnt;i++) printf("%d %d\n", ocnt[i], vcnt[i]);
    printf("%d %d", oans, vans);
    return 0;
}