#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using lD = long double;
using D = double;

struct DSU{
    int n, sum;
    vector <int> par, s;
    DSU(int n) : n(n), sum(0), par(n<<1), s(n<<1) {
        iota(par.begin(), par.end(), 0);
        fill(s.begin(), s.end(), 1);
    }
    int rev(int v) {
        return v < n ? v + n : v - n;
    }
    int ffind(int x) {
        if(par[x] == x) return x;
        else return par[x] = ffind(par[x]);
    }
    void funion(int v, int u) {
        u = ffind(u), v = ffind(v);
        if(u == v) return;
        if(ffind(rev(u)) == u) sum -= s[u];
        if(ffind(rev(v)) == v) sum -= s[v];
        par[u] = v;
        s[v] += s[u];
        if(ffind(rev(v)) == v) sum += s[v];
    }
    void merge(int x, int y) {
        funion(x, rev(y));
        funion(rev(x), y);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i, j;
    int n, q;
    cin >> n >> q;
    DSU dsu(n + 1);
    while(q--) {
        int x, y;
        cin >> x >> y;
        dsu.merge(x, y);
        cout << dsu.sum / 2 << "\n";
    }
    return 0;
}