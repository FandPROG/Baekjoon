#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using lD = long double;
using D = double;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int R, C;
    cin >> R >> C;
    vector<string> grid(R);
    for (int i = 0; i < R; i++) cin >> grid[i];
    int N;
    cin >> N;
    vector<int> th(N);
    for (int i = 0; i < N; i++) cin >> th[i];
    for (int t = 0; t < N; t++) {
        int h = th[t], r = R - h;
        if(t % 2 == 0){
            for (int c = 0; c < C; c++){
                if(grid[r][c] == 'x') {
                    grid[r][c] = '.';
                    break;
                }
            }
        }
        else {
            for (int c = C - 1; c >= 0; c--){
                if(grid[r][c] == 'x'){
                    grid[r][c] = '.';
                    break;
                }
            }
        }
        vector<vector<bool>> vis(R, vector<bool>(C, 0));
        queue<pair<int,int>> q;
        for (int i = 0; i < C; i++){
            if(grid[R - 1][i] == 'x' && !vis[R - 1][i]){
                vis[R - 1][i] = 1;
                q.push({R - 1, i});
            }
        }
        int dr[4] = {1, -1, 0, 0}, dc[4] = {0, 0, 1, -1};
        while(!q.empty()) {
            auto [cr, cc] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++){
                int nr = cr + dr[d], nc = cc + dc[d];
                if(nr >= 0 && nr < R && nc >= 0 && nc < C){
                    if(!vis[nr][nc] && grid[nr][nc] == 'x'){
                        vis[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
        vector<pair<int,int>> clust;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if(grid[i][j] == 'x' && !vis[i][j]) clust.push_back({i, j});
            }
        }
        if(clust.empty()) continue;
        for(auto p : clust) grid[p.first][p.second] = '.';
        int fall = R;
        for(auto p : clust) {
            int d = 0, cr = p.first, cc = p.second;
            for (int i = cr + 1; i < R; i++) {
                if(grid[i][cc] == 'x') break;
                d++;
            }
            fall = min(fall, d);
        }
        for(auto p : clust) grid[p.first + fall][p.second] = 'x';
    }
    for(auto s : grid) cout << s << "\n";
    return 0;
}
