#include <stdio.h>
#include <algorithm>

using namespace std;
int dp[2010][2010];
int arr[1010];
int n, m, a, d;

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i <= n + d - 1; i++) {
		for (j = 0; j <= n; j++) {
			dp[i][j] = -2e9;
		}
	}
	dp[0][0] = 0;
	for (i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		dp[i][0] = dp[i - 1][0] + arr[i];
	}
	if (dp[n][0] >= m) {
		printf("0");
		return 0;
	}
	scanf("%d %d", &a, &d);
	for (i = 1; i <= n + d - 1; i++) {
		for (j = 1; j <= n; j++) {
			if (i < d) continue;
			dp[i][j] = max(dp[i - 1][j] + arr[i], dp[i - d][j - 1] + a);
		}
	}
/*	for (i = 0; i <= n + d - 1; i++) {
		for (j = 0; j <= n; j++) {
			if (dp[i][j] == -2e9) printf("INF ");
			else printf("%d ", dp[i][j]);
		}
		printf("\n");
	}*/
	for (i = 0; i <= n; i++) {
		if (dp[n + d - 1][i] >= m) {
			printf("%d", i);
			return 0;
		}
	}
	printf("-1");
	return 0;
}