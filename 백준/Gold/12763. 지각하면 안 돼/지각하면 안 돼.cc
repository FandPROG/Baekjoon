#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;

struct dat{
    int y, t, c;
};

int v, e;
int t, m;

vector <dat> vec[110];
int dis[110][10010];

void Dijkstra(int s)
{
    int i, j;
    priority_queue<pair<int, pair<int, int>>> pq; // f = 돈, s.f = idx, s.s = 시간
    pq.push({0, {s, 0}});
    dis[0][0] = 0;
    while(!pq.empty()) {
        int nmon = -pq.top().first, nidx = pq.top().second.first;
        int nval = pq.top().second.second;
        pq.pop();
        if(dis[nidx][nval] < nmon) continue;
        for(i=0;i<vec[nidx].size();i++) {
            int idx = vec[nidx][i].y;
            int val = nval + vec[nidx][i].t;
            int mon = nmon + vec[nidx][i].c;
            if(val > t || mon > m) continue;
            if(dis[idx][val] > mon) {
                dis[idx][val] = mon;
                pq.push({-mon, {idx, val}});
            }
        }
    }
}

int main()
{
    int i, j;
    scanf("%d", &v);
    scanf("%d %d %d", &t, &m, &e);
    for(i=0;i<e;i++) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        vec[a].push_back({b, c, d});
        vec[b].push_back({a, c, d});
    }
    for(i=0;i<=v;i++) {
        for(j=0;j<=t;j++) {
            dis[i][j] = 2e9;
        }
    }
    Dijkstra(1);
    int ans = 2e9;
    for(i=0;i<=t;i++) {
        ans = min(ans, dis[v][i]);
    }
    if(ans == 2e9) printf("-1");
    else printf("%d", ans);
    return 0;
}