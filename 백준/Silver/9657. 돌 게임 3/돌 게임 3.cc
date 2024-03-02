#include <stdio.h>
#include <algorithm>

int n;
int dp[1010];

int main()
{
	int i, j;
	scanf("%d", &n);
	dp[n] = 1;
	for (i = n - 1; i >= 1; i--) {
		if (dp[i + 1] == 0) dp[i] = 1;
		if (i + 3 <= n && dp[i + 3] == 1) dp[i] = 0;
		if (i + 4 <= n && dp[i + 4] == 1) dp[i] = 0;
	}
	if (dp[1] == 1 || dp[3] == 1 || dp[4] == 1) printf("SK");
	else printf("CY");
}