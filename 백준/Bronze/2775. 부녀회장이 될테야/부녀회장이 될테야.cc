#include <stdio.h>

int dp[15][15];
int k, n;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int i, j;
		scanf("%d %d", &k, &n);
		for (i = 0; i <= n; i++) dp[0][i] = i;
		for (i = 1; i <= k; i++) {
			dp[i][0] = dp[i - 1][0];
			for (j = 1; j <= n; j++) {
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
			}
		}
		printf("%d\n", dp[k][n]);
	}
	return 0;
}