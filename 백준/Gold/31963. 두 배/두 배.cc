#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int n;
vector <int> vec, ans;

int getres(int i) {
    int j;
    ll x = vec[i-1], y = vec[i];
    for (j = 0; j < 20; j++) x *= 2;
    for (j = -20; j < 0; j++) {
        if (x <= y) {
            return j;
        }
        x /= 2;
    }
    for (j = 0; j < 20; j++) {
        if (x <= y) {
            return j;
        }
        y *= 2;
    }
    return 20;
}

int main()
{
    int i, j;
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        int x;
        scanf("%d", &x);
        vec.push_back(x);
    }
    for(i=1;i<n;i++) ans.push_back(getres(i));
    ll res = 0;
    for(i=0;i<n-1;i++) {
        if(ans[i] > 0) {
            res += ans[i];
            ans[i + 1] += ans[i];
        }
    }
    printf("%lld", res);
    return 0;
}