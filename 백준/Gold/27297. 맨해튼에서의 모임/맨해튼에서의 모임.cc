#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int n, m;
vector<ll> vec[1010];

int main()
{
    int i, j;
    scanf("%d %d", &n, &m);
    for(i=0;i<m;i++) {
        for(j=0;j<n;j++) {
            ll x;
            scanf("%lld", &x);
            vec[j].push_back(x);
        }
    }
    for(i=0;i<n;i++) {
        sort(vec[i].begin(), vec[i].end());
    }
    vector <ll> ans;
    for(i=0;i<n;i++) {
        if(m % 2) {
            ans.push_back(vec[i][m / 2]);
        }
        else {
            ans.push_back((vec[i][m / 2] + vec[i][m / 2 - 1]) / 2);
        }
    }
    ll sum = 0;
    for(i=0;i<m;i++) {
        for(j=0;j<n;j++) {
            sum += abs(vec[j][i] - ans[j]);
        }
    }
    printf("%lld\n", sum);
    for(i=0;i<n;i++) {
        printf("%lld ", ans[i]);
    }
    return 0;
}