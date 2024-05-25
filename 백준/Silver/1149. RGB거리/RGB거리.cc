#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int dp[1010][5];
int arr[1010][5];

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= 3; j++) {
			scanf("%d", &arr[i][j]);
			dp[i][j] = 2e9;
		}
	}
	dp[1][1] = arr[1][1];
	dp[1][2] = arr[1][2];
	dp[1][3] = arr[1][3];
	for (i = 2; i <= n; i++) {
		for (j = 1; j <= 3; j++) {
			for (int k = 1; k <= 3; k++) {
				if (j == k) continue;
				dp[i][k] = min(dp[i][k], dp[i - 1][j] + arr[i][k]);
			}
		}
	}
	int ans = 2e9;
	for (i = 1; i <= 3; i++) ans = min(ans, dp[n][i]);
	printf("%d", ans);
	return 0;
}