#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using lD = long double;
using D = double;

int n, m, k, s;
int p, q;

vector <int> edge[100010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i, j;

    cin >> n >> m >> k >> s;
    cin >> p >> q;

    vector <int> con(n + 1);    
    vector <int> cost(n + 1);

    queue<pair<int, int>> qu;

    for(i=0;i<k;i++) {
        int x;
        cin >> x;
        con[x] = 1;
        qu.push({x, 0});
    }
    for(i=0;i<m;i++) {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    while(!qu.empty()) {
        int idx = qu.front().first, val = qu.front().second;
        qu.pop();
        for(i=0;i<edge[idx].size();i++) {
            int nidx = edge[idx][i];
            if(con[nidx] > 0) continue;
            if(val + 1 > s) continue;
            con[nidx] = 2;
            qu.push({nidx, val + 1});
        }
    }
    
    for(i=1;i<=n;i++) {
        if(con[i] == 2) cost[i] = q;
        else if(con[i] == 0) cost[i] = p;
    }
    
    vector <ll> dis (n + 1);
    for(i=0;i<=n;i++) dis[i] = 1e9 * 1e9 + 7;
    priority_queue<pair<ll, int>> pq;

    dis[1] = 0;
    pq.push({0, 1});
    while(!pq.empty()) {
        int idx = pq.top().second;
        ll val = -pq.top().first;
        pq.pop();
        if(dis[idx] < val) continue;
        for(auto nde : edge[idx]) {
            int nidx = nde;
            if(con[nidx] == 1) continue;
            ll nval = val + (ll)cost[nidx];
            if(nval < dis[nidx]) {
                dis[nidx] = nval;
                pq.push({-nval, nidx});
            }
        }
    }

    // for(i=1;i<=n;i++) cout << dis[i] << ' ';
    // cout << "\n";
    cout << dis[n] - cost[n];

    return 0;
}