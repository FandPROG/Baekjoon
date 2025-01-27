#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using lD = long double;
using D = double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, k;
    cin >> n >> k;
    if(n <= k) {
        cout << n * 2 - 1;
    }
    else if(k == 1) {
        cout << n * n;
    }
    else {
        //k + 1 ~ n - 1까지의 합 + n
        int l = k + 1, r = n - 1;
        ll res = 0;
        for(ll i=l;i<=r;i++) res += i;
        res *= 2;
        res += n;
        ll ans = res / k;
        if(res % k > 0) ans++;
        cout << k * 2 + ans;
    }
    return 0;
}