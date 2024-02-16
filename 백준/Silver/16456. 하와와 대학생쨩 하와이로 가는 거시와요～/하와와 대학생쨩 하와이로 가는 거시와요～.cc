#include <stdio.h>

int n;
int dp[50010];

int main()
{
	int i, j;
	scanf("%d", &n);
	dp[2] = 1;
	dp[1] = 1;
	dp[3] = 2;
	for (i = 4; i <= n; i++) dp[i] = (dp[i - 1] + dp[i - 3]) % 1000000009;
	printf("%d", dp[n]);
	return 0;
}