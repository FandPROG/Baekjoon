#include <stdio.h>

int dp[110][15], sum;

int main()
{
	int a, i, j;
	scanf("%d", &a);
	for(j=1;j<=9;j++) dp[0][j] = 1;
	for(i=1;i<a;i++) {
		for(j=1;j<9;j++) {
			dp[i][j] = dp[i-1][j+1] + dp[i-1][j-1];
			dp[i][j] %= 1000000000;
		}
		dp[i][9] = dp[i-1][8];
		dp[i][9] %= 1000000000;
		dp[i][0] = dp[i-1][1];
		dp[i][0] %= 1000000000;
	}
	for(i=0;i<=9;i++) {
		sum += dp[a-1][i];
		sum %= 1000000000;
	}
	printf("%d", sum);
	return 0;
}
