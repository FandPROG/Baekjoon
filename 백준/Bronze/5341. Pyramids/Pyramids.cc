#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int main()
{
    int i, j;
    while(1) {
        int x;
        scanf("%d", &x);
        if(x == 0) break;
        ll ans = 0;
        for(i=1;i<=x;i++) ans += i;
        printf("%lld\n", ans);
    }
    return 0;
}