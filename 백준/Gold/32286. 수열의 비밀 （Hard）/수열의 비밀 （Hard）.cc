#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using lD = long double;
using D = double;

const ll MOD = 1000000007;

int k;
ll dp[55];
ll twosq[55];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i, j;
    ll p, q, r, s, a1;
    cin >> k;
    twosq[0] = 1;
    for(i=1;i<=k;i++) {
        twosq[i] = (twosq[i - 1] * 2) % MOD;
    }
    cin >> p >> q >> r >> s;
    cin >> a1;
    dp[1] = a1;
    for(i=2;i<=k;i++) dp[i] = a1 + ((((dp[i - 1]) * (p + r)) % MOD) + (((twosq[i - 1] - 1) * (q + s)) % MOD)) % MOD;

    cout << dp[k];
    return 0;
}