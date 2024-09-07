#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int n, m;
vector <pair<ll, int>> cow;
vector <ll> cane, ans;
ll first_cow;

int main()
{
    int i, j;
    scanf("%d %d", &n, &m);
    ll now_cow = -2e9;
    for(i=0;i<n;i++) {
        ll x;
        scanf("%lld", &x);
        if(now_cow < x) {
            cow.push_back({x, i}); //소의 키, 인덱스 저장
            now_cow = x;
        }
        ans.push_back(x);
    }
    first_cow = cow[0].first;
    for(i=0;i<m;i++) {
        ll x;
        scanf("%lld", &x);
        cane.push_back(x);
    }
    for(i=0;i<m;i++) {
        ll now = cane[i];
        ll tall = 0;
        if(now <= first_cow) {
            first_cow += now;
            continue;
        }
        else {
            tall = first_cow;
            first_cow *= 2;
        }
        for(j=1;j<cow.size();j++) {
            int idx = cow[j].second;
            ll h = ans[idx];
            if(h > tall) {
                if(h >= now) {
                    ans[idx] += (now - tall);
                    break;
                }
                else {
                    ll imsi = ans[idx];
                    ans[idx] += (ans[idx] - tall);
                    tall = imsi;
                }
            }
        }
    }
    printf("%lld\n", first_cow);
    for(i=1;i<ans.size();i++) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}