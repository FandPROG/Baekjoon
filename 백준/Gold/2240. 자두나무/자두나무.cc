#include <stdio.h>
#include <algorithm> 
#include <vector>

using namespace std;

int n, m;
int arr[1010];
int dp[1010][35][5];

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) scanf("%d", &arr[i]);

	if (arr[0] == 1) dp[0][0][1] = 1;
	else dp[0][1][2] = 1;

	for (i = 1; i < n; i++) {
		for (j = 0; j <= m; j++) {
			dp[i][j][1] = dp[i - 1][j][1];
			dp[i][j][2] = dp[i - 1][j][2];
			if (j > 0) {
				if (arr[i] == 1) dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - 1][2]);
				if (arr[i] == 2) dp[i][j][2] = max(dp[i][j][2], dp[i - 1][j - 1][1]);
			}
			dp[i][j][arr[i]]++;
		}
	}

	int ans = -2e9;
	for (i = 0; i <= m; i++) ans = max(ans, max(dp[n - 1][i][1], dp[n - 1][i][2]));
	printf("%d", ans);
	return 0;
}