#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX = 50010;
const int LOG = 18;
const ll INF = (ll)1e9 * (ll)1e9 * (ll)7;

struct dat { ll x, y, val; };

bool comp (dat a, dat b) {
    return a.val < b.val;
}

ll V, E;
ll par[MAX];
ll dp[MAX][LOG];
ll mx[MAX][LOG], mx2[MAX][LOG];
ll deep[MAX];
ll MST = 0;

vector<dat> Edge;
vector<pair<ll,ll>> vec[MAX];

ll ffind (ll x) {
    if (x == par[x]) return x;
    else return par[x] = ffind(par[x]);
}

void funion (ll x, ll y) {
    ll a = ffind(x), b = ffind(y);
    if (a < b) par[b] = a;
    else par[a] = b;
}

void dfs (ll x, ll p) {
    dp[x][0] = p;
    deep[x] = deep[p] + 1;
    for (int i = 1; i < LOG; i++) {
        ll mid = dp[x][i - 1];
        dp[x][i] = dp[mid][i - 1];
        auto pr = vector<ll>{ mx[x][i-1], mx2[x][i-1], mx[mid][i-1], mx2[mid][i-1] };
        auto r = pair<ll,ll>{-1,-1};
        for (ll v : pr) {
            if (v > r.first) {
                if (v != r.first) r.second = r.first;
                r.first = v;
            }
            else if (v != r.first && v > r.second) {
                r.second = v;
            }
        }
        mx[x][i]  = r.first;
        mx2[x][i] = r.second;
    }
    for (auto &e : vec[x]) {
        ll u = e.first, w = e.second;
        if (u == p) continue;
        mx[u][0] = w;
        dfs(u, x);
    }
}

int lca (int u, int v) {
    if (deep[u] < deep[v]) swap(u, v);
    int diff = deep[u] - deep[v];
    for (int i = 0; i < LOG; i++) {
        if (diff & (1 << i)) {
            u = dp[u][i];
        }
    }
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; i--) {
        if (dp[u][i] != dp[v][i]) {
            u = dp[u][i];
            v = dp[v][i];
        }
    }
    return dp[u][0];
}

pair<ll,ll> getMaxonPath (ll u, ll v) {
    pair<ll,ll> ans = {0, 0};
    if (deep[u] < deep[v]) swap(u, v);
    ll diff = deep[u] - deep[v];
    for (int i = 0; i < LOG; i++) {
        if (diff & (1 << i)) {
            auto pr = vector<ll>{ mx[u][i], mx2[u][i], ans.first, ans.second };
            auto r  = pair<ll,ll>{-1,-1};
            for (ll x : pr) {
                if (x > r.first) {
                    if (x != r.first) r.second = r.first;
                    r.first = x;
                }
                else if (x != r.first && x > r.second) {
                    r.second = x;
                }
            }
            ans = r;
            u   = dp[u][i];
        }
    }
    if (u == v) return ans;
    for (int i = LOG - 1; i >= 0; i--) {
        if (dp[u][i] != dp[v][i]) {
            auto pr = vector<ll> { mx[u][i], mx[v][i], mx2[u][i], mx2[v][i], ans.first, ans.second };
            auto r = pair<ll,ll> {-1,-1};
            for (ll x : pr) {
                if (x > r.first) {
                    if (x != r.first) r.second = r.first;
                    r.first = x;
                }
                else if (x != r.first && x > r.second) {
                    r.second = x;
                }
            }
            ans = r;
            u = dp[u][i];
            v = dp[v][i];
        }
    }
    auto pr = vector<ll>{ mx[u][0], mx[v][0], mx2[u][0], mx2[v][0], ans.first, ans.second };
    auto r  = pair<ll,ll> {-1,-1};
    for (ll x : pr) {
        if (x > r.first) {
            if (x != r.first) r.second = r.first;
            r.first = x;
        }
        else if (x != r.first && x > r.second) {
            r.second = x;
        }
    }
    ans = r;
    return ans;
}

int sz[MAX], heavy[MAX], head[MAX], pos[MAX], cur;
ll base[MAX];
vector<ll> seg[4*MAX];

int dfs_hld (int u, int p) {
    sz[u] = 1;
    heavy[u] = 0;
    int maxs = 0;
    for (auto &e : vec[u]) {
        int v = e.first;
        if (v == p) continue;
        int s = dfs_hld(v, u);
        if (s > maxs) {
            maxs = s;
            heavy[u] = v;
        }
        sz[u] += s;
    }
    return sz[u];
}

void decomp (int u, int h) {
    head[u] = h;
    pos[u] = cur;
    base[cur] = (u == 1 ? 0 : mx[u][0]);
    cur++;
    if (heavy[u]) decomp(heavy[u], h);
    for (auto &e : vec[u]) {
        int v = e.first;
        if (v == dp[u][0] || v == heavy[u]) continue;
        decomp(v, v);
    }
}

void build (int id, int l, int r) {
    if (l == r) {
        seg[id] = { base[l] };
        return;
    }
    int m = (l + r) >> 1;
    build(id<<1, l, m);
    build(id<<1|1, m+1, r);
    seg[id].resize(seg[id<<1].size() + seg[id<<1|1].size());
    merge(seg[id<<1].begin(), seg[id<<1].end(), seg[id<<1|1].begin(), seg[id<<1|1].end(), seg[id].begin());
}

ll query (int id, int l, int r, int ql, int qr, ll w) {
    if (qr < l || r < ql) return -INF;
    if (ql <= l && r <= qr) {
        auto it = lower_bound(seg[id].begin(), seg[id].end(), w);
        if (it == seg[id].begin()) return -INF;
        return *prev(it);
    }
    int m = (l + r) >> 1;
    ll x = query(id<<1, l, m, ql, qr, w);
    ll y = query(id<<1|1, m+1, r, ql, qr, w);
    return x > y ? x : y;
}

ll path_q (int u, int v, ll w) {
    ll res = -INF;
    while (head[u] != head[v]) {
        if (deep[head[u]] > deep[head[v]]) {
            ll t = query(1, 0, V-1, pos[head[u]], pos[u], w);
            if (t > res) res = t;
            u = dp[head[u]][0];
        } else {
            ll t = query(1, 0, V-1, pos[head[v]], pos[v], w);
            if (t > res) res = t;
            v = dp[head[v]][0];
        }
    }
    if (u != v) {
        if(deep[u] > deep[v]) {
            ll t = query(1, 0, V-1, pos[v]+1, pos[u], w);
            if (t > res) res = t;
        }
        else {
            ll t = query(1, 0, V-1, pos[u]+1, pos[v], w);
            if (t > res) res = t;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> V >> E;
    for (int i = 1; i <= V; i++) par[i] = i;
    Edge.reserve(E);
    for (int i = 0; i < E; i++) {
        ll x, y, z;
        cin >> x >> y >> z;
        Edge.push_back({x, y, z});
    }
    sort(Edge.begin(), Edge.end(), comp);
    vector<int> inMST(E);
    int cnt = 0;
    for (int i = 0; i < E; i++) {
        ll x = Edge[i].x, y = Edge[i].y, z = Edge[i].val;
        if (ffind(x) != ffind(y)) {
            funion(x, y);
            inMST[i] = 1;
            MST += z;
            cnt++;
            vec[x].push_back({y, z});
            vec[y].push_back({x, z});
        }
    }
    if (cnt != V - 1) {
        cout << -1;
        return 0;
    }
    deep[0] = -1;
    mx[1][0] = 0;
    dfs(1, 0);
    dfs_hld(1, 0);
    cur = 0;
    decomp(1, 1);
    build(1, 0, V-1);
    ll ans = INF;
    for (int i = 0; i < E; i++) {
        if (inMST[i]) continue;
        ll x = Edge[i].x, y = Edge[i].y, w = Edge[i].val;
        ll b = path_q(x, y, w);
        if (b > -INF) {
            ll r = MST - b + w;
            if (r > MST && r < ans) ans = r;
        }
    }
    if (ans == INF) cout << -1;
    else cout << ans;
    return 0;
}