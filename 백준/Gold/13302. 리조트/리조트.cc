#include <stdio.h>
#include <algorithm>

using namespace std;

int n, m;
int ch[110];
int dp[210][210];

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= m; i++) {
		int x;
		scanf("%d", &x);
		ch[x] = 1;
	}
	if (n == m) {
		printf("0");
		return 0;
	}
	for (i = 0; i <= n + 5; i++) {
		for (j = 0; j <= n + 5; j++) {
			dp[i][j] = 2e9;
		}
	}
	dp[0][0] = 0;
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= n; j++) {
			if (dp[i][j] == 2e9) continue;
			if (ch[i + 1] == 1) dp[i + 1][j] = min(dp[i][j], dp[i + 1][j]);
			dp[i + 1][j] = min(dp[i][j] + 10, dp[i + 1][j]);
			if (j >= 3) dp[i + 1][j - 3] = min(dp[i + 1][j - 3], dp[i][j]);
			for (int l = 1; l <= 3; l++) dp[i + l][j + 1] = min(dp[i][j] + 25, dp[i + l][j + 1]);
			for (int l = 1; l <= 5; l++) dp[i + l][j + 2] = min(dp[i][j] + 37, dp[i + l][j + 2]);
		}
	}
	int ans = 2e9;
	for (i = 0; i <= n; i++) ans = min(ans, dp[n][i]);
	long long res = ans * 1000;
	printf("%lld", res);
	return 0;
}