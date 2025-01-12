#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int n, m;
ll arr[110];
ll dp[110][55], sum[110];

int main()
{
    int i, j;
    scanf("%d %d", &n, &m);
    for(i=1;i<=n;i++) {
        scanf("%lld", &arr[i]);
        sum[i] = sum[i - 1] + arr[i];
    }
    for(i=0;i<=n;i++) {
        for(j=1;j<=m;j++) {
            dp[i][j] = -2e9;
        }
    }
    dp[1][1] = arr[1];
    for(i=2;i<=n;i++) {
        for(j=1;j<=m;j++) {
            dp[i][j] = dp[i - 1][j];
            if(j == 1) {
                dp[i][j] = max(dp[i][j], sum[i]);
            }
            for(int k=0;k<=i - 2;k++) {
                dp[i][j] = max(dp[i][j], dp[k][j - 1] + sum[i] - sum[k + 1]);
            }
        }
    }
    printf("%lld", dp[n][m]);
    return 0;
}