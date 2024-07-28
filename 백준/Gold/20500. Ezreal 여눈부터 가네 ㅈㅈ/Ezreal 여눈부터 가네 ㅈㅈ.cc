#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int dp[1520][1520];
int n;

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i <= n; i++) dp[i][i] = 1, dp[i][0] = 1;
	for (i = 2; i <= n; i++) {
		for (j = 1; j < i; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 1000000007;
		}
	}
	int ans = 0;
	for (i = 1; i <= n; i++) {
		int sum = (i * 5) + (n - i);
		if (sum % 3 == 0) {
			ans = (ans + dp[n - 1][i - 1]) % 1000000007;
		}
	}
	printf("%d", ans);
	return 0;
}