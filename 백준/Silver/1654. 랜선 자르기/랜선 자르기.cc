#include <stdio.h>

int n;
long long k, arr[1000010];

long long pandas(long long mid)
{
    int i;
    long long ans = 0;
    for (i = 0; i < n; i++) {
        ans += arr[i] / mid;
    }
    return ans;
}

int main()
{
    int i, j;
    scanf("%d %lld", &n, &k);
    long long low = 1, high = -2e9;
    for (i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
        if (arr[i] > high) high = arr[i] + 1;
    }
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long mid_res = pandas(mid);
        if (mid_res < k) high = mid - 1;
        else low = mid + 1;
    }
    printf("%lld", high);
    return 0;
}