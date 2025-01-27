#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using lD = long double;
using D = double;

struct bipartite_union_find {
    int n, sum; vector<int> p, s;
    bipartite_union_find(int n) : n(n), sum(0), p(n+n), s(n+n) {
        iota(p.begin(), p.end(), 0);
        fill(s.begin(), s.begin()+n, 1);
    }
    int neg(int v){ return v < n ? v + n : v - n; }
    int find(int v){ return v == p[v] ? v : p[v] = find(p[v]); }
    void merge(int u, int v){
        u = find(u); v = find(v);
        if(u == v) return;
        if(find(neg(u)) == u) sum -= s[u];
        if(find(neg(v)) == v) sum -= s[v];
        p[u] = v; s[v] += s[u];
        if(find(neg(v)) == v) sum += s[v];
    }
    void add_edge(int u, int v){
        merge(u, neg(v));
        merge(v, neg(u));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int i, j;
    int n, Q;
    cin >> n >> Q;
    bipartite_union_find dsu(n);
    while(Q--) {
        int x, y;
        cin >> x >> y;
        dsu.add_edge(x, y);
        cout << dsu.sum << "\n";
    }
    return 0;
}