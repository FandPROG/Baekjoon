#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, m;
        ll k;
        scanf("%d %d %lld", &n, &m, &k);
        vector<ll> vec(n + 1);
        for(int i=1;i<=n;i++) scanf("%lld", &vec[i]);
        vector <ll> sum(n + 1);
        for(int i=1;i<=n;i++) sum[i] = sum[i - 1] + vec[i];
        int ans = 0;
        for(int i=1;i<=n;i++) {
            ll res;
            if(i + m - 1 > n) 
                res = sum[n] - sum[i - 1] + sum[i + m - 1 - n];
            else 
                res = sum[i + m - 1] - sum[i - 1];
            if(res < k) {
                //printf("%d %d %lld\n", i, i + m - 1, res);
                ans++;
            }
        }
        if(n == m && ans > 0) printf("1\n");
        else printf("%d\n", ans);
    }
    return 0;
}