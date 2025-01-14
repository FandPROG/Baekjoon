#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

int main()
{
    int n;
    scanf("%d", &n);
    vector <ll> vec(n);
    for(int i=0;i<n;i++) scanf("%lld", &vec[i]);
    ll ans = 0, contribute = 0, sum = 0;
    for(int i=0;i<n;i++) {
        contribute += sum;
        vec[i] += contribute;
        ll res = -vec[i];
        ans += abs(res);
        sum += res;
        contribute += res;
        //printf("%d : %lld %lld %lld %lld\n", i, res, ans, sum, contribute);
    }
    printf("%lld", ans);
    return 0;
}