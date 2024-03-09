#include <stdio.h>

int n;
long long dp[1000010];

int main()
{
	int i, j;
	scanf("%d", &n);
    dp[2] = 1;
	dp[3] = 2;
	dp[4] = 9;
	for (i = 5; i <= n; i++) {
		dp[i] = ((i - 1) % 1000000000 * (dp[i - 1] + dp[i - 2]) % 1000000000);
	}
	printf("%lld", dp[n]);
	return 0;
}