#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int n;
vector <pair<int, int>> vec;

int main() 
{
    int i, j;
    scanf("%d", &n);
    ll ans = 0;
    for(i=0;i<n;i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        vec.push_back({x, y});
        ans += y;
    }
    sort(vec.begin(), vec.end());
    ll res;
    if(ans % 2) {
        res = (ans + 1) / 2;
    }
    else {
        res = ans / 2;
    }
    ll now = 0;
    for(i=0;i<n;i++) {
        now += vec[i].second;
        if(now >= res) {
            printf("%d", vec[i].first);
            return 0;
        }
    }
    return 0;
}