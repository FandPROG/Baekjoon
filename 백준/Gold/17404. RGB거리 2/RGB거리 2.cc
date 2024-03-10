#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int arr[1010][5];
int dp[1010][5][5];

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= 3; j++) {
			for (int k = 0; k <= 3; k++) {
				dp[i][j][k] = 2e9;
			}
		}
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= 3; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (i = 1; i <= 3; i++) dp[1][i][i] = arr[1][i];
	for (i = 1; i <= 3; i++) {
		for (j = 1; j < n; j++) {
			for (int k = 1; k <= 3; k++) {
				for (int l = 1; l <= 3; l++) {
					if (l == k) continue;
					dp[j + 1][l][i] = min(dp[j + 1][l][i], dp[j][k][i] + arr[j + 1][l]);
				}
			}
		}
	}
	/*for (i = 1; i <= 3; i++) {
		printf("\n\n<%d>\n", i);
		for (j = 1; j <= n; j++) {
			for (int k = 1; k <= 3; k++) {
				printf("%d ", dp[j][k][i]);
			}
			printf("\n");
		}
	}*/
	int ans = 2e9;
	for (i = 1; i <= 3; i++) {
		for (j = 1; j <= 3; j++) {
			if (i == j) continue;
			ans = min(ans, dp[n][i][j]);
		}
	}
	printf("%d", ans);
	return 0;
}