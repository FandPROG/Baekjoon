#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

vector<pair<ll, ll>> vec(4);

ll func(ll L)
{
    vector<pair<ll, ll>> sqch = {
        {L, L},
        {L, -L},
        {-L, L},
        {-L, -L}
    };

    vector<int> perm = {0, 1, 2, 3};
    ll minres = (ll)1e9 * (ll)1e9 + 7;

    do {
        ll res = 0;
        for(int i = 0; i < 4; i++) {
            res += abs(vec[i].first - sqch[perm[i]].first) + abs(vec[i].second - sqch[perm[i]].second);
        }
        if(res < minres){
            minres = res;
        }
    } while(next_permutation(perm.begin(), perm.end()));
    
    return minres;
}

int main()
{
    for(int i = 0; i < 4; i++) {
        scanf("%lld %lld", &vec[i].first, &vec[i].second);
        vec[i].first *= 2;
        vec[i].second *= 2;
    }

    ll low = 1, high = 2000000000;
    while(high - low > 3) {
        ll p = (low*2 + high) / 3;
        ll q = (high*2 + low) / 3;
        ll fp = func(p);
        ll fq = func(q);
        if(fp < fq){
            high = q;
        }
        else{
            low = p;
        }
    }

    ll res = (ll)1e9 * (ll)1e9 + 7, ans = -1;
    for(ll k = low; k <= high; k++) {
        ll kres = func(k);
        if(kres < res || (kres == res && k > ans)) {
            ans = k;
            res = kres;
        }
    }

    printf("%lld", ans);
    return 0;
}
