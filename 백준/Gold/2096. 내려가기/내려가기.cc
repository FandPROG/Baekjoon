#include <stdio.h>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int arr[4];
int dp[2][4], dp_mn[2][4];

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= 3; j++) {
			dp[0][j] = dp[1][j], dp[1][j] = -2e9;
			dp_mn[0][j] = dp_mn[1][j], dp_mn[1][j] = 2e9;
		}
		for (j = 1; j <= 3; j++) {
			scanf("%d", &arr[j]);
		}
		for (j = 1; j <= 3; j++) {
			for (int k = 1; k <= 3; k++) {
				if (abs(j - k) > 1) continue;
				dp[1][k] = max(dp[1][k], dp[0][j] + arr[k]);
			}
		}
		for (j = 1; j <= 3; j++) {
			for (int k = 1; k <= 3; k++) {
				if (abs(j - k) > 1) continue;
				dp_mn[1][k] = min(dp_mn[1][k], dp_mn[0][j] + arr[k]);
			}
		}
	}
	int ans_mx = max(dp[1][1], max(dp[1][2], dp[1][3]));
	int ans_mn = min(dp_mn[1][1], min(dp_mn[1][2], dp_mn[1][3]));
	printf("%d %d", ans_mx, ans_mn);
	return 0;
}