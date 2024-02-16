#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
int k, ends;
int mni[200010];
vector< pair<int, int> > adj[200010];

void dijk()
{

    priority_queue <pair<int, int>> q;
    for (int i = 1; i <= n; i++) {
        mni[i] = 987654321;
    }
    mni[k] = 0;
    q.push({ 0,k });

    while (!q.empty()) {
        int u = q.top().second;
        int value = -q.top().first;
        q.pop();
        if (value > mni[u]) continue;
        for (auto i : adj[u]) {
            int v = i.first;
            int d = i.second;
            if (value + d < mni[v]) {
                mni[v] = value + d;
                q.push({ -mni[v],v });
            }
        }
    }
}

int main()
{
    int i, j;
    scanf("%d %d", &n, &m);
    for (i = 1; i <= m; i++) {
        int a, b, p;
        scanf("%d %d %d", &a, &b, &p);
        adj[a].push_back({ b,p });
        adj[b].push_back({ a,p });
    }
    int a, b, ans = 0, an = 0;
    bool ch1 = 0, ch2 = 0;
    scanf("%d %d", &a, &b);

    k = 1;
    dijk();
    ans += mni[a];
    if (mni[a] == 987654321) {
        ch1 = 1;
    }
    k = a;
    dijk();
    ans += mni[b];
    if (mni[b] == 987654321) {
        ch1 = 1;
    }
    k = b;
    dijk();
    if (mni[n] == 987654321) {
        ch1 = 1;
    }
    ans += mni[n];

    k = 1;
    dijk();
    an += mni[b];
    if (mni[b] == 987654321) {
        ch2 = 1;
    }
    k = b;
    dijk();
    an += mni[a];
    if (mni[a] == 987654321) {
        ch2 = 1;
    }
    k = a;
    dijk();
    if (mni[n] == 987654321) {
        ch2 = 1;
    }
    an += mni[n];
    if (ch1 == 1 && ch2 == 1) {
        printf("-1");
        return 0;
    }
    if (an > ans) printf("%d", ans);
    else printf("%d", an);
    return 0;
}