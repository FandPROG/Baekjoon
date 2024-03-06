#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<pair<int, int>> vec[1010];
int dis[1010];
int s, e;
int way[1010];
vector <int> ans;

void Dijkstra(int x)
{
    int i, j;
    priority_queue <pair<int, int>> pq;
    dis[x] = 0;
    pq.push({0, x});
    while(!pq.empty()) {
        int now_idx = pq.top().second, now_val = -pq.top().first;
        pq.pop();
        if(dis[now_idx] < now_val) continue;
        for(i=0;i<vec[now_idx].size();i++) {
            int idx = vec[now_idx][i].first, val = now_val + vec[now_idx][i].second;
            if(dis[idx] > val) {
                dis[idx] = val;
                pq.push({-val, idx});
                way[idx] = now_idx;
            }
        }
    }
}

void DFS(int x)
{
    if(x == -1) return;
    else {
        ans.push_back(x);
        DFS(way[x]);
    }
}

int main()
{
    int i, j;
    scanf("%d %d", &n, &m);
    for(i=0;i<m;i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        vec[x].push_back({y, z});
    }
    scanf("%d %d", &s, &e);
    for(i=1;i<=n;i++) dis[i] = 2e9;
    Dijkstra(s);
    printf("%d\n", dis[e]);
    way[s] = -1;
    DFS(e);
    printf("%d\n", ans.size());
    for(i=ans.size() - 1;i>=0;i--) printf("%d ", ans[i]);
    return 0;
}