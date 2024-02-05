#include <stdio.h>

long long n, arr[10];
long long min1 = 2e9, min2 = 2e9, min3 = 2e9;
int dx[15] = { 1, 1, 1, 1, 2, 2, 2, 3, 3, 4, 4, 5 };
int dy[15] = { 2, 3, 4, 5, 4, 3, 6, 5, 6, 5, 6, 6 };

int da[10] = { 1, 1, 1, 1, 6, 6, 6, 6 };
int db[10] = { 2, 2, 5, 5, 2, 2, 5, 5 };
int dc[10] = { 3, 4, 4, 3, 4, 3, 4, 3 };

int main()
{
    int i;
    long long mx = -2e9, sum = 0;
    scanf("%lld", &n);
    for (i = 1; i <= 6; i++) {
        scanf("%lld", &arr[i]);
        if (arr[i] < min1) min1 = arr[i];
        if (arr[i] > mx) mx = arr[i];
        sum += arr[i];
    }
    for (i = 0; i < 12; i++) {
        if (min2 > arr[dx[i]] + arr[dy[i]]) min2 = arr[dx[i]] + arr[dy[i]];
    }
    for (i = 0; i < 8; i++) {
        long long div = arr[da[i]] + arr[db[i]] + arr[dc[i]];
        if (div < min3) min3 = div;
    }
    long long ans = 4 * min3;
    ans += min2 * ((4 * (n - 1)) + ((n - 2) * 4));
    ans += min1 * ((4 * ((n - 2) * (n - 1))) + ((n - 2) * (n - 2)));
    if (n == 1) printf("%d", sum - mx);
    else printf("%lld", ans);
    return 0;
}