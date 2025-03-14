#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using lD = long double;
using D = double;

int dx[10] = {0, 1, 1, -1, -1};
int dy[10] = {-1, 0, -1, 0, -1};
int nox[5] = {0, 1, -1};
int noy[5] = {1, 1, 1};

string mp[550];
int dis[550][550];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i, j;
    int h, w;
    cin >> h >> w;
    for(i=0;i<h;i++) {
        cin >> mp[i];
    }

    deque <pair<int, int>> dq;

    int ex, ey;

    for(i=0;i<h;i++) {
        for(j=0;j<w;j++) {
            dis[i][j] = 2e9;
            if(mp[i][j] == 'K') {
                dis[i][j] = 0;
                dq.push_back({i, j});
            }
            if(mp[i][j] == '*') {
                ex = i, ey = j;
            }
        }
    }

    while(!dq.empty()) {
        int n_x = dq.front().first, n_y = dq.front().second;
        dq.pop_front();
        for(i=0;i<3;i++) {
            int nx = n_x + nox[i];
            int ny = n_y + noy[i];
            if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
            if(mp[nx][ny] == '#') continue;
            if(dis[nx][ny] <= dis[n_x][n_y]) continue;
            dq.push_front({nx, ny});
            dis[nx][ny] = dis[n_x][n_y];
        }
        for(i=0;i<5;i++) {
            int nx = n_x + dx[i];
            int ny = n_y + dy[i];
            if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
            if(mp[nx][ny] == '#') continue;
            if(dis[nx][ny] <= dis[n_x][n_y] + 1) continue;
            dq.push_back({nx, ny});
            dis[nx][ny] = dis[n_x][n_y] + 1;
        }
    }
    if(dis[ex][ey] == 2e9) cout << "-1";
    else cout << dis[ex][ey];
    return 0;
}