#include <stdio.h>

int n;
long long dp[1000010];

int main()
{
	int i, j;
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		for (i = 4; i <= n; i++) dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
		printf("%lld\n", dp[n]);
	}
}