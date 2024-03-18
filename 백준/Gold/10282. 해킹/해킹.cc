#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

vector <pair<int, int>> vec[10010];
int dis[10010];

void Dijkstra(int s)
{
    int i, j;
    priority_queue <pair<int, int>> pq;
    pq.push({0, s});
    dis[s] = 0;
    while(!pq.empty()) {
        int nidx = pq.top().second, nval = -pq.top().first;
        pq.pop();
        if(dis[nidx] < nval) continue;
        for(i=0;i<vec[nidx].size();i++) {
            int idx = vec[nidx][i].first, val = nval + vec[nidx][i].second;
            if(dis[idx] > val) {
                dis[idx] = val;
                pq.push({-val, idx});
            }
        }
    }
}

int main()
{
    int i, j;
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, m, s;
        scanf("%d %d %d", &n, &m, &s);
        for(i=0;i<m;i++) {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            vec[y].push_back({x, z});
        }
        for(i=1;i<=n;i++) dis[i] = 2e9;
        Dijkstra(s);
        int mx = -2e9, ans = 0;
        for(i=1;i<=n;i++) {
            if(dis[i] == 2e9) continue;
            ans++;
            mx = max(mx, dis[i]);
        }
        printf("%d %d\n", ans, mx);
        for(i=1;i<=n;i++) vec[i].clear();
    }
    return 0;
}