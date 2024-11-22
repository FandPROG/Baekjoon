#include <stdio.h>
#include <algorithm>

using namespace std;

int n, m;
int dp[25][210];

int d[25], p[25];

int main()
{
    int i, j;
    scanf("%d %d", &n, &m);
    for(i=1;i<=m;i++) {
        scanf("%d %d", &d[i], &p[i]);
    }
    for(i=1;i<=m;i++) {
        for(j=1;j<=n;j++) {
            dp[i][j] = dp[i - 1][j];
            if(j < d[i]) continue;
            dp[i][j] = max(dp[i][j], dp[i - 1][j - d[i]] + p[i]);
        }
    }
    int ans = -2e9;
    for(i=1;i<=m;i++) ans = max(ans, dp[i][n]);
    printf("%d", ans);
    return 0;
}