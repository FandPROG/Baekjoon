#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

ll n, q;
ll arr[200010];
ll sum[200010];

int main()
{
    ll i, j;
    scanf("%lld %lld", &n, &q);
    for(i=0;i<n;i++) scanf("%d", &arr[i]);
    sum[0] = arr[0];
    for(i=1;i<n;i++) sum[i] = sum[i-1] + arr[i];
    while(q--) {
        ll x, y;
        scanf("%lld %lld", &x, &y);
        ll L = lower_bound(arr, arr + n, x) - arr;
        ll R = upper_bound(arr, arr + n, y) - arr - 1;
        if(L >= R) {
            printf("0\n");
            continue;
        }
        ll N = R - L + 1;
        ll sumN = sum[R];
        if(L > 0) sumN -= sum[L - 1];
        ll mx = max((2 - N) * arr[L] + sumN - (arr[L] * 2), N * arr[R] - sumN);
        ll mn_idx = (N / 2);
        ll mn = ((2 * (mn_idx + 1)) - N) * arr[L + mn_idx] + sumN - (2 * (sum[L + mn_idx] - sum[L - 1]));
        printf("%lld\n", mx - mn);
    }
    return 0;
}