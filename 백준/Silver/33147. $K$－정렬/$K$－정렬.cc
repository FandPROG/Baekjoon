#include <stdio.h>
#include <cmath>

using namespace std;
using ll = long long;

ll n, k;

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main()
{
    ll i, j;
    scanf("%lld %lld", &n, &k);
    ll res = gcd(n, k);
    for(i=0;i<n;i++) {
        ll x;
        scanf("%lld", &x);
        ll ans = fabs(x - i);
        if(ans % res > 0) {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}