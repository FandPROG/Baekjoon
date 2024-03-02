#include <stdio.h>
#include <string.h>

int n;
int dp[5010];
char s[5010];

int main()
{
	int i, j;
	scanf("%s", s + 1);
	s[0] = '0';
	if (s[1] == '0') {
		printf("0");
		return 0;
	}
	n = strlen(s) - 1;
	dp[0] = 1;
	dp[1] = 1;
	for (i = 2; i <= n; i++) {
		int x = s[i] - '0', y = s[i - 1] - '0';
		if (x > 0) dp[i] = dp[i - 1];
		if (y == 0) continue;
		if (y * 10 + x <= 26) dp[i] = (dp[i] + dp[i - 2]) % 1000000;
	}
	printf("%d", dp[n]);
	return 0;
}