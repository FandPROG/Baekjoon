#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
long long arr[500010];
long long sum[500010];

int main()
{
    int i, j;
    scanf("%d", &n);
    for(i=1;i<=n;i++) {
        scanf("%lld", &arr[i]);
    }
    sort(arr + 1, arr + n + 1);
    for(i=1;i<=n;i++) {
        sum[i] = sum[i - 1] + arr[i];
    }
    long long ans = 0;
    for(i=2;i<=n;i++) {
        //printf("%lld %d %ld\n", arr[i], i - 1, sum[i-1]);
        ans += ((arr[i] * (i-1)) - sum[i-1]);
    }
    printf("%lld", ans * 2);
    return 0;
}