#include <stdio.h>
#include <vector>
#include <algorithm>

int n;
long long k;
long long arr[500010];

long long satang(long long x)
{
    int i;
    long long res = 0;
    for(i=0;i<n;i++) {
        if(arr[i] > x) res += arr[i] - x;
    }
    return res;
}

int main()
{
    int i;
    scanf("%d %lld", &n, &k);
    for(i=0;i<n;i++) scanf("%lld", &arr[i]);
    long long low = 0, high = 1000000000000;
    while(low <= high) {
        long long mid = (low + high)/2;
        long long mid_res = satang(mid);
        if(mid_res <= k) high = mid - 1;
        else low = mid + 1;
    }
    printf("%lld", high + 1);
    return 0;
}