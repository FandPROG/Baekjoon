#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;

int n, m;
priority_queue <int> pq;
vector <pair<int, int>> query;

int main()
{
    int i, j;
    scanf("%d %d", &n, &m);
    for(i=0;i<n;i++) {
        int x;
        scanf("%d", &x);
        pq.push(x);
    }
    for(i=0;i<m;i++) {
        int t, q;
        scanf("%d %d", &t, &q);
        query.push_back({t, q});
    }
    ll ans = 0;
    int idx = 0;
    for(i=0;i<m;i++) {
        while (!pq.empty() && ans < query[i].second) {
            ans += (ll)(pq.top() + query[i].first);
            pq.pop();
        }
    }
    while(!pq.empty()) {
        ans += (ll)(pq.top() + query[m - 1].first);
        pq.pop();
    }
    if(query[m - 1].second <= ans) printf("%lld", ans);
    else printf("-1");
    return 0;
}