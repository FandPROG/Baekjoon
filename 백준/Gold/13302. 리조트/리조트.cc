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
	for (i = 0; i <= n + 5; i++) {
		for (j = 0; j <= n + 5; j++) {
			dp[i][j] = 2e9;
		}
	}
	dp[0][0] = 0;
	for (i = 1; i <= n; i++) {
		for (j = 0; j <= n; j++) {
			if (ch[i] == 1) {
				dp[i][j] = dp[i - 1][j];
				continue;
			}
			dp[i][j] = min(dp[i][j], dp[i - 1][j] + 10);
			dp[i][j] = min(dp[i][j], dp[i - 1][j + 3]);
			if (i >= 3 && j >= 1) dp[i][j] = min(dp[i][j], dp[i - 3][j - 1] + 25);
			if (i >= 5 && j >= 2) dp[i][j] = min(dp[i][j], dp[i - 5][j - 2] + 37);
		}
	}
	int ans = 2e9;
	for (i = 0; i <= n; i++) ans = min(ans, dp[n][i]);
	long long res = ans * 1000;
	printf("%lld", res);
	return 0;
}