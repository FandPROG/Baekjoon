#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[100010][2];
int n;

int main()
{
	int i, j;
	scanf("%d", &n);
	dp[1][0] = 1;
	dp[1][1] = 2;
	for (i = 2; i <= n; i++) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % 9901;
		dp[i][1] = (dp[i - 1][0] * 2 + dp[i - 1][1]) % 9901;
	}
	printf("%d", (dp[n][0] + dp[n][1]) % 9901);
	return 0;
}