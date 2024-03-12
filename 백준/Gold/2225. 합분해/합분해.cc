#include <stdio.h>
#include <algorithm>

using namespace std;

int n, k;
long long dp[210][210];

int main()
{
	int i, j;
	scanf("%d %d", &n, &k);
	for (i = 0; i <= n; i++) dp[i][1] = 1;
	for (i = 0; i <= n; i++) {
		for (j = 1; j <= k; j++) {
			for (int l = 0; l <= i; l++) {
				dp[i][j] = (dp[i][j] + dp[i - l][j - 1]) % 1000000000;
			}
		}
	}
	/*for (i = 1; i <= n; i++) {
		for (j = 1; j <= k; j++) {
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}*/
	printf("%lld", dp[n][k]);
	return 0;
}