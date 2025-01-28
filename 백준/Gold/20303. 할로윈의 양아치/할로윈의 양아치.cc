#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using lD = long double;
using D = double;

int dp[30010][3010];

struct DSU{
    int n;
    vector <int> par, s, candy;
    int size;
    vector <pair<int, int>> vec;
    DSU(int n, vector <int> vec) : n(n), par(n), s(n), candy(n) {
        iota(par.begin(), par.end(), 0);
        fill(s.begin(), s.end(), 1);
        for(int i=1;i<n;i++) candy[i] = vec[i];
    }
    int ffind(int x) {
        if(par[x] == x) return x;
        else return par[x] = ffind(par[x]);
    }
    void funion(int v, int u) {
        v = ffind(v), u = ffind(u);
        if(v == u) return;
        par[u] = v;
        s[v] += s[u];
        candy[v] += candy[u];
    }
    void init() {
        set<int> st;
        for(int i=1;i<n;i++) {
            st.insert(ffind(i));
        }
        size = st.size();
        vec.push_back({0, 0});
        for(auto itr = st.begin();itr!=st.end();itr++) {
            vec.push_back({s[*itr], candy[*itr]});
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i, j;
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> candy(n + 1);
    for(i=1;i<=n;i++) cin >> candy[i];
    DSU dsu(n + 1, candy);
    for(i=0;i<m;i++) {
        int x, y;
        cin >> x >> y;
        dsu.funion(x, y);
    }
    dsu.init();
    // for(i=1;i<=dsu.size;i++) {
    //     cout << dsu.vec[i].first << ' ' << dsu.vec[i].second << "\n";
    // }
    //cout << endl;
    for(i=1;i<=dsu.size;i++) {
        int s = dsu.vec[i].first, c = dsu.vec[i].second;
        for(j=1;j<k;j++) {
            dp[i][j] = dp[i - 1][j];
            if(j >= s) dp[i][j] = max(dp[i - 1][j - s] + c, dp[i][j]);
        }
    }
    // for(i=1;i<=dsu.size;i++) {
    //     for(j=1;j<=k;j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << "\n";
    // }
    int ans = 0;
    for(i=1;i<k;i++) {
        ans = max(ans, dp[dsu.size][i]);
    }
    cout << ans;
}