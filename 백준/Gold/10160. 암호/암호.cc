#include <stdio.h>

int n, m;
long long dp[1000010];

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	dp[0] = 1;
	for (i = 1; i <= n; i++) {
		dp[i] = (dp[i - 1] * m) % 1000000009;
		if (i >= 5) dp[i] = (2000000018 + dp[i] - (dp[i - 5] * 2)) % 1000000009;
		if (i >= 7) dp[i] = (dp[i] + dp[i - 7]) % 1000000009;
	}
	printf("%lld", dp[n] % 1000000009);
	return 0;
}