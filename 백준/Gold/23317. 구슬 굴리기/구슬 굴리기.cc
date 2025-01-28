#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using lD = long double;
using D = double;

ll com[31][31];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i, j;
    int n, m;
    cin >> n >> m;
    ll ans = 1;
    vector <pair<ll, ll>> vec;
    com[0][0] = 1;
    for(i=1;i<=n;i++) {
        com[i][0] = 1;
        for(j=1;j<i;j++) {
            com[i][j] = com[i - 1][j] + com[i - 1][j - 1];
        }
        com[i][i] = 1;
    }
    for(i=0;i<m;i++) {
        ll x, y;
        cin >> x >> y;
        vec.push_back({x, y});
    }
    sort(vec.begin(), vec.end());
    ll x = 0, y = 0;
    for(i=0;i<m;i++) {
        ans *= com[vec[i].first - x][vec[i].second - y];
        x = vec[i].first, y = vec[i].second;
    }
    ans *= pow(2, n - x - 1);
    cout << ans;
    return 0;
}