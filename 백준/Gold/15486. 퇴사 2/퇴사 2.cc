#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int dp[1500010];
int t[1500010], p[1500010];

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d %d", &t[i], &p[i]);
	for (i = 1; i <= n; i++) dp[i] = -2e9;
	for (i = 1; i <= n; i++) {
		dp[i] = max(dp[i - 1], dp[i]);
		dp[i + t[i] - 1] = max(dp[i + t[i] - 1], dp[i - 1] + p[i]);
	}
	printf("%d", dp[n]);
	return 0;
}