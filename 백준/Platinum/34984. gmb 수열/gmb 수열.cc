#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll MOD = (ll)1e9 + (ll)7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector <int> vec(n + 1);
    int mx = -2e9;
    for(int i=0;i<n;i++) {
        cin >> vec[i];
        mx = max(mx, vec[i] + 1);
    }
    vector <vector<ll>> dp;
    dp.resize(mx * 2, vector<ll>(mx * 2, 0));
    vector <ll> cnt(mx);

    ll ans = 0;
    
    for(int i=0;i<n;i++) {
        int a = vec[i];
        for(int b=0;b<mx;b++) {
            ans = (ans + dp[a + b][b]) % MOD;
            dp[b][a] = (dp[b][a] + dp[a + b][b] + cnt[b]) % MOD;
        }
        cnt[a] = (cnt[a] + 1) % MOD;
    }
    cout << ans % MOD;
    return 0;
}