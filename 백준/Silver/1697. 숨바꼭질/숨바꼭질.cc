#include <stdio.h>
#include <algorithm>

using namespace std;

int n, k;
int dp[100010];

int main()
{
    int i, j;
    scanf("%d %d", &n, &k);
    if (k == 0) {
        printf("%d", n);
        return 0;
    }
    for (i = n + 1; i <= k; i++) dp[i] = dp[i - 1] + 1;
    for (i = n - 1; i >= 1; i--) dp[i] = dp[i + 1] + 1;
    dp[0] = 2e9;
    for (i = 1; i <= k; i++) {
        if (i % 2 == 0) dp[i] = min(dp[i / 2] + 1, min(dp[i], dp[i - 1] + 1));
        else dp[i] = min(dp[i], min(dp[i - 1] + 1, dp[(i + 1) / 2] + 2));
    }
    printf("%d", dp[k]);
    return 0;
}