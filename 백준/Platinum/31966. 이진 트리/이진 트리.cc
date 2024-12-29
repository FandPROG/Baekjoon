#include <stdio.h>
#include <algorithm>

using namespace std;
using ll = long long;

ll fdp[100010];
ll edp[100010];
ll dp[100010];
ll Tsize[100010];
ll N;

ll MOD = 1000000007;

int main()
{
    dp[0] = 1;
    fdp[0] = 1;
    edp[0] = 1;
    Tsize[0] = 1;
    scanf("%lld", &N);
    for(ll i=1;i<=N;i++) {
        ll x, y;
        scanf("%lld %lld", &x, &y);
        ll n = i;
        Tsize[n] = (Tsize[x] + Tsize[y]) % MOD;
        fdp[n] = (fdp[x] + ((fdp[y] + Tsize[y]) % MOD) - 1) % MOD;
        edp[n] = (edp[y] + ((edp[x] + Tsize[x]) % MOD) - 1) % MOD;
        dp[n] = ((((dp[x] + dp[y]) % MOD) + ((Tsize[y] * edp[x]) % MOD)) % MOD + ((Tsize[x] * fdp[y]) % MOD)) % MOD - 1;
    }
    for(ll i=1;i<=N;i++) printf("%lld\n", dp[i] % MOD);
    return 0;
}