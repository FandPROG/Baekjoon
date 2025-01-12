#include <stdio.h>
#include <vector>

using namespace std;
using ll = long long;

int main()
{
    ll n, k;
    scanf("%lld %lld", &n, &k);
    ll res8 = 0, res4 = 0, res1 = 0;
    if(n >= 8) {
        res8 = n / 8;
        n %= 8;
    }
    if(n >= 4) {
        res4 = n / 4;
        n %= 4;
    }
    if(n >= 1) {
        res1 = n / 1;
    }
    ll sum = res1 + res4 + res8;
    if(sum > k) {
        printf("-1");
        return 0;
    }
    if(sum < k) {
        if(res8 > 0 && k - sum >= res8) {
            res4 += (res8 * 2);
            res8 = 0;
            sum = res4 + res1 + res8;
        }
        if(res4 > 0 && k - sum >= res4 * 3) {
            res1 += (res4 * 4);
            res4 = 0;
            sum = res1 + res4 + res8;
        }
    }

    vector <pair<ll, ll>> vec;
    if(res8 > 0) vec.push_back({8, res8});
    if(res4 > 0) vec.push_back({4, res4});
    if(res1 > 0) vec.push_back({1, res1});
    
    printf("%lld\n", vec.size());
    printf("%lld %lld\n", k - sum, vec[0].first);
    ll time = k - sum + vec[0].second;
    for(ll i=1;i<vec.size();i++) {
        printf("%lld %lld\n", time, vec[i].first);
        time += vec[i].second;
    }
    return 0;
}