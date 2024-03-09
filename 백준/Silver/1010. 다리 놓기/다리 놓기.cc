#include <stdio.h>

int dp[50][50];
int t, m, n;

int main()
{
	int i, j;
	for (i = 1; i <= 30; i++) dp[i][i] = 1;
	for (i = 1; i <= 30; i++) dp[1][i] = i;
	for (i = 2; i < 30; i++) {
		for (j = 2; j < 30; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
		}
	}
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%d %d", &n, &m);
		printf("%d\n", dp[n][m]);
	}
	return 0;
}