#include <stdio.h>

int n;
int dp[1010];

int main()
{
	int i, j;
	scanf("%d", &n);
	dp[n] = 1;
	for (i = n - 1; i >= 1; i--) {
		if (dp[i + 1] == 0) dp[i] = 1;
		else if (dp[i + 1] == 1) dp[i] = 0;
		if (i <= n - 3) {
			if (dp[i + 3] == 0) dp[i] = 1;
		}
	}
	if (dp[1] == 1) printf("SK");
	else printf("CY");
}