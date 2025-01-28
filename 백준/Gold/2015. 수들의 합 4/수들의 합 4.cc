#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using lD = long double;
using D = double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i, j;
    int n, k;
    cin >> n >> k;
    vector <int> arr(n + 1);
    vector <ll> sum(n + 1);
    for(i=1;i<=n;i++) cin >> arr[i];
    for(i=1;i<=n;i++) sum[i] = sum[i - 1] + arr[i];
    map<ll, int> mp;
    ll ans = 0;
    for(i=0;i<=n;i++) {
        if(mp.find(sum[i] - k) != mp.end()) ans +=  mp[sum[i] - k];
        if(mp.find(sum[i]) == mp.end()) mp[sum[i]] = 1;
        else mp[sum[i]]++;
    }
    cout << ans;
}