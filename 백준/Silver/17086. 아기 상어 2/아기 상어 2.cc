#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using lD = long double;
using D = double;

int mp[55][55];
int dx[10] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[10] = {1, -1, 0, 0, -1, 1, -1, 1};
int safe[55][55];
queue<pair<int, int>> q;
int n, m;

void BFS()
{
    int i, j;
    while (!q.empty())
    {
        int n_x = q.front().first, n_y = q.front().second;
        q.pop();
        for(i=0;i<8;i++) {
            int nx = n_x + dx[i], ny = n_y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(safe[nx][ny] == 0) {
                safe[nx][ny] = safe[n_x][n_y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i, j;
    cin >> n >> m;
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            cin >> mp[i][j];
            if(mp[i][j] == 1) {
                q.push({i, j});
                safe[i][j] = 1;
            }
        }
    }
    BFS();
    int ans = -2e9;
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            ans = max(ans, safe[i][j]);
        }
    }
    cout << ans - 1;
}