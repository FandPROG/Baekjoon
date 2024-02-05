#include <stdio.h>
#include <math.h>

int n;

int main()
{
    int i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        long long x, y;
        scanf("%lld %lld", &x, &y);
        long long dis = sqrt(y - x), dis3 = dis + 1;
        long long dis2 = ((dis * dis) + (dis3 * dis3)) / 2;
        long long res1 = dis * 2, res2 = dis * 2 + 1;
        if (dis * dis == y - x) {
            printf("%lld\n", res1 - 1);
        }
        else if (dis * dis < y - x && y - x <= dis2) printf("%lld\n", res1);
        else printf("%lld\n", res2);
    }
    return 0;
}