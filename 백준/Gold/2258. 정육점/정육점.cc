#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int n;
ll m;

struct dat {
    ll x, y;
};

bool comp(dat a, dat b) {
    if(a.x == b.x) return a.y > b.y;
    return a.x < b.x;
}

int main()
{
    scanf("%d %lld", &n, &m);
    vector <dat> vec(n + 1);
    for(int i=1;i<=n;i++) scanf("%lld %lld", &vec[i].y, &vec[i].x);
    sort(vec.begin() + 1, vec.end(), comp);
    vec[0].x = -1;
    ll sum = 0;
    ll ans = 3e9;
    ll val = 0;
    for(int i=1;i<=n;i++) {
        sum += vec[i].y;
        if(vec[i].x == vec[i - 1].x) {
            val += vec[i].x;
            if(sum >= m) {
                ans = min(ans, val);
            }
        }
        else {
            val = vec[i].x;
            if(sum >= m) {
                ans = min(ans, val);
            }
        }
        
    }
    if(ans == 3e9) printf("-1");
    else printf("%lld", ans);
    return 0;
}