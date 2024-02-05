#include <stdio.h>
#include <math.h>

int n;
int dp[50010];
int sqr[300], cnt;

int main()
{
    int i, j;
    scanf("%d", &n);
    int small = sqrt(n);
    for (i = 1; i <= small; i++) sqr[cnt++] = i * i;
    for (i = 1; i <= n; i++) {
        dp[i] = 2e9;
        for (j = 0; j < cnt; j++) {
            if (i >= sqr[j] && dp[i] > dp[i - sqr[j]] + 1) dp[i] = dp[i - sqr[j]] + 1;
        }
    }
    printf("%d", dp[n]);
    return 0;
}