#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
long long dp[35];

int main()
{
	int i, j;
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 5;
	for (i = 4; i <= 30; i++) {
		for (j = 0; j <= i; j++) {
			dp[i] += dp[j] * dp[i - j - 1];
		}
	}
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		printf("%lld\n", dp[n]);
	}
	return 0;
}