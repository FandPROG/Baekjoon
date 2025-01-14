#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
using ll = long long;

struct dat{
    int idx;
    ll val;
    int color;
};

vector <dat> vec[200010];
int n, m, x;

ll Dijkstra(int blue, int red)
{
    ll dis[200010];
    for(int i = 0;i<=n;i++) dis[i] = (ll)1e9 * (ll)1e9 + (ll)7;
    dis[1] = 0;
    priority_queue<pair<ll, int>> pq;
    pq.push({0, 1});
    while(!pq.empty()) {
        int nw = pq.top().second;
        ll nwval = -pq.top().first;
        pq.pop();
        if(dis[nw] < nwval) continue;
        for(auto i : vec[nw]) {
            int idx = i.idx;
            ll nval = nwval + i.val;
            if(i.color == 1) nval += (ll)red;
            if(i.color == 2) nval += (ll)blue;
            if(nval < dis[idx]) {
                dis[idx] = nval;
                pq.push({-nval, idx});
            }
        }
    }
    return dis[n];
}

ll func(ll y)
{
    return Dijkstra(y, x - y);
}

int main()
{
    int i, j;
    scanf("%d %d %d", &n, &m, &x);
    for(i=0;i<m;i++) {
        int a, b, color;
        ll val;
        scanf("%d %d %lld %d", &a, &b, &val, &color);
        vec[a].push_back({b, val, color});
        vec[b].push_back({a, val, color});
    }
    ll low = 0, high = x;
    while(high - low >= 3) {
        ll p = ((low * 2) + high) / 3, q = (low + (high * 2)) / 3;
        if(func(p) < func(q)) low = p;
        else high = q;
    }
    ll ans = -((ll)1e9 * (ll)1e9 + (ll)7);
    for(int k = low; k<= high;k++) {
        ans = max(ans, func(k));
    }
    printf("%lld", ans);
}