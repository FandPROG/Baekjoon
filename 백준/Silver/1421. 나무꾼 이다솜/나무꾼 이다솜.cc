#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace  std;
using ll = long long;

int n, c, w;
vector <ll> vec;

int main()
{
    int i, j;
    scanf("%d %d %d", &n, &c, &w);
    ll mx = -2e15;
    for(i=0;i<n;i++) {
        ll x;
        scanf("%lld", &x);
        vec.push_back(x);
        mx = max(mx, x);
    }
    ll ans = -2e15;
    for(i=1;i<=mx;i++) {
        ll sum = 0;
        for(j=0;j<n;j++) {
            if(vec[j] < i) continue;
            ll num = vec[j] / i;
            ll res = vec[j] / i;
            if(vec[j] % i == 0) res--;
            sum += max((ll)0, (num*w*i) - (res*c));
        }
        ans = max(ans, sum);
    }
    printf("%lld", ans);
    return 0;
}