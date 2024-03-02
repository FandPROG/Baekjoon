#include <stdio.h>
#include <algorithm>

using namespace std;

int n, m;
int dp[1010][1010];

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%1d", &dp[i][j]);
		}
	}
	for (i = 1; i < n; i++) {
		for (j = 1; j < m; j++) {
			int mn = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
			if (dp[i][j] == 1) dp[i][j] = mn + 1;
		}
	}
	int ans = -2e9;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			ans = max(dp[i][j], ans);
		}
	}
	printf("%d", ans*ans);
	return 0;
}