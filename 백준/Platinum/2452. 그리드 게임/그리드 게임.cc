#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

static const int INF = 2e9;

int n, m;  
int board[110][110];   
int ch[110][110];    
int color[10010]; 
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

vector<int> adj[10010];

int cnt;

void BFS1(int sx, int sy) {
    cnt++;
    color[cnt] = board[sx][sy];
    queue<pair<int,int>> q;
    q.push({sx, sy});
    ch[sx][sy] = cnt;

    while(!q.empty()) {
        auto [x, y] = q.front(); 
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
            if(board[nx][ny] == color[cnt] && ch[nx][ny] == 0) {
                ch[nx][ny] = cnt;
                q.push({nx, ny});
            }
        }
    }
}

void BFS2(int s, vector<int>& dis) {
    for(int i=1; i<=cnt; i++){
        dis[i] = INF;
    }
    dis[s] = 0;

    deque<int> dq;
    dq.push_back(s);

    while(!dq.empty()) {
        int now = dq.front();
        dq.pop_front();

        for(int nxt : adj[now]) {

            int cost = (color[now] == color[nxt]) ? 0 : 1;
            if(dis[now] + cost < dis[nxt]) {
                dis[nxt] = dis[now] + cost;
                if(cost == 0) dq.push_front(nxt);
                else dq.push_back(nxt);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(ch[i][j] == 0) {
                BFS1(i, j);
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int currC = ch[i][j];
            for(int k=0; k<4; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
                int nextC = ch[nx][ny];
                if(currC != nextC) {
                    adj[currC].push_back(nextC);
                }
            }
        }
    }
    vector<int> dis(cnt+1);
    int ans = INF;

    for(int i=1; i<=cnt; i++){
        BFS2(i, dis);
        int mx = -1;
        for(int j=1; j<=cnt; j++){
            mx = max(mx, dis[j]);
        }
        ans = min(ans, mx);
    }

    cout << ans << "\n";
    return 0;
}
