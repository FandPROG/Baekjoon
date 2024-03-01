#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

int arr[100010][5];
int dp[100010][5];

int main()
{
	int i, j;
	int t = 1;
	while (1) {
		int x;
		scanf("%d", &x);
		for (i = 0; i < x; i++) {
			for (j = 0; j < 3; j++) {
				dp[i][j] = 2e9;
			}
		}
		if (x == 0) break;
		for (i = 0; i < x; i++) {
			for (j = 0; j < 3; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		dp[0][1] = arr[0][1];
		dp[0][2] = arr[0][1] + arr[0][2];
		for (i = 1; i < x; i++) {
			for (j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					if (k > 0) dp[i][k] = min(dp[i][k], dp[i][k - 1] + arr[i][k]);
					if (abs(k - j) > 1) continue;
					dp[i][k] = min(dp[i][k], dp[i - 1][j] + arr[i][k]);
				}
			}
		}
		printf("%d. %d\n", t++, dp[x - 1][1]);
/*		for (i = 0; i < x; i++) {
			for (j = 0; j < 3; j++) {
				printf("%d ", dp[i][j]);
			}
			printf("\n");
		}*/
	}
	return 0;
}