#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using lD = long double;
using D = double;

ll mobius[1000010];

ll getFunc(ll x)
{
    ll ans = 0;
    ll now = 1;
    while(1) {
        if(now * now > x) break;
        ans += mobius[now] * (x / (now * now));
        now++;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll k;
    cin >> k;
    mobius[1] = 1;
    for(ll i=1;i<=1000000;i++) {
        for(ll j=2 * i;j<=1000000;j+=i) {
            mobius[j] -= mobius[i];
        }
    }
    ll low = 0, high = 1e11;
    while(low <= high) {
        ll mid = (low + high) / 2;
        ll res = getFunc(mid);
        if(res >= k) high = mid - 1;
        else low = mid + 1;
    }
    cout << high + 1;
    return 0;
}