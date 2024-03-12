#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[100010][5][5];

int main()
{
	int i, j;
	for (i = 0; i <= 100000; i++) {
		for (j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				dp[i][j][k] = 2e9;
			}
		}
	}
	dp[0][0][0] = 0;
	i = 0;
	while (1)
	{
		int x;
		i++;
		scanf("%d", &x);
		if (x == 0) break;
		for (j = 0; j <= 4; j++) {
			for (int k = 0; k <= 4; k++) {
				if (k == x) dp[i][j][x] = min(dp[i][j][x], dp[i - 1][j][k] + 1);
				if (j == x) dp[i][x][k] = min(dp[i][x][k], dp[i - 1][j][k] + 1);
				if (k == 0) dp[i][j][x] = min(dp[i][j][x], dp[i - 1][j][k] + 2);
				if (j == 0) dp[i][x][k] = min(dp[i][x][k], dp[i - 1][j][k] + 2);
				if (k == 1) {
					if (x == 2) dp[i][j][x] = min(dp[i][j][x], dp[i - 1][j][k] + 3);
					else if (x == 4) dp[i][j][x] = min(dp[i][j][x], dp[i - 1][j][k] + 3);
					else if (x == 3) dp[i][j][x] = min(dp[i][j][x], dp[i - 1][j][k] + 4);
				}
				if (j == 1) {
					if (x == 2) dp[i][x][k] = min(dp[i][x][k], dp[i - 1][j][k] + 3);
					else if (x == 4) dp[i][x][k] = min(dp[i][x][k], dp[i - 1][j][k] + 3);
					else if (x == 3) dp[i][x][k] = min(dp[i][x][k], dp[i - 1][j][k] + 4);
				}

				if (k == 2) {
					if (x == 1) dp[i][j][x] = min(dp[i][j][x], dp[i - 1][j][k] + 3);
					else if (x == 4) dp[i][j][x] = min(dp[i][j][x], dp[i - 1][j][k] + 4);
					else if (x == 3) dp[i][j][x] = min(dp[i][j][x], dp[i - 1][j][k] + 3);
				}
				if (j == 2) {
					if (x == 1) dp[i][x][k] = min(dp[i][x][k], dp[i - 1][j][k] + 3);
					else if (x == 4) dp[i][x][k] = min(dp[i][x][k], dp[i - 1][j][k] + 4);
					else if (x == 3) dp[i][x][k] = min(dp[i][x][k], dp[i - 1][j][k] + 3);
				}

				if (k == 3) {
					if (x == 2) dp[i][j][x] = min(dp[i][j][x], dp[i - 1][j][k] + 3);
					else if (x == 4) dp[i][j][x] = min(dp[i][j][x], dp[i - 1][j][k] + 3);
					else if (x == 1) dp[i][j][x] = min(dp[i][j][x], dp[i - 1][j][k] + 4);
				}
				if (j == 3) {
					if (x == 2) dp[i][x][k] = min(dp[i][x][k], dp[i - 1][j][k] + 3);
					else if (x == 4) dp[i][x][k] = min(dp[i][x][k], dp[i - 1][j][k] + 3);
					else if (x == 1) dp[i][x][k] = min(dp[i][x][k], dp[i - 1][j][k] + 4);
				}

				if (k == 4) {
					if (x == 2) dp[i][j][x] = min(dp[i][j][x], dp[i - 1][j][k] + 4);
					else if (x == 1) dp[i][j][x] = min(dp[i][j][x], dp[i - 1][j][k] + 3);
					else if (x == 3) dp[i][j][x] = min(dp[i][j][x], dp[i - 1][j][k] + 3);
				}
				if (j == 4) {
					if (x == 2) dp[i][x][k] = min(dp[i][x][k], dp[i - 1][j][k] + 4);
					else if (x == 1) dp[i][x][k] = min(dp[i][x][k], dp[i - 1][j][k] + 3);
					else if (x == 3) dp[i][x][k] = min(dp[i][x][k], dp[i - 1][j][k] + 3);
				}
			}
		}
	}
	int ans = 2e9;
	for (j = 0; j <= 4; j++) {
		for (int k = 0; k <= 4; k++) {
			ans = min(ans, dp[i - 1][j][k]);
		}
	}
	printf("%d", ans);
	return 0;
}