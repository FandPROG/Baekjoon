#include <stdio.h>
#include <vector>

using namespace std;

int n, x, y;

int main()
{
    int i, j;
    scanf("%d %d %d", &n, &x, &y);
    int res = y - x;
    int ans = 0, add = 0;
    for(i=0;i<n;i++) {
        int z;
        scanf("%d", &z);
        if(z < x) {
            add += z;
            continue;
        }
        ans += (z / x);
        if((z / x) * res < (z % x)) {
            add += (z % x) - ((z / x) * res);
        }
    }
    printf("%d\n%d", ans, add);
    return 0;
}