#include <stdio.h>

int dp[1010][1010];

int main()
{
	int a, b, i, j;
	dp[1][1] = 1;
	scanf("%d %d", &a, &b);
	for(i=2;i<=a+1;i++) {
		for(j=1;j<=b+1;j++) {
			dp[i][j] = (dp[i-1][j] + dp[i-1][j-1])%10007;
		}
	}
	printf("%d", dp[a+1][b+1]%10007);
	return 0;
}