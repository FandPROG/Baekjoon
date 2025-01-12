#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int n;
ll MAXLONG = (ll)1e9 * (ll)1e9 + (ll)7;
vector <pair<ll, ll>> monkey;

ll func(ll x)
{
    ll res = -MAXLONG;
    for(int i=0;i<n - 1;i++) {
        for(int j=i + 1;j<n;j++) {
            if(monkey[i].first == monkey[j].first)
                res = max(res, abs(monkey[j].second - monkey[i].second));
            else
                res = max(res, abs(monkey[i].first - monkey[j].first) + abs(monkey[i].second - x) + abs(monkey[j].second - x));
        }
    }
    return res;
}

int main()
{
    scanf("%d", &n);
    ll low = MAXLONG, high = -MAXLONG;
    for(int i=0;i<n;i++) {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        monkey.push_back({a, b});
        low = min(low, b);
        high = max(high, b);
    }
    while(3 <= high - low) {
        ll p = (2* low + high) / 3, q = (low + 2 * high) / 3;
        if(func(p) < func(q)) high = q;
        else low = p;
    }
    ll ans = MAXLONG;
    for(ll k = low;k<=high;k++) {
        ans = min(ans, func(k));
    }
    printf("%lld", ans);
    return 0;
}